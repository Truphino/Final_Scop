/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/15 15:14:30 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_vector		matrix_transform_raster_point(t_vector *pnt, t_matrix m)
{
	t_vector	inv;

	inv.x = pnt->x * m[0 * 4 + 0] +
			pnt->y * m[0 * 4 + 1] +
			pnt->z * m[0 * 4 + 2] +
			pnt->w * m[0 * 4 + 3];
	inv.y = pnt->x * m[1 * 4 + 0] +
			pnt->y * m[1 * 4 + 1] +
			pnt->z * m[1 * 4 + 2] +
			pnt->w * m[1 * 4 + 3];
	inv.z = pnt->x * m[2 * 4 + 0] +
			pnt->y * m[2 * 4 + 1] +
			pnt->z * m[2 * 4 + 2] +
			pnt->w * m[2 * 4 + 3];
	inv.w = pnt->x * m[3 * 4 + 0] +
			pnt->y * m[3 * 4 + 1] +
			pnt->z * m[3 * 4 + 2] +
			pnt->w * m[3 * 4 + 3];
	return (inv);
}

t_vector		matrix_transform_point(t_vector *pnt, t_matrix m)
{
	t_vector	inv;

	inv.x = pnt->x * m[0 * 4 + 0] +
			pnt->y * m[0 * 4 + 1] +
			pnt->z * m[0 * 4 + 2] +
					m[0 * 4 + 3];
	inv.y = pnt->x * m[1 * 4 + 0] +
			pnt->y * m[1 * 4 + 1] +
			pnt->z * m[1 * 4 + 2] +
					m[1 * 4 + 3];
	inv.z = pnt->x * m[2 * 4 + 0] +
			pnt->y * m[2 * 4 + 1] +
			pnt->z * m[2 * 4 + 2] +
					m[2 * 4 + 3];
	inv.w = 1;
	return (inv);
}

t_vector		matrix_transform_direction(t_vector *dir, t_matrix m)
{
	t_vector	inv;

	inv.x = dir->x * m[0 * 4 + 0] +
			dir->y * m[0 * 4 + 1] +
			dir->z * m[0 * 4 + 2];
	inv.y = dir->x * m[1 * 4 + 0] +
			dir->y * m[1 * 4 + 1] +
			dir->z * m[1 * 4 + 2];
	inv.z = dir->x * m[2 * 4 + 0] +
			dir->y * m[2 * 4 + 1] +
			dir->z * m[2 * 4 + 2];
	inv.w = 0;
	return (inv);
}
