/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:23:30 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/22 16:04:05 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			print_3_float(char *message, float tab[3])
{
	printf("%s%f\t%f\t%f\n", message, tab[0], tab[1], tab[2]);
}

void			print_mtl(t_mtl mtl)
{
	printf("newmtl: %s\n", mtl.name);
	printf("Ns: %f\n", mtl.specular_exponent);
	print_3_float("Ka: ", mtl.ambient_color);
	print_3_float("Kd: ", mtl.diffuse_color);
	print_3_float("Ks: ", mtl.specular_color);
	printf("Ni: %f\n", mtl.optical_density);
	printf("d: %f\n", mtl.transparency);
	printf("illum: %i\n", mtl.illumination_model);
}

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
		free_if(line);
	}
	free_if(line);
}
