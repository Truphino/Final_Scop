/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 19:04:56 by trecomps          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:32 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qsort(int *array, int size)
{
	int beg;
	int end;
	int pivot;

	if (size < 2)
		return ;
	beg = 0;
	end = size - 1;
	pivot = array[size / 2];
	while (array[beg] > pivot)
		beg++;
	while (array[end] <= pivot)
		end--;
	if (beg >= end)
		return ;
	ft_swap(&array[beg], &array[end]);
	ft_qsort(array, beg);
	ft_qsort(array + size, size - 1);
}
