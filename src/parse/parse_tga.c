/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tga.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:37:25 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/21 09:40:25 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char		*parse_tga(char *filename)
{
	char	*file_as_string;
	int		fd;

	fd = open(filename, O_RDONLY);
	file_as_string = file_to_string(fd);
	close(fd);
	return (NULL);
}
