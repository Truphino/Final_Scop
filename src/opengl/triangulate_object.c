/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangulate_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:32:10 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/14 13:32:11 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static int			calcutate_triangle(t_obj_data *od)
{
	int		i;
	int		n_triangle;

	i = 0;
	n_triangle = 0;
	while (i < od->n_faces)
	{
		if (od->face_indexes[i * 4 + 3] != -1)
			n_triangle += 2;
		else
			n_triangle += 1;
		i++;
	}
	return (n_triangle);
}

static void		load_vertice_value(t_obj_data *od, int index, float *load)
{
	t_vector	vertices;

	vertices = od->vertices[index];
	load[0] = vertices.x;
	load[1] = vertices.y;
	load[2] = vertices.z;
}

static void		load_vertices_triangle(t_obj_data *od, int i, int j, int second)
{
	if (second == 0)
	{
		load_vertice_value(od, od->face_indexes[i * 4 + 0],
				od->triangle_vertices + (j * (3 + 0) * 3));
		load_vertice_value(od, od->face_indexes[i * 4 + 1],
				od->triangle_vertices + (j * (3 + 1) * 3));
		load_vertice_value(od, od->face_indexes[i * 4 + 2],
				od->triangle_vertices + (j * (3 + 2) * 3));
//		od->triangle_vertices[j * 3 + 0] = od->face_indexes[i * 4 + 0];
	}
	else
	{
		load_vertice_value(od, od->face_indexes[i * 4 + 0],
				od->triangle_vertices + (j * (3 + 0) * 3));
		load_vertice_value(od, od->face_indexes[i * 4 + 2],
				od->triangle_vertices + (j * (3 + 1) * 3));
		load_vertice_value(od, od->face_indexes[i * 4 + 3],
				od->triangle_vertices + (j * (3 + 2) * 3));
	}
}

void		triangulate_obj(t_obj_data *od)
{
	int		i;
	int		j;

	od->n_triangle = calcutate_triangle(od);
	od->triangle_vertices = (float *)ft_memalloc(sizeof(float) *
			od->n_triangle * 9);
	i = 0;
	j = 0;
	while (i < od->n_faces)
	{
		load_vertices_triangle(od, i, j, 0);
		if (od->face_indexes[i * 4 + 3] != -1)
		{
			j++;
			load_vertices_triangle(od, i, j, 1);
		}
		j++;
		i++;
	}
	i = -1;
}
