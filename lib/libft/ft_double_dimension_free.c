/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_dimension_free.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:33:03 by trecomps          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:24 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_dimension_free(void **ptr, int d)
{
	int i;

	i = 0;
	while (i < d)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
