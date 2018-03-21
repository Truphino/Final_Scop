/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/20 13:50:28 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void		copy_matrix(t_matrix dst, t_matrix src)
{
	dst[0 * 4 + 0] = src[0 * 4 + 0];
	dst[0 * 4 + 1] = src[0 * 4 + 1];
	dst[0 * 4 + 2] = src[0 * 4 + 2];
	dst[0 * 4 + 3] = src[0 * 4 + 3];
	dst[1 * 4 + 0] = src[1 * 4 + 0];
	dst[1 * 4 + 1] = src[1 * 4 + 1];
	dst[1 * 4 + 2] = src[1 * 4 + 2];
	dst[1 * 4 + 3] = src[1 * 4 + 3];
	dst[2 * 4 + 0] = src[2 * 4 + 0];
	dst[2 * 4 + 1] = src[2 * 4 + 1];
	dst[2 * 4 + 2] = src[2 * 4 + 2];
	dst[2 * 4 + 3] = src[2 * 4 + 3];
	dst[3 * 4 + 0] = src[3 * 4 + 0];
	dst[3 * 4 + 1] = src[3 * 4 + 1];
	dst[3 * 4 + 2] = src[3 * 4 + 2];
	dst[3 * 4 + 3] = src[3 * 4 + 3];
}

void		transpose_matrix(t_matrix dest, t_matrix src)
{
	dest[0 * 4 + 0] = src[0 * 4 + 0];
	dest[0 * 4 + 1] = src[1 * 4 + 0];
	dest[0 * 4 + 2] = src[2 * 4 + 0];
	dest[0 * 4 + 3] = src[3 * 4 + 0];
	dest[1 * 4 + 0] = src[0 * 4 + 1];
	dest[1 * 4 + 1] = src[1 * 4 + 1];
	dest[1 * 4 + 2] = src[2 * 4 + 1];
	dest[1 * 4 + 3] = src[3 * 4 + 1];
	dest[2 * 4 + 0] = src[0 * 4 + 2];
	dest[2 * 4 + 1] = src[1 * 4 + 2];
	dest[2 * 4 + 2] = src[2 * 4 + 2];
	dest[2 * 4 + 3] = src[3 * 4 + 2];
	dest[3 * 4 + 0] = src[0 * 4 + 3];
	dest[3 * 4 + 1] = src[1 * 4 + 3];
	dest[3 * 4 + 2] = src[2 * 4 + 3];
	dest[3 * 4 + 3] = src[3 * 4 + 3];
}
