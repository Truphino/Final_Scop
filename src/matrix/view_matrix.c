/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:54:15 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/30 10:57:50 by trecomps         ###   ########.fr       */
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

void			compute_cs_angles(t_fps_camera *fps_cam)
{
	fps_cam->cs_angles.sin_pitch = sin(degrees_to_radians(fps_cam->pitch));
	fps_cam->cs_angles.cos_pitch = cos(degrees_to_radians(fps_cam->pitch));
	fps_cam->cs_angles.sin_yaw = sin(degrees_to_radians(fps_cam->yaw));
	fps_cam->cs_angles.cos_yaw = cos(degrees_to_radians(fps_cam->yaw));
}

void			compute_fps_view_matrix(t_fps_camera *fps_cam)
{
	t_vector	vx;
	t_vector	vy;
	t_vector	vz;
	t_cs_angles	*a;

	compute_cs_angles(fps_cam);
	a = &fps_cam->cs_angles;
	vx = new_vector(a->cos_yaw,
					0,
					-a->sin_yaw);
	vy = new_vector(a->sin_yaw * a->sin_pitch,
					a->cos_pitch,
					a->cos_yaw * a->sin_pitch);
	vz = new_vector(a->sin_yaw * a->cos_pitch,
					-a->sin_pitch,
					a->cos_yaw * a->cos_pitch);
	fill_matrix_line(vx, -dot_product(vx, fps_cam->eye),
			fps_cam->view_matrix + (4 * 0));
	fill_matrix_line(vy, -dot_product(vy, fps_cam->eye),
			fps_cam->view_matrix + (4 * 1));
	fill_matrix_line(vz, -dot_product(vz, fps_cam->eye),
			fps_cam->view_matrix + (4 * 2));
	fill_matrix_line(new_vector(0, 0, 0), 1,
			fps_cam->view_matrix + (4 * 3));
}
