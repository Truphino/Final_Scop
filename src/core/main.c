/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/06 15:01:34 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static void	init_proj_matrix(t_scene *scene)
{
	new_perspective_matrix(scene->projection,
			scene->camera.tan_half_height,
			(double)scene->window.width / (double)scene->window.height);
}

void		handle_arguments(int argc, char **argv, t_scene *scene)
{
	if (argc == 1)
	{
		scene->obj_file_name = ft_strdup("./object_files/42_texture.obj");
		scene->text_file_name =
			ft_strdup("./texture/preacher_of_the_night.bmp");
		scene->textures_enabled = 1;
	}
	else if (argc == 2)
	{
		scene->obj_file_name = argv[1];
		scene->text_file_name = NULL;
		scene->textures_enabled = 0;
	}
	else if (argc == 3)
	{
		scene->obj_file_name = argv[1];
		scene->text_file_name = argv[2];
		scene->textures_enabled = 1;
	}
	else
		exit(1);
}

int			main(int argc, char **argv)
{
	t_scene		scene;

	initialize_scene(&scene);
	handle_arguments(argc, argv, &scene);
	initialize_window(&scene.window);
	init_proj_matrix(&scene);
	put_image(&scene);
	return (0);
}
