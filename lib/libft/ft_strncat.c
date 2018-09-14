/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:03:01 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/14 11:57:01 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*d;
	const char	*s;
	int			i;
	int			j;

	d = s1;
	s = s2;
	i = 0;
	j = 0;
	while (d[i] != 0)
		i++;
	while (n > 0 && s[j])
	{
		d[i++] = s[j++];
		n--;
	}
	d[i] = '\0';
	return (s1);
}
