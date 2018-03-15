/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:03:07 by trecomps          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:37 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*stuck;
	int				i;
	unsigned int	beg;

	beg = start;
	i = 0;
	stuck = (char *)malloc(sizeof(char) * (len + 1));
	if (stuck != NULL)
	{
		while (len > 0)
		{
			stuck[i] = s[beg];
			beg++;
			len--;
			i++;
		}
		stuck[i] = '\0';
	}
	return (stuck);
}
