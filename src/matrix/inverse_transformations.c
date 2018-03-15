/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_transformations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/15 12:09:38 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void	build_inverse_translation_matrix(t_matrix m,
double x, double y, double z)
{
	m[0 * 4 + 0] = 1;
	m[0 * 4 + 1] = 0;
	m[0 * 4 + 2] = 0;
	m[0 * 4 + 3] = -x;
	m[1 * 4 + 0] = 0;
	m[1 * 4 + 1] = 1;
	m[1 * 4 + 2] = 0;
	m[1 * 4 + 3] = -y;
	m[2 * 4 + 0] = 0;
	m[2 * 4 + 1] = 0;
	m[2 * 4 + 2] = 1;
	m[2 * 4 + 3] = -z;
	m[3 * 4 + 0] = 0;
	m[3 * 4 + 1] = 0;
	m[3 * 4 + 2] = 0;
	m[3 * 4 + 3] = 1;
}

void	build_inverse_scale_matrix(t_matrix m, double x, double y, double z)
{
	m[0 * 4 + 0] = 1.0 / x;
	m[0 * 4 + 1] = 0;
	m[0 * 4 + 2] = 0;
	m[0 * 4 + 3] = 0;
	m[1 * 4 + 0] = 0;
	m[1 * 4 + 1] = 1.0 / y;
	m[1 * 4 + 2] = 0;
	m[1 * 4 + 3] = 0;
	m[2 * 4 + 0] = 0;
	m[2 * 4 + 1] = 0;
	m[2 * 4 + 2] = 1.0 / z;
	m[2 * 4 + 3] = 0;
	m[3 * 4 + 0] = 0;
	m[3 * 4 + 1] = 0;
	m[3 * 4 + 2] = 0;
	m[3 * 4 + 3] = 1;
}

void	build_inverse_transformation_matrix(t_matrix inverse_transform,
t_transform t)
{
	t_matrix	inverse_scale;
	t_matrix	inverse_rotation;
	t_matrix	inverse_translation;
	t_matrix	res;

	build_inverse_scale_matrix(inverse_scale,
	t.scale.x, t.scale.y, t.scale.z);
	build_inverse_rotation_matrix(inverse_rotation,
	t.rotation.x, t.rotation.y, t.rotation.z);
	build_inverse_translation_matrix(inverse_translation,
	t.translation.x, t.translation.y, t.translation.z);
	matrix_multiply(res, inverse_rotation, inverse_translation);
	matrix_multiply(inverse_transform, inverse_scale, res);
}
