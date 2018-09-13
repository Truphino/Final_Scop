/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 09:37:23 by trecomps          #+#    #+#             */
/*   Updated: 2015/12/28 14:03:07 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					len_l(char *buf)
{
	int				i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i + 1);
	return (-1);
}

char				*take_one(char *buf)
{
	int				i;
	char			*str;
	int				len;

	i = 0;
	len = len_l(buf) - 1;
	if (len < 0)
		return (NULL);
	if ((str = (char *)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	if (len == 0)
		return (str);
	str = ft_strncpy(str, buf, len);
	return (str);
}

char				*rm_one_line(char *buf, int len)
{
	char			*tmp;

	if ((tmp = ft_strdup(buf + len)) == NULL)
		return (NULL);
	free(buf);
	buf = tmp;
	return (buf);
}

int					read_it(char **buf, int fd)
{
	char			*tmp;
	int				re;

	while (len_l(*buf) < 1)
	{
		if ((tmp = (char *)ft_memalloc(BUFF_SIZE + 1)) == NULL)
			return (-1);
		re = read(fd, tmp, BUFF_SIZE);
		if (re == -1 || re == 0)
			return (re);
		*buf = ft_strjoin(*buf, tmp);
		free(tmp);
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		*buf = NULL;
	int				re;

	if (!line)
		return (-1);
	if (!buf)
		if ((buf = (char *)ft_memalloc(1)) == NULL)
			return (-1);
	if ((*line = take_one(buf)) == NULL)
	{
		if ((re = read_it(&buf, fd)) == 0 && ft_strlen(buf) > 0)
		{
			*line = ft_strdup(buf);
			*buf = '\0';
			return (1);
		}
		if ((re == 0 && ft_strlen(buf) == 0) || re == -1)
			return (re);
		*line = take_one(buf);
	}
	buf = rm_one_line(buf, len_l(buf));
	return (1);
}
