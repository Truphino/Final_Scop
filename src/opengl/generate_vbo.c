/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_vbo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:33:14 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/14 13:40:30 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

float		*generate_vbo(t_obj_data *od)
{
	float	*vbo;
	int		i;

	if ((vbo = (float *)ft_memalloc(sizeof(float) *
					od->n_triangle * 9)) == NULL)
		exit(1);
	while (i < od->n_triangle)
	{
		vbo[i * 3 + 0] = 1.f * ((i % 4) / 4);
		vbo[i * 3 + 1] = 1.f * ((i % 4) / 4);
		vbo[i * 3 + 2] = 1.f * ((i % 4) / 4);
		i++;
	}

	return (vbo);
}
