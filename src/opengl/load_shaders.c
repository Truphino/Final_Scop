/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:42:33 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/15 16:49:05 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"
#include "parse.h"

char		*load_shader_file(char *filename)
{
	int		fd;
	int		first_line_len;
	char	*first_line;
	char	*file;
	char	*shader_string;

	if ((fd = open(filename, O_RDONLY)) < 2)
		return NULL;
	if (get_next_line(fd, &first_line) <= 0)
		return NULL;
	if ((file = file_to_string(fd)) == NULL)
		return NULL;
	first_line_len = ft_strlen(first_line);
	shader_string = (char *)ft_memalloc((first_line_len + ft_strlen(file) + 2) *
			sizeof(char));
	ft_strcpy(shader_string, first_line);
	shader_string[first_line_len] = '\n';
	ft_strcpy(shader_string + first_line_len + 1, file);
	return shader_string;

	return NULL;
}
