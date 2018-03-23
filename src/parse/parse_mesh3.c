/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:59:12 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/23 10:00:28 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			push_obj_texture(t_obj_data *od, char *line)
{
	char		**tokens;

	tokens = ft_strsplit(line, ' ');
	od->textures[od->n_textures].x = atof(tokens[1]);
	od->textures[od->n_textures].y = atof(tokens[2]);
	od->textures[od->n_textures].z = 0;
	od->textures[od->n_textures].w = 0;
	od->n_textures++;
	multi_free_4(tokens[0], tokens[1], tokens[2], tokens[3]);
	free(tokens);
}

void			push_smooth_shading_data(t_obj_data *od, char *line)
{
	if (ft_strncmp(line, "s on", 4) == 0 || ft_strncmp(line, "s 1", 3) == 0)
		od->smooth_shading = 1;
}

void			parse_line(t_obj_data *od, char *line)
{
	if (line[0] == 'v' && line[1] == ' ')
		push_obj_vertex(od, line);
	else if (line[0] == 'v' && line[1] == 'n')
		push_obj_normal(od, line);
	else if (line[0] == 'v' && line[1] == 't')
		push_obj_texture(od, line);
	else if (line[0] == 'f')
		push_obj_face_data(od, line);
	else if (line[0] == 's')
		push_smooth_shading_data(od, line);
}
