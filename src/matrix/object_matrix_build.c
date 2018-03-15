/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_matrix_build.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 20:22:56 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/15 15:06:18 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void		build_normal_to_world(t_matrix norm_to_world, t_transform t)
{
	t_matrix	inverse_scale;
	t_matrix	rotation;

	build_inverse_scale_matrix(inverse_scale, t.scale.x, t.scale.y, t.scale.z);
	build_rotation_matrix(rotation, t.rotation.x, t.rotation.y, t.rotation.z);
	matrix_multiply(norm_to_world, rotation, inverse_scale);
}
