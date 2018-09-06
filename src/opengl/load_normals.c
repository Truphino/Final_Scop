/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_normals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:58:22 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/06 14:17:06 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void		compute_normals(t_obj_data *od, int i)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	normal;

	v1 = new_vector(
		od->triangle_vertices[i * 9 + 3] - od->triangle_vertices[i * 9 + 0],
		od->triangle_vertices[i * 9 + 4] - od->triangle_vertices[i * 9 + 1],
		od->triangle_vertices[i * 9 + 5] - od->triangle_vertices[i * 9 + 2]);
	v2 = new_vector(
		od->triangle_vertices[i * 9 + 6] - od->triangle_vertices[i * 9 + 0],
		od->triangle_vertices[i * 9 + 7] - od->triangle_vertices[i * 9 + 1],
		od->triangle_vertices[i * 9 + 8] - od->triangle_vertices[i * 9 + 2]);
	normal = vector_cross(v1, v2);
	normal.w = 0;
	od->final_normals[i * 9 + 0] = normal.x;
	od->final_normals[i * 9 + 1] = normal.y;
	od->final_normals[i * 9 + 2] = normal.z;
	od->final_normals[i * 9 + 3] = normal.x;
	od->final_normals[i * 9 + 4] = normal.y;
	od->final_normals[i * 9 + 5] = normal.z;
	od->final_normals[i * 9 + 6] = normal.x;
	od->final_normals[i * 9 + 7] = normal.y;
	od->final_normals[i * 9 + 8] = normal.z;
}

void		load_compute_normals(t_obj_data *od)
{
	int			i;
	t_vector	v1;
	t_vector	v2;

	i = 0;
	free_if((void **)&od->normals);
	while (i < od->n_triangle)
	{
		compute_normals(od, i);
		i++;
	}
}
