/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/13 17:27:05 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				in_comments(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '/')
		{
			if (s[i + 1])
			{
				if (s[i + 1] == '/')
				{
					return (1);
				}
			}
		}
		i++;
	}
	return (0);
}

int				only_spaces(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!is_space(s[i]))
			return (0);
		i++;
	}
	return (1);
}
