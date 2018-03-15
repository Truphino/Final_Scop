/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 22:25:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/12 10:55:10 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GEOMETRY_H
# define __GEOMETRY_H

# include "vector.h"

double			euclidean_distance3d(t_vector a, t_vector b);
double			degrees_to_radians(double degrees);
t_vector		linear_inter(t_vector a, t_vector b, double n);

#endif
