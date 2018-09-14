/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interaction_event.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:18:34 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/14 11:40:08 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			change_movement_speed(t_scene *scene, int key)
{
	if (key == SDLK_KP_MULTIPLY)
		scene->movement_speed = 1;
	else if (key == SDLK_KP_PLUS)
		scene->movement_speed *= 1.1;
	else if (key == SDLK_KP_MINUS)
		scene->movement_speed /= 1.1;
}

void			change_transition_speed(t_scene *scene, int key)
{
	if (key == SDLK_x)
		scene->transition.speed += 100;
	else if (key == SDLK_c)
	{
		if (scene->transition.speed > 100)
			scene->transition.speed -= 100;
	}
}

void			switch_texture_colours(t_scene *scene, int key)
{
	if (scene->transition.enabled == 0)
	{
		if (key == SDLK_t)
		{
			scene->texture_enabled = !scene->texture_enabled;
			scene->transition.enabled = 1;
			scene->transition.time = clock();
		}
		glUniform1i(scene->uni_tex_enabled, scene->texture_enabled);
		glUniform1i(scene->transition.uni_enabled, scene->transition.enabled);
		glUniform1d(scene->transition.uni_time, 0);
	}
}

void			handle_keys(t_scene *scene, int key)
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
	else if (key == SDLK_KP_PLUS ||
			key == SDLK_KP_MINUS || key == SDLK_KP_MULTIPLY)
		change_movement_speed(scene, key);
	else if (key == SDLK_t)
		switch_texture_colours(scene, key);
	else if (key == SDLK_x || key == SDLK_c)
		change_transition_speed(scene, key);
}

void			handle_mouse(t_scene *scene, SDL_MouseMotionEvent e)
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
