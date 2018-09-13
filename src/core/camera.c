/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/11 18:07:38 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			init_fps_camera(t_fps_camera *fps_cam)
{
	fps_cam->pitch = 0;
	fps_cam->yaw = 0;
	fps_cam->lock_camera = 1;
	fps_cam->eye = new_vector(0, 0, 10);
	compute_fps_view_matrix(fps_cam);
}

void			default_camera(t_camera *camera)
{
	camera->fov = FOV;
	camera->tan_half_height = tan(degrees_to_radians(camera->fov / 2));
	camera->eye = new_vector(0, 0, 10);
	camera->look_at = new_vector(0, 0, 0);
	camera->light.position[0] = 5;
	camera->light.position[1] = 1;
	camera->light.position[2] = 0;
	camera->light.colors[0] = 1;
	camera->light.colors[1] = 1;
	camera->light.colors[2] = 1;
	init_fps_camera(&camera->fps_cam);
	//compute_look_at_view_matrix(camera);
}
