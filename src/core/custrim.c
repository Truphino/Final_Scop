/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:19:46 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/14 14:21:55 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static int	is_whitespace(char c)
{
	if (c == '\n' || c == ' ' || c == '\t' || c == '\v' || c == '\f' ||
			c == '\r')
		return (1);
	return (0);
}

char		*custrim(char *str)
{
	int		i;
	int		len;
	int		start;
	char	*dest;

	i = 0;
	len = ft_strlen(str);
	start = 0;
	while(is_whitespace(str[start]))
		start++;
	i = len - 1;
	while (is_whitespace(str[i]) && i)
	{
		i--;
		len--;
	}
	dest = ft_strnew(len - start);
	return (ft_strncpy(dest, str + start, len - start));
}
