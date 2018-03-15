/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/15 12:11:02 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void		build_scale_matrix(t_matrix m, double x, double y, double z)
{
	m[0 * 4 + 0] = x;
	m[0 * 4 + 1] = 0;
	m[0 * 4 + 2] = 0;
	m[0 * 4 + 3] = 0;
	m[1 * 4 + 0] = 0;
	m[1 * 4 + 1] = y;
	m[1 * 4 + 2] = 0;
	m[1 * 4 + 3] = 0;
	m[2 * 4 + 0] = 0;
	m[2 * 4 + 1] = 0;
	m[2 * 4 + 2] = z;
	m[2 * 4 + 3] = 0;
	m[3 * 4 + 0] = 0;
	m[3 * 4 + 1] = 0;
	m[3 * 4 + 2] = 0;
	m[3 * 4 + 3] = 1;
}

void		build_translation_matrix(t_matrix m, double x, double y, double z)
{
	m[0 * 4 + 0] = 1;
	m[0 * 4 + 1] = 0;
	m[0 * 4 + 2] = 0;
	m[0 * 4 + 3] = x;
	m[1 * 4 + 0] = 0;
	m[1 * 4 + 1] = 1;
	m[1 * 4 + 2] = 0;
	m[1 * 4 + 3] = y;
	m[2 * 4 + 0] = 0;
	m[2 * 4 + 1] = 0;
	m[2 * 4 + 2] = 1;
	m[2 * 4 + 3] = z;
	m[3 * 4 + 0] = 0;
	m[3 * 4 + 1] = 0;
	m[3 * 4 + 2] = 0;
	m[3 * 4 + 3] = 1;
}

void		compose_matrices(t_matrix transform, t_matrix scale,
t_matrix rotation, t_matrix translation)
{
	t_matrix	res;

	matrix_multiply(res, rotation, scale);
	matrix_multiply(transform, translation, res);
}

void		build_transformation_matrix(t_matrix transform, t_transform t)
{
	t_matrix	scale;
	t_matrix	rotation;
	t_matrix	translation;

	build_scale_matrix(scale, t.scale.x, t.scale.y, t.scale.z);
	build_rotation_matrix(rotation, t.rotation.x, t.rotation.y, t.rotation.z);
	build_translation_matrix(translation, t.translation.x,
	t.translation.y, t.translation.z);
	compose_matrices(transform, scale, rotation, translation);
}
