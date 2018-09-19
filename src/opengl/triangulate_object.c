/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangulate_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:32:10 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/19 11:45:37 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			fetch_memory_od(t_obj_data *od)
{
	od->explodes_vectors = (float *)ft_memalloc(sizeof(float) *
			od->n_triangles * 9);
	od->triangle_vertices = (float *)ft_memalloc(sizeof(float) *
			od->n_triangles * 9);
	od->final_normals = (float *)ft_memalloc(sizeof(float) *
			od->n_triangles * 9);
	od->final_textures = (float *)ft_memalloc(sizeof(float) *
			od->n_triangles * 6);
	if (od->final_normals == NULL ||
			od->final_textures == NULL ||
			od->explodes_vectors == NULL ||
			od->triangle_vertices == NULL)
		exit(1);
}

void			triangulate_obj(t_obj_data *od)
{
	int		i;

	fetch_memory_od(od);
	i = 0;
	while (i < od->n_triangles)
	{
		load_all(od, i);
		i++;
	}
	if (od->n_normals <= 0)
		load_compute_normals(od);
	if (od->n_textures <= 0)
		generate_texture_vbo(od);
}
