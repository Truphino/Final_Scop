/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:02:35 by trecomps          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:25 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char		*s;
	unsigned char			*d;
	unsigned char			*ipts;

	d = dst;
	s = src;
	while (n > 0)
	{
		if (*s == (unsigned char)c)
		{
			*d++ = *s++;
			ipts = (unsigned char *)&*d;
			return (ipts);
		}
		*d++ = *s++;
		n--;
	}
	return (NULL);
}
