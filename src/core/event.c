/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:49:24 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/19 16:41:33 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static void		rotate_model(t_scene *scene, int key)
{
	int			rotation_y;
	int			rotation_x;

	rotation_y = 0;
	rotation_x = 0;
	if (key == SDLK_LEFT)
		rotation_y = 10;
	else if (key == SDLK_RIGHT)
		rotation_y = -10;
	else if (key == SDLK_UP)
		rotation_x = 10;
	else if (key == SDLK_DOWN)
		rotation_x = -10;

	scene->model_transformation.rotation.y += rotation_y;
	scene->model_transformation.rotation.x += rotation_x;
	build_transformation_matrix(scene->model_matrix,
								scene->model_transformation);
	transpose_matrix(scene->model_matrix);
	glUniformMatrix4fv(scene->uni_model_matrix, 1, GL_FALSE,
						scene->model_matrix);
	transpose_matrix(scene->model_matrix);
}

static void		translate_model(t_scene *scene, int key)
{
	int			translation_x;
	int			translation_y;

	translation_x = 0;
	translation_y = 0;
	if (key == SDLK_w)
		translation_y += 1;
	else if (key == SDLK_s)
		translation_y -= 1;
	else if (key == SDLK_a)
		translation_x -= 1;
	else if (key == SDLK_d)
		translation_x += 1;
	scene->model_transformation.translation.y += translation_y;
	scene->model_transformation.translation.x += translation_x;
	build_transformation_matrix(scene->model_matrix,
								scene->model_transformation);
	transpose_matrix(scene->model_matrix);
	glUniformMatrix4fv(scene->uni_model_matrix, 1, GL_FALSE,
						scene->model_matrix);
	transpose_matrix(scene->model_matrix);
}

static void		print_all_matrix(t_scene *scene)
{
	print_matrix(scene->model_matrix);
	ft_putchar('\n');
	print_matrix(scene->camera.view_matrix);
	ft_putchar('\n');
	print_matrix(scene->projection);
	ft_putchar('\n');
	ft_putchar('\n');
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
			glClear(GL_COLOR_BUFFER_BIT);
			glDrawArrays(GL_TRIANGLES, 0, 2 * 3);
			SDL_GL_SwapWindow(SDL_WINDOW);
			if (SDL_EVENT.type == SDL_KEYDOWN)
			{
				if (SDL_EVENT.type == SDL_QUIT ||
					KEY == SDLK_ESCAPE)
				{
					quit = 1;
					kill_sdl(scene, "", 2);
				}
				if (KEY == SDLK_RIGHT || KEY == SDLK_LEFT || KEY == SDLK_UP || KEY == SDLK_DOWN)
					rotate_model(scene, KEY);
				if (KEY == SDLK_d || KEY == SDLK_a || KEY == SDLK_w || KEY == SDLK_s)
					translate_model(scene, KEY);
			}
		}
	}
}
