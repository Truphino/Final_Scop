/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/15 14:40:38 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

double		degrees_to_radians(double degrees)
{
	return (PI * degrees / 180);
}

double		euclidean_distance3d(t_vector a, t_vector b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)));
}

t_vector	linear_inter(t_vector a, t_vector b, double n)
{
	t_vector		ret;

	ret.x = a.x * (1 - n) + b.x * n;
	ret.y = a.y * (1 - n) + b.y * n;
	ret.z = a.z * (1 - n) + b.z * n;
	return (ret);
}
