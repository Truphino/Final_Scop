/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:55:28 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/14 11:58:05 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void	initialize_scene(t_scene *scene)
{
	default_camera(&scene->camera);
	scene->od = NULL;
	scene->movement_speed = 1;
	scene->transition.enabled = 0;
	scene->transition.time = 0;
	scene->transition.speed = 100;
	default_transformation(&scene->model_transformation);
	scene->model_transformation.translation = new_vector(0, 0, -5);
	scene->model_transformation.rotation.z += 0;
	build_transformation_matrix(scene->model_matrix,
								scene->model_transformation);
	identity_matrix(scene->projection);
}
