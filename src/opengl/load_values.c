/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:20:13 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/23 12:25:54 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static void		load_vertice_value(t_obj_data *od, int index, float *load)
{
	t_vector	vertices;

	vertices = od->vertices[index];
	load[0] = vertices.x;
	load[1] = vertices.y;
	load[2] = vertices.z;
}

void			load_normal_value(t_obj_data *od, int index, float *load)
{
	t_vector	normal;

	normal = od->normals[index];
	load[0] = normal.x;
	load[1] = normal.y;
	load[2] = normal.z;
}

void			load_texture_value(t_obj_data *od, int index, float *load)
{
	t_vector	texture;

	texture = od->textures[index];
	load[0] = texture.x;
	load[1] = texture.y;
}

void			load_all_value(t_obj_data *od, int i, int j, int j_offset)
{
	load_vertice_value(od, od->face_indexes[i],
			od->triangle_vertices + ((j * 3 + j_offset) * 3));
	if (od->n_normals > 0)
		load_normal_value(od, od->normal_indexes[i],
			od->final_normals + ((j * 3 + j_offset) * 3));
	if (od->n_textures > 0)
		load_texture_value(od, od->texture_indexes[i],
			od->final_textures + ((j * 3 + j_offset) * 2));
}

void			load_all(t_obj_data *od, int i, int j, int second)
{
	if (!second)
	{
		load_all_value(od, i * 4 + 0, j, 0);
		load_all_value(od, i * 4 + 1, j, 1);
		load_all_value(od, i * 4 + 2, j, 2);
	}
	else
	{
		load_all_value(od, i * 4 + 0, j, 0);
		load_all_value(od, i * 4 + 2, j, 1);
		load_all_value(od, i * 4 + 3, j, 2);
	}
}
