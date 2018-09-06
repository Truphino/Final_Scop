/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:35:17 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/09/06 14:17:51 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_data.h"
#include "parse.h"

int			get_extension(const char *file_name)
{
	char *file_extension;

	file_extension = ft_strrchr(file_name, '.');
	if (file_extension)
	{
		if (ft_strncmp(file_extension, ".obj", 4) == 0)
		{
			return (OBJ);
		}
	}
	exit(0);
}

void		meta_obj(t_obj_data *od, const int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ')
			od->n_vertices++;
		if (line[0] == 'f' && line[1] == ' ')
			od->n_faces++;
		if (line[0] == 'v' && line[1] == 'n')
			od->n_normals++;
		if (line[0] == 'v' && line[1] == 't')
			od->n_textures++;
		free_if((void **)&line);
	}
	free_if((void **)&line);
}

void		reset_counter(t_obj_data *od)
{
	od->n_vertices = 0;
	od->n_normals = 0;
	od->n_normal_indexes = 0;
	od->n_faces = 0;
	od->n_textures = 0;
}

void		load_mesh(t_obj_data *od, char *file_name)
{
	int			fd;
	int			extension;

	fd = open(file_name, O_RDONLY);
	if (fd < 2)
		exit(1);
	extension = get_extension(file_name);
	if (extension == OBJ)
		meta_obj(od, fd);
	else
		exit(1);
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (extension == OBJ)
		load_obj(od, fd);
	close(fd);
}

void		load_obj(t_obj_data *od, const int fd)
{
	char	*line;

	line = NULL;
	fetch_obj_data_mem(od);
	reset_counter(od);
	while (get_next_line(fd, &line) > 0)
	{
		parse_line(od, line);
		free_if((void **)&line);
	}
	free_if((void **)&line);
}
