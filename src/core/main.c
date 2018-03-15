/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/15 18:34:07 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void		usage(void)
{
	ft_putstr("usage : ./rt [example.rtsd]\n");
	exit(0);
}

void		init_view_matrices(t_scene *scene)
{
	double width;
	double height;
	double fov;

	fov = scene->camera.half_height;
	width = scene->window.width;
	height = scene->window.height;
	init_screen_space(scene->screen_space, width, height);
	new_perspective_matrix(scene->projection, fov, width / height);
}

int			main(int argc, char **argv)
{
	t_scene		scene;

	initialize_scene(&scene);
	initialize_window(&scene.window);
	initialize_camera(&scene.camera, &scene.window);
//	init_view_matrices(&scene);
	put_image(&scene);
	return (0);
}
