/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:32:55 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/23 10:47:22 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static void			move_symmetry_center(t_scene *scene, t_obj_data *od)
{
	int			i;
	t_vector	min;
	t_vector	max;

	min = od->vertices[0];
	max = od->vertices[0];
	i = 0;
	while (i < od->n_vertices)
	{
		if (od->vertices[i].x < min.x)
			min.x = od->vertices[i].x;
		if (od->vertices[i].y < min.y)
			min.y = od->vertices[i].y;
		if (od->vertices[i].z < min.z)
			min.z = od->vertices[i].z;
		if (od->vertices[i].x > max.x)
			max.x = od->vertices[i].x;
		if (od->vertices[i].y > max.y)
			max.y = od->vertices[i].y;
		if (od->vertices[i].z > max.z)
			max.z = od->vertices[i].z;
		i++;
	}
	scene->model_transformation.pr_translation = vector_scale(vector_subtract(
				max, vector_const_divide(vector_subtract(max, min), 2)), -1);
}

t_obj_data			*load_object(char *filename, t_scene *scene)
{
	t_obj_data	*obj;

	obj = (t_obj_data *)ft_memalloc(sizeof(t_obj_data));
	load_mesh(obj, filename);
	triangulate_obj(obj);
	move_symmetry_center(scene, obj);
	return (obj);
}
