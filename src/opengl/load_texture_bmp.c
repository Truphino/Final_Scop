/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_bmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:46:56 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/14 11:59:47 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static int		read_header(t_bmp_parser *bmp_p, int fd)
{
	if (read(fd, bmp_p->header, 54) == 54)
	{
		if (bmp_p->header[0] == 'B' && bmp_p->header[1] == 'M')
		{
			bmp_p->data_offset = *(int *)&(bmp_p->header[HEADER_DATA_OFFSET]);
			bmp_p->image_size = *(int *)&(bmp_p->header[HEADER_IMAGE_SIZE]);
			bmp_p->width = *(int *)&(bmp_p->header[HEADER_IMAGE_WIDTH]);
			bmp_p->height = *(int *)&(bmp_p->header[HEADER_IMAGE_HEIGHT]);
			if (bmp_p->image_size == 0)
				bmp_p->image_size = 3 * bmp_p->height * bmp_p->width;
			if (bmp_p->data_offset == 0)
				bmp_p->data_offset = 54;
			bmp_p->header[54] = '\0';
			if ((bmp_p->header_second_part = (unsigned char*)malloc(
					sizeof(char) * bmp_p->data_offset - 54)) == NULL)
				return (0);
			read(fd, bmp_p->header_second_part, bmp_p->data_offset - 54);
			return (1);
		}
	}
	return (0);
}

t_bmp_parser	parse_texture_bmp(const char *filename)
{
	t_bmp_parser	bmp_p;
	int				fd;

	if ((fd = open(filename, O_RDONLY)) < 2)
		ft_putendl("Can't open bmp");
	if (!read_header(&bmp_p, fd))
	{
		ft_putendl("Not a valid bmp");
		exit(1);
	}
	if ((bmp_p.bmp_data = (unsigned char *)ft_memalloc(sizeof(char) *
					bmp_p.image_size)) == NULL)
		exit(1);
	read(fd, bmp_p.bmp_data, bmp_p.image_size);
	close(fd);
	return (bmp_p);
}

GLuint			load_texture_bmp(const char *filename)
{
	GLuint			texture_id;
	t_bmp_parser	bmp_p;

	bmp_p = parse_texture_bmp(filename);
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmp_p.width, bmp_p.height, 0,
			GL_BGR, GL_UNSIGNED_BYTE, bmp_p.bmp_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	return (texture_id);
}

GLuint			load_texture_bmp_cubemap(const char *filename)
{
	GLuint			texture_id;
	t_bmp_parser	bmp_p;
	int				i;

	i = -1;
	bmp_p = parse_texture_bmp(filename);
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture_id);
	while (++i < 6)
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB,
			bmp_p.width, bmp_p.height, 0,
			GL_BGR, GL_UNSIGNED_BYTE, bmp_p.bmp_data);
	glActiveTexture(GL_TEXTURE0);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	return (texture_id);
}
