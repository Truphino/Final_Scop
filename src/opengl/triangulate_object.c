/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangulate_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:32:10 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/23 12:14:28 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static int		calcutate_triangle(t_obj_data *od)
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

void			fetch_memory_od(t_obj_data *od)
{
	od->triangle_vertices = (float *)ft_memalloc(sizeof(float) *
			od->n_triangle * 9);
	od->final_normals = (float *)ft_memalloc(sizeof(float) *
			od->n_triangle * 9);
	od->final_textures = (float *)ft_memalloc(sizeof(float) *
			od->n_triangle * 6);
	if (od->final_normals == NULL ||
			od->final_textures == NULL ||
			od->triangle_vertices == NULL)
		exit(1);
}

void			triangulate_obj(t_obj_data *od)
{
	int		i;
	int		j;

	od->n_triangle = calcutate_triangle(od);
	fetch_memory_od(od);
	i = 0;
	j = 0;
	while (i < od->n_faces)
	{
		load_all(od, i, j, 0);
		if (od->face_indexes[i * 4 + 3] != -1)
		{
			j++;
			load_all(od, i, j, 1);
		}
		j++;
		i++;
	}
	if (od->n_normals <= 0)
		load_compute_normals(od);
	if (od->n_textures <= 0)
		generate_texture_vbo(od);
}
