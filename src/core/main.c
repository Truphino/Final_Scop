/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/19 13:47:25 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static void	init_proj_matrix(t_scene *scene)
{
	new_perspective_matrix(scene->projection,
			scene->camera.tan_half_height,
			(double)scene->window.width / (double)scene->window.height);
}

int			main(int argc, char **argv)
{
	t_scene		scene;

	initialize_scene(&scene);
	initialize_window(&scene.window);
	init_proj_matrix(&scene);
	put_image(&scene);
	return (0);
}
