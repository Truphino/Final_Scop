/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 01:21:57 by trecomps          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:33 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	int		minsize;
	void	*newptr;

	newptr = ft_memalloc(size);
	if (newptr == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		minsize = ft_strlen(ptr);
		if ((int)size < minsize)
			minsize = size;
		ft_memcpy(newptr, ptr, minsize);
		free(ptr);
	}
	return (newptr);
}
