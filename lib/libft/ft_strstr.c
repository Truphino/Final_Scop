/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:57:03 by trecomps          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:37 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		beg;
	char	*ipt;

	if (!(*little))
		return ((char *)big);
	while (*big != '\0')
	{
		i = 0;
		while (*big != *little && *big != '\0')
			big++;
		if (*big == '\0')
			return (0);
		beg = i;
		while (big[i] == little[i] && big[i] != '\0')
			i++;
		if (little[i] == '\0')
		{
			ipt = (char *)&big[beg];
			return (ipt);
		}
		big++;
	}
	return (0);
}
