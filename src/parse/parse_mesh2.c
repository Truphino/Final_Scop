/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pares_mesh2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:15:15 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/09/11 18:15:07 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_data.h"
#include "parse.h"

void		fetch_obj_data_mem(t_obj_data *od)
{
	od->vertices = malloc(sizeof(t_vector) * od->n_vertices);
	od->normals = malloc(sizeof(t_vector) * od->n_normals);
	od->textures = malloc(sizeof(t_vector) * od->n_textures);
	od->face_indexes = malloc(sizeof(int) * od->n_faces * 4);
	od->texture_indexes = malloc(sizeof(int) * od->n_faces * 4);
	od->normal_indexes = malloc(sizeof(int) * od->n_faces * 4);
	ft_memset(od->face_indexes, -1, od->n_faces * 4 * sizeof(int));
	ft_memset(od->texture_indexes, -1, od->n_faces * 4 * sizeof(int));
	ft_memset(od->normal_indexes, -1, od->n_faces * 4 * sizeof(int));
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

void		load_subfield(t_obj_data *od, char *tokens, size_t len, int pos)
{
	char		*tmp;
	char		*slash;
	size_t		i;
	size_t		tmp_len;

	i = 0;
	tmp = tokens;
	tmp_len = len;
	while (i < 3 && tmp)
	{
		if (i == 0)
			od->face_indexes[(od->n_faces * 4) + pos] = atoi(tmp) - 1;
		else if (i == 1)
			od->texture_indexes[(od->n_faces * 4) + pos] = atoi(tmp) - 1;
		else if (i == 2)
			od->normal_indexes[(od->n_faces * 4) + pos] = atoi(tmp) - 1;
		if ((tmp = ft_memchr(tmp, '/', len)))
		{
			tmp += 1;
			tmp_len = len - (tmp - tokens);
		}
		i++;
	}
}

void		push_obj_face_data(t_obj_data *od, char *line)
{
	int		i;
	char	*tokens;
	char	*end;
	size_t	len;

	i = 0;
	len = 0;
	tokens = line;
	while (i < 4 && tokens)
	{
		if ((tokens = ft_strchr(tokens, ' ')))
		{
			tokens += 1;
			if ((end = ft_strchr(tokens, ' ')))
				len = end - tokens;
			else
				len = ft_strlen(tokens);
			load_subfield(od, tokens, len, i);
		}
		i++;
	}
	od->n_faces++;
}
