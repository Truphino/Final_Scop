/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:32:55 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/13 16:34:42 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static void		move_symmetry_center(t_scene *scene, t_obj_data *od)
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

static void		fill_explode_vector(t_obj_data *od, int i, t_vector res2)
{
	od->explodes_vectors[i * 9 + 0] += res2.x;
	od->explodes_vectors[i * 9 + 1] += res2.y;
	od->explodes_vectors[i * 9 + 2] += res2.z;
	od->explodes_vectors[i * 9 + 3] += res2.x;
	od->explodes_vectors[i * 9 + 4] += res2.y;
	od->explodes_vectors[i * 9 + 5] += res2.z;
	od->explodes_vectors[i * 9 + 6] += res2.x;
	od->explodes_vectors[i * 9 + 7] += res2.y;
	od->explodes_vectors[i * 9 + 8] += res2.z;
}

t_vector		extract_vector(t_obj_data *od, int i, int offset)
{
	t_vector	tmp;

	offset *= 3;
	tmp = new_vector(od->triangle_vertices[i * 9 + 0 + offset],
			od->triangle_vertices[i * 9 + 1 + offset],
			od->triangle_vertices[i * 9 + 2 + offset]);
	return (tmp);
}

void			explode_view(t_obj_data *od, t_scene *scene)
{
	int			i;
	t_vector	v[3];
	t_vector	v0_v1;
	t_vector	v0_v2;
	t_vector	res;

	i = 0;
	while (i < od->n_triangle)
	{
		v[0] = extract_vector(od, i, 0);
		v[1] = extract_vector(od, i, 1);
		v[2] = extract_vector(od, i, 2);
		v0_v1 = vector_subtract(v[1], v[0]);
		v0_v2 = vector_subtract(v[2], v[0]);
		res = vector_inverse_scale(vector_add(v0_v1, v0_v2), 3);
		res = vector_add(res, v[0]);
		res = vector_add(res, scene->model_transformation.pr_translation);
		res = vector_scale(res, 2);
		fill_explode_vector(od, i, res);
		i++;
	}
}

t_obj_data		*load_object(char *filename, t_scene *scene)
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
