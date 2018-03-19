/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:55:28 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/19 16:30:22 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void	print_vector(char *message, t_vector v)
{
	printf("%s:\n\t%f\t%f\t%f\t%f\n", message, v.x, v.y, v.z, v.w);
}

void	initialize_scene(t_scene *scene)
{
	default_camera(&scene->camera);
	scene->od = NULL;
	default_transformation(&scene->model_transformation);
	scene->model_transformation.translation = new_vector(0, 0, -10);
	scene->model_transformation.rotation.z += 0;
	build_transformation_matrix(scene->model_matrix,
								scene->model_transformation);
	identity_matrix(scene->projection);
}
