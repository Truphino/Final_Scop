/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:32:55 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/28 14:36:04 by trecomps         ###   ########.fr       */
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

void			explode_view(t_obj_data *od, t_scene *scene)
{
	int			i;
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
	t_vector	v1_v2;
	t_vector	v1_v3;
	t_vector	res;
	t_vector	res2;

	i = 0;
	while (i < od->n_triangle)
	{
	v1 = new_vector(od->triangle_vertices[i * 9 + 0],
			od->triangle_vertices[i * 9 + 1],
			od->triangle_vertices[i * 9 + 2]);
	v2 = new_vector(od->triangle_vertices[i * 9 + 3],
			od->triangle_vertices[i * 9 + 4],
			od->triangle_vertices[i * 9 + 5]);
	v3 = new_vector(od->triangle_vertices[i * 9 + 6],
			od->triangle_vertices[i * 9 + 7],
			od->triangle_vertices[i * 9 + 8]);
	v1_v2 = vector_subtract(v2, v1);
	v1_v3 = vector_subtract(v3, v1);
	res = vector_inverse_scale(vector_add(v1_v2, v1_v3), 3);
	res2 = vector_add(res, v1);
	res2 = vector_add(res2, scene->model_transformation.pr_translation);

	res2 = vector_scale(res2, 2);
	od->explodes_vectors[i * 9 + 0] += res2.x;
	od->explodes_vectors[i * 9 + 1] += res2.y;
	od->explodes_vectors[i * 9 + 2] += res2.z;
	od->explodes_vectors[i * 9 + 3] += res2.x;
	od->explodes_vectors[i * 9 + 4] += res2.y;
	od->explodes_vectors[i * 9 + 5] += res2.z;
	od->explodes_vectors[i * 9 + 6] += res2.x;
	od->explodes_vectors[i * 9 + 7] += res2.y;
	od->explodes_vectors[i * 9 + 8] += res2.z;
	i++;
	}
}

t_obj_data			*load_object(char *filename, t_scene *scene)
{
	t_obj_data	*obj;

	obj = (t_obj_data *)ft_memalloc(sizeof(t_obj_data));
	load_mesh(obj, filename);
	triangulate_obj(obj);
	move_symmetry_center(scene, obj);
	explode_view(obj, scene);
	obj->explode_coef = 0;
	return (obj);
}
