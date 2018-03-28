/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/23 16:59:08 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			initialize_window(t_window *window)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("Coundn't init sdl\n");
	init_opengl();
	SDL_WIDTH = SDL_WIDTH ? SDL_WIDTH : DEFAULT_WINDOW_WIDTH;
	SDL_HEIGHT = SDL_HEIGHT ? SDL_HEIGHT : DEFAULT_WINDOW_HEIGHT;
	SDL_DEPTH = 32;
	SDL_WINDOW = SDL_CreateWindow("Scop", 100, 200,
	SDL_WIDTH, SDL_HEIGHT, SDL_WINDOW_OPENGL);
	window->aspect_ratio = (double)SDL_WIDTH / (double)SDL_HEIGHT;
	window->inverse_aspect_ratio = (double)SDL_HEIGHT / (double)SDL_WIDTH;
	if ((window->gl_context = SDL_GL_CreateContext(SDL_WINDOW)) == NULL)
		printf("Cannot init gl context\n");
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		ft_putendl("Error while loading glew");
		exit(1);
	}
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
}

void			kill_sdl(t_scene *scene, char *str, int fd)
{
	t_window	*window;

	window = &scene->window;
	SDL_GL_DeleteContext(window->gl_context);
	SDL_DestroyWindow(SDL_WINDOW);
	SDL_Quit();
	ft_putstr_fd(str, fd);
	exit(0);
}

void			put_image(t_scene *scene)
{
	t_window	*window;

	window = &scene->window;
	set_gl_color(window, new_vector(0, 0, 1), 1);
	render_obj(scene);
	poll_events(scene);
}
