/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:49:24 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/09/13 19:27:08 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

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

int			transition_time(t_scene *scene)
{
	clock_t		stop;
	double		ellapsed_time;

	if (scene->transition.enabled)
	{
		stop = clock();
		ellapsed_time = (double)(stop - scene->transition.time) / CLOCKS_PER_SEC;
		if (ellapsed_time > .01f)
		{
			scene->transition.time = 0;
			scene->transition.enabled = 0;
			glUniform1i(scene->transition.uni_enabled,
						scene->transition.enabled);
		}
		else
			glUniform1f(scene->transition.uni_time, ellapsed_time * 100);
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
		while (transition_time(scene) && SDL_PollEvent(&SDL_EVENT))
		{
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
		print_loop(scene);
	}
}
