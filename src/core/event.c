/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:49:24 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/20 15:11:21 by trecomps         ###   ########.fr       */
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
	build_transformation_matrix(scene->model_matrix,
								scene->model_transformation);
	transpose_matrix(scene->tr_model_matrix, scene->model_matrix);
	glUniformMatrix4fv(scene->uni_model_matrix, 1, GL_FALSE,
						scene->tr_model_matrix);
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
	build_transformation_matrix(scene->model_matrix,
								scene->model_transformation);
	transpose_matrix(scene->tr_model_matrix, scene->model_matrix);
	glUniformMatrix4fv(scene->uni_model_matrix, 1, GL_FALSE,
						scene->tr_model_matrix);
}

static void		handle_keys(t_scene *scene, int key)
{
	if (key == SDLK_RIGHT || key == SDLK_LEFT ||
			key == SDLK_UP || key == SDLK_DOWN ||
			key == SDLK_q || key == SDLK_e)
		rotate_model(scene, key);
	if (key == SDLK_d || key == SDLK_a ||
			key == SDLK_w || key == SDLK_s ||
			key == SDLK_g || key == SDLK_f)
		translate_model(scene, key);
}

static void		print_loop(t_scene *scene)
{
	t_window	*window;

	window = &scene->window;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, scene->od->n_triangle * 3);
	SDL_GL_SwapWindow(SDL_WINDOW);
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
		while (SDL_PollEvent(&SDL_EVENT))
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
		}
	}
}
