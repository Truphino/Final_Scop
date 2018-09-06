/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/06 14:21:06 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_range					range(double min, double max)
{
	t_range	range;

	range.min = min;
	range.max = max;
	return (range);
}

void					swap(double *a, double *b)
{
	double c;

	c = *a;
	*a = *b;
	*b = c;
}

void					free_if(void **ptr)
{
	if (ptr && *ptr)
		ft_memdel(ptr);
}

void					free_null_terminated_tab(void **ptr)
{
	int		i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
}
