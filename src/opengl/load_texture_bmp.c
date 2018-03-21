/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_bmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:46:56 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/21 16:36:03 by trecomps         ###   ########.fr       */
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
			if ((bmp_p->header_second_part = (unsigned char*)malloc(sizeof(char) *
							bmp_p->data_offset - 54)) == NULL)
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

void			print_texture(t_bmp_parser bmp_p)
{
	int			i;

	i = bmp_p.image_size;
	printf("Data offset: %i\nWidth: %i\nHeight: %i\nImage Size: %i\n",
			bmp_p.data_offset, bmp_p.width, bmp_p.height, bmp_p.image_size);
	while (i < bmp_p.image_size)
	{
		printf("%u\t%u\t%u\n",
				bmp_p.bmp_data[i],
				bmp_p.bmp_data[i + 1],
				bmp_p.bmp_data[i + 2]);
		i += 3;
	}
}

GLuint			load_texture_bmp(const char *filename)
{
	GLuint			texture_id;
	t_bmp_parser	bmp_p;

	bmp_p = parse_texture_bmp(filename);
	//print_texture(bmp_p);
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmp_p.width, bmp_p.height, 0,
			GL_BGR, GL_UNSIGNED_BYTE, bmp_p.bmp_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	return (texture_id);
}