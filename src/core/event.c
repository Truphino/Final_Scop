/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:49:24 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/09/14 11:51:42 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

int				transition_time(t_scene *scene)
{
	clock_t		stop;
	double		ellapsed_time;

	if (scene->transition.enabled)
	{
		stop = clock();
		ellapsed_time = (double)(stop - scene->transition.time)
								/ CLOCKS_PER_SEC;
		if (ellapsed_time > 1.f / (double)scene->transition.speed)
		{
			scene->transition.time = 0;
			scene->transition.enabled = 0;
			glUniform1i(scene->transition.uni_enabled,
						scene->transition.enabled);
		}
		else
			glUniform1f(scene->transition.uni_time,
							ellapsed_time * (double)scene->transition.speed);
	}
	return (1);
}

int				sdl_event_keydown(t_scene *scene, t_window *window)
{
	int			quit;

	quit = 0;
	if (SDL_EVENT.type == SDL_QUIT ||
			KEY == SDLK_ESCAPE)
	{
		quit = 1;
		kill_sdl(scene, "", 2);
	}
	handle_keys(scene, KEY);
	return (quit);
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
			quit = sdl_event_keydown(scene, window);
			if (SDL_EVENT.type == SDL_MOUSEMOTION)
				handle_mouse(scene, SDL_EVENT.motion);
		}
		transition_time(scene);
		print_loop(scene);
	}
}
