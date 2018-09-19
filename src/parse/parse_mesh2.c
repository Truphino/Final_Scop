/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pares_mesh2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:15:15 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/09/19 12:12:17 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_data.h"
#include "parse.h"

void		fetch_obj_data_mem(t_obj_data *od)
{
	od->vertices = ft_memalloc(sizeof(t_vector) * od->n_vertices);
	od->normals = ft_memalloc(sizeof(t_vector) * od->n_normals);
	od->textures = ft_memalloc(sizeof(t_vector) * od->n_textures);
	od->vertex_indexes = ft_memalloc(sizeof(int) * od->n_triangles * 3);
	od->texture_indexes = ft_memalloc(sizeof(int) * od->n_triangles * 3);
	od->normal_indexes = ft_memalloc(sizeof(int) * od->n_triangles * 3);
	od->smooth_shading = 0;
}

void		push_obj_vertex(t_obj_data *od, char *line)
{
	char **tokens;

	tokens = ft_strsplit(line, ' ');
	od->vertices[od->n_vertices].x = atof(tokens[1]);
	od->vertices[od->n_vertices].y = atof(tokens[2]);
	od->vertices[od->n_vertices].z = atof(tokens[3]);
	od->vertices[od->n_vertices].w = 1.0f;
	od->n_vertices++;
	free_null_terminated_tab((void **)tokens);
}

void		push_obj_normal(t_obj_data *od, char *line)
{
	char **tokens;

	tokens = ft_strsplit(line, ' ');
	od->normals[od->n_normals].x = atof(tokens[1]);
	od->normals[od->n_normals].y = atof(tokens[2]);
	od->normals[od->n_normals].z = atof(tokens[3]);
	od->normals[od->n_normals].w = 1.0f;
	od->n_normals++;
	free_null_terminated_tab((void **)tokens);
}

void		load_subfield(t_obj_data *od, char *tokens, int pos)
{
	char		*tmp;
	size_t		i;
	size_t		tmp_len;

	i = 0;
	tmp = tokens;
	while (i < 3 && tmp)
	{
		if (i == 0)
			od->vertex_indexes[(od->n_triangles * 3) + pos] = atoi(tmp) - 1;
		else if (i == 1)
			od->texture_indexes[(od->n_triangles * 3) + pos] = atoi(tmp) - 1;
		else if (i == 2)
			od->normal_indexes[(od->n_triangles * 3) + pos] = atoi(tmp) - 1;
		if ((tmp = ft_strchr(tmp, '/')))
			tmp += 1;
		i++;
	}
}

void		push_obj_face_data(t_obj_data *od, char *line)
{
	int		i;
	char	**tokens;

	i = 1;
	tokens = ft_strsplit(line, ' ');
	while (tokens && tokens[0] && tokens[i])
	{
		if (i <= 3)
			load_subfield(od, tokens[i], i - 1);
		if (i > 3)
		{
			load_subfield(od, tokens[1], 0);
			load_subfield(od, tokens[i - 1], 1);
			load_subfield(od, tokens[i], 2);
		}
		if (i >= 3)
			od->n_triangles++;
		i++;
	}
	free_null_terminated_tab((void **)tokens);
}
