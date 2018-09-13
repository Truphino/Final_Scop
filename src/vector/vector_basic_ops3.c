/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_basic_ops3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:04:33 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/09/13 15:52:37 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vector	vector_inverse(t_vector a)
{
	t_vector	inv;

	inv.x = 1 / a.x;
	inv.y = 1 / a.y;
	inv.z = 1 / a.z;
	return (inv);
}

t_vector	vector_const_divide(t_vector a, double b)
{
	t_vector	res;

	res.x = a.x / b;
	res.y = a.y / b;
	res.z = a.z / b;
	return (res);
}

t_vector	vec_abs(t_vector a)
{
	t_vector	tmp;

	tmp.x = fabs(a.x);
	tmp.y = fabs(a.y);
	tmp.z = fabs(a.z);
	return (tmp);
}
