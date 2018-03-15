/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:02:49 by trecomps          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:33 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*save;
	int		size;

	size = ft_strlen(s);
	ch = (char)c;
	while (size >= 0)
	{
		if (*s == ch)
		{
			save = &*(char *)s;
			return (save);
		}
		size--;
		s++;
	}
	return (NULL);
}
