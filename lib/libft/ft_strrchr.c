/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:03:05 by trecomps          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:37 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*save;
	int		end;

	ch = (char)c;
	end = ft_strlen(s);
	s += end;
	if (end > 0)
	{
		while (end > -1)
		{
			if (*s == ch)
			{
				save = &*(char *)s;
				return (save);
			}
			s--;
			end--;
		}
	}
	return (NULL);
}
