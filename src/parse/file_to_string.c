/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/11 17:03:54 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char		*append(char *s, char *to_add)
{
	char		*final;
	int			total_length;
	int			i;
	int			j;

	i = 0;
	total_length = ft_strlen(s) + ft_strlen(to_add);
	final = (char *)ft_memalloc(sizeof(char) * (total_length + 1));
	final[total_length] = '\0';
	while (i < (int)ft_strlen(s))
	{
		final[i] = s[i];
		i++;
	}
	j = 0;
	while (j < (int)ft_strlen(to_add))
	{
		final[i] = to_add[j];
		i++;
		j++;
	}
	free(s);
	return (final);
}

char		*file_to_string(const int fd)
{
	char	*file_as_string;
	char	*line;
	int		lines;
	int		r;

	lines = 0;
	r = 0;
	file_as_string = (char *)ft_memalloc(sizeof(char));
	file_as_string[0] = '\0';
	while ((r = get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		if (!only_spaces(line) && !in_comments(line))
		{
			file_as_string = append(file_as_string, line);
		}
		free_if((void **)&line);
		lines++;
	}
	free_if((void **)&line);
	return (lines ? file_as_string : NULL);
}
