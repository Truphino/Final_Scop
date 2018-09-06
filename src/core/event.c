/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:49:24 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/09/06 14:32:59 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static void		rotate_model(t_scene *scene, int key)
{
	if (key == SDLK_RIGHT)
		scene->model_transformation.rotation.y += 10;
	else if (key == SDLK_LEFT)
		scene->model_transformation.rotation.y -= 10;
	else if (key == SDLK_DOWN)
		scene->model_transformation.rotation.x += 10;
	else if (key == SDLK_UP)
		scene->model_transformation.rotation.x -= 10;
	else if (key == SDLK_q)
		scene->model_transformation.rotation.z += 10;
	else if (key == SDLK_e)
		scene->model_transformation.rotation.z -= 10;
	send_model_mt_opengl(scene);
}

static void		translate_model(t_scene *scene, int key)
{
	if (key == SDLK_w)
		scene->model_transformation.translation.y += 1;
	else if (key == SDLK_s)
		scene->model_transformation.translation.y -= 1;
	else if (key == SDLK_a)
		scene->model_transformation.translation.x -= 1;
	else if (key == SDLK_d)
		scene->model_transformation.translation.x += 1;
	else if (key == SDLK_f)
		scene->model_transformation.translation.z -= 1;
	else if (key == SDLK_g)
		scene->model_transformation.translation.z += 1;
	send_model_mt_opengl(scene);
}

void			reset_model(t_scene *scene)
{
	scene->model_transformation.translation = new_vector(0, 0, 0);
	scene->model_transformation.rotation = new_vector(0, 0, 0);
	send_model_mt_opengl(scene);
}

void			explode_model(t_scene *scene, int key)
{
	if (key == SDLK_j)
	{
		if (scene->od->explode_coef >= 0.1f)
			scene->od->explode_coef -= 0.1f;
		else
			scene->od->explode_coef = 0;
	}
	else if (key == SDLK_k)
		scene->od->explode_coef += 0.1f;
	glUniform1f(scene->od->uni_explode_coef, scene->od->explode_coef);
}

void			scale_model(t_scene *scene, int key)
{
	if (key == SDLK_y)
	{
		scene->model_transformation.scale.x *= 1.2;
		scene->model_transformation.scale.y *= 1.2;
		scene->model_transformation.scale.z *= 1.2;
	}
	else if (key == SDLK_u)
	{
		scene->model_transformation.scale.x /= 1.2;
		scene->model_transformation.scale.y /= 1.2;
		scene->model_transformation.scale.z /= 1.2;
	}
	send_model_mt_opengl(scene);
}

static void		handle_keys(t_scene *scene, int key)
{
	if (key == SDLK_RIGHT || key == SDLK_LEFT ||
			key == SDLK_UP || key == SDLK_DOWN ||
			key == SDLK_q || key == SDLK_e)
		rotate_model(scene, key);
	else if (key == SDLK_d || key == SDLK_a ||
			key == SDLK_w || key == SDLK_s ||
			key == SDLK_g || key == SDLK_f)
		translate_model(scene, key);
	else if (key == SDLK_y || key == SDLK_u)
		scale_model(scene, key);
	else if (key == SDLK_o)
		reset_model(scene);
	else if (key == SDLK_j || key == SDLK_k)
		explode_model(scene, key);
	else if (key == SDLK_p)
		scene->camera.fps_cam.lock_camera = !scene->camera.fps_cam.lock_camera;
}

static void		handle_mouse(t_scene *scene, SDL_MouseMotionEvent e)
{
	if (!scene->camera.fps_cam.lock_camera)
	{
		scene->camera.fps_cam.pitch -= (float)e.yrel / 10;
		scene->camera.fps_cam.yaw -= (float)e.xrel / 10;
		if (scene->camera.fps_cam.pitch > 90)
			scene->camera.fps_cam.pitch = 90;
		if (scene->camera.fps_cam.pitch < -90)
			scene->camera.fps_cam.pitch = -90;
		if (scene->camera.fps_cam.yaw > 90)
			scene->camera.fps_cam.yaw = 90;
		if (scene->camera.fps_cam.yaw < -90)
			scene->camera.fps_cam.yaw = -90;
		compute_fps_view_matrix(&scene->camera.fps_cam);
		glUniformMatrix4fv(scene->camera.fps_cam.uni_view_matrix, 1, GL_TRUE,
				scene->camera.fps_cam.view_matrix);
	}
}

int			fps_counter(void)
{
	static double		last_time = 0;
	static int			nb_frames = 0;

	if (last_time == 0)
		last_time = time(NULL);
	nb_frames++;
	if (time(NULL) - last_time > 1)
	{
		printf("%f ms/frames\n", 1000.f/(double)nb_frames);
		nb_frames = 0;
		last_time += 1.f;
	}
	return (1);
}

void			poll_events(t_scene *scene)
{
	int			quit;
	t_window	*window;
	t_matrix	tmp;

	window = &scene->window;
	quit = 0;
	while (!quit)
	{
		while (fps_counter() && SDL_PollEvent(&SDL_EVENT))
		{
			print_loop(scene);
			if (SDL_EVENT.type == SDL_KEYDOWN)
			{
				if (SDL_EVENT.type == SDL_QUIT ||
					KEY == SDLK_ESCAPE)
				{
					quit = 1;
					kill_sdl(scene, "", 2);
				}
				handle_keys(scene, KEY);
			}
			if (SDL_EVENT.type == SDL_MOUSEMOTION)
				handle_mouse(scene, SDL_EVENT.motion);
		}
	}
}
