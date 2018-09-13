/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:49:24 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/09/13 16:21:37 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

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
			if (SDL_EVENT.type == SDL_MOUSEMOTION)
				handle_mouse(scene, SDL_EVENT.motion);
		}
	}
}
