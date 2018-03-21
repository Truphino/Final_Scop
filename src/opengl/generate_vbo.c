/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_vbo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:33:14 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/21 14:42:30 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

float		*generate_vbo(t_obj_data *od)
{
	float	*vbo;
	int		i;
	float	colour;

	if ((vbo = (float *)ft_memalloc(sizeof(float) *
					od->n_triangle * 9)) == NULL)
		exit(1);
	i = 0;
	while (i < od->n_triangle)
	{
		colour = ((double)((i * 9) % 10) / 10.f);
		vbo[i * 9 + 0] = colour;
		vbo[i * 9 + 1] = colour;
		vbo[i * 9 + 2] = colour;
		vbo[i * 9 + 3] = colour;
		vbo[i * 9 + 4] = colour;
		vbo[i * 9 + 5] = colour;
		vbo[i * 9 + 6] = colour;
		vbo[i * 9 + 7] = colour;
		vbo[i * 9 + 8] = colour;
		i++;
	}
	return (vbo);
}

float		*generate_texture_vbo(t_obj_data *od)
{
	float	*vbo;
	int		i;

	i = 0;
	if ((vbo = (float *)malloc(sizeof(float) * od->n_triangle * 6)) == NULL)
		exit(1);
	while (i < od->n_triangle)
	{
		vbo[i * 6 + 0] = 0;
		vbo[i * 6 + 1] = 0;
		vbo[i * 6 + 2] = 1;
		vbo[i * 6 + 3] = 0;
		vbo[i * 6 + 4] = 1;
		vbo[i * 6 + 5] = 1;
		i++;
	}
	return (vbo);
}
