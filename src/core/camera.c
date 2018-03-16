/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/16 15:15:50 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static void		fill_matrix_line(t_vector v, float w, t_matrix matrix)
{
	matrix[0] = v.x;
	matrix[1] = v.y;
	matrix[2] = v.z;
	matrix[3] = w;
}

void			compute_look_at_view_matrix(t_camera *camera)
{
	t_vector	vx;
	t_vector	vy;
	t_vector	vz;

	vz = unit_vector(vector_subtract(camera->eye, camera->look_at));
	vx = vector_cross(UP_VECTOR, vz);
	vy = vector_cross(vz, vx);
	fill_matrix_line(vx, -dot_product(vx, camera->eye),
			camera->view_matrix + (4 * 0));
	fill_matrix_line(vy, -dot_product(vy, camera->eye),
			camera->view_matrix + (4 * 1));
	fill_matrix_line(vz, -dot_product(vz, camera->eye),
			camera->view_matrix + (4 * 2));
	fill_matrix_line(new_vector(0, 0, 0), 1, 
			camera->view_matrix + (4 * 3));
}

void		default_camera(t_camera *camera)
{
	camera->fov = FOV;
	camera->tan_half_height = tan(degrees_to_radians(camera->fov / 2));
	camera->eye = new_vector(0, 0, 0);
	camera->look_at = new_vector(0, 0, -1);
	compute_look_at_view_matrix(camera);
}
