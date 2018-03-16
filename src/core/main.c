/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/16 15:27:04 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void		usage(void)
{
	ft_putstr("usage : ./rt [example.rtsd]\n");
	exit(0);
}

static void	init_view_matrice(t_scene *scene)
{
	new_perspective_matrix(scene->projection,
			scene->camera.tan_half_height,
			scene->window.height / scene->window.width);
}

int			main(int argc, char **argv)
{
	t_scene		scene;

	initialize_scene(&scene);
	initialize_window(&scene.window);
	//init_view_matrice(&scene);
	put_image(&scene);
	return (0);
}
