/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/19 16:25:46 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>

void	new_perspective_matrix(t_matrix m,
							double fov,
							double aspect_ratio)
{
	double		z_near;
	double		z_far;
	double		z_range;

	z_near = 1.0;
	z_far = 100.0;
	z_range =  z_near - z_far;
	m[0 * 4 + 0] = 1.0f / (fov * aspect_ratio);
	m[0 * 4 + 1] = 0;
	m[0 * 4 + 2] = 0;
	m[0 * 4 + 3] = 0;
	m[1 * 4 + 0] = 0;
	m[1 * 4 + 1] = 1.0f / fov;
	m[1 * 4 + 2] = 0;
	m[1 * 4 + 3] = 0;
	m[2 * 4 + 0] = 0;
	m[2 * 4 + 1] = 0;
	m[2 * 4 + 2] = (z_near + z_far) / z_range;
	m[2 * 4 + 3] = 2 * z_far * z_near / z_range;
	m[3 * 4 + 0] = 0;
	m[3 * 4 + 1] = 0;
	m[3 * 4 + 2] = -1;
	m[3 * 4 + 3] = 0;
}
