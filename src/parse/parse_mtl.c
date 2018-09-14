/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:23:30 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/14 12:00:16 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			load_3_float(float tab[3], char *line)
{
	char		**tokens;

	tokens = ft_strsplit(line, ' ');
	tab[0] = atof(tokens[1]);
	tab[1] = atof(tokens[2]);
	tab[2] = atof(tokens[3]);
	free_null_terminated_tab((void **)tokens);
}

void			parse_mtl_line(t_mtl *mtl, char *line)
{
	if (ft_strncmp(line, "newmtl", 6) == 0)
		mtl->name = ft_strdup(line + 7);
	else if (ft_strncmp(line, "illum", 5) == 0)
		mtl->illumination_model = atof(line + 6);
	else if (ft_strncmp(line, "Ka", 2) == 0)
		load_3_float(mtl->ambient_color, line);
	else if (ft_strncmp(line, "Kd", 2) == 0)
		load_3_float(mtl->diffuse_color, line);
	else if (ft_strncmp(line, "Ks", 2) == 0)
		load_3_float(mtl->specular_color, line);
	else if (ft_strncmp(line, "Ns", 2) == 0)
		mtl->specular_exponent = atof(line + 3);
	else if (ft_strncmp(line, "Ni", 2) == 0)
		mtl->optical_density = atof(line + 3);
	else if (ft_strncmp(line, "d", 1) == 0)
		mtl->transparency = atof(line + 2);
}

void			parse_mtl(t_mtl *mtl, char *filename)
{
	char		*line;
	int			fd;

	line = NULL;
	if ((fd = open(filename, O_RDONLY)) < 2)
		exit(1);
	while (get_next_line(fd, &line) > 0)
	{
		parse_mtl_line(mtl, line);
		free_if((void **)&line);
	}
	free_if((void **)&line);
}
