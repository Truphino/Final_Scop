/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_vbo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:33:14 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/06 16:32:33 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

float		*generate_vbo(t_obj_data *od)
{
	float		*vbo;
	int			i;
	t_vector	tmp;

	if ((vbo = (float *)ft_memalloc(sizeof(float) *
					od->n_triangle * 9)) == NULL)
		exit(1);
	i = 0;
	while (i < od->n_triangle * 3)
	{
		tmp = vec_abs(unit_vector(new_vector(od->triangle_vertices[i * 3 + 0],
										od->triangle_vertices[i * 3 + 1],
										od->triangle_vertices[i * 3 + 2])));
		if (i % 2)
		{
			vbo[i * 3 + 0] = tmp.x;
			vbo[i * 3 + 1] = tmp.y;
			vbo[i * 3 + 2] = tmp.z;
		}
		else
		{
			vbo[i * 3 + 0] = tmp.x + ((1 - tmp.x) / 2);
			vbo[i * 3 + 1] = tmp.y + ((1 - tmp.y) / 2);
			vbo[i * 3 + 2] = tmp.z + ((1 - tmp.z) / 2);
		}
		i++;
	}
	return (vbo);
}

void		generate_texture_vbo(t_obj_data *od)
{
	int		i;

	i = 0;
	while (i < od->n_triangle)
	{
		od->final_textures[i * 6 + 0] = 0;
		od->final_textures[i * 6 + 1] = 0;
		od->final_textures[i * 6 + 2] = 1;
		od->final_textures[i * 6 + 3] = 0;
		od->final_textures[i * 6 + 4] = 1;
		od->final_textures[i * 6 + 5] = 1;
		i++;
	}
}
