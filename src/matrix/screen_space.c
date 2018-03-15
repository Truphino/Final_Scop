/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/15 12:11:05 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void	init_screen_space(t_matrix m, double width, double height)
{
	m[0 * 4 + 0] = width / 2;
	m[0 * 4 + 1] = 0;
	m[0 * 4 + 2] = 0;
	m[0 * 4 + 3] = width / 2 - 0.5;
	m[1 * 4 + 0] = 0;
	m[1 * 4 + 1] = -height / 2;
	m[1 * 4 + 2] = 0;
	m[1 * 4 + 3] = height / 2 - 0.5;
	m[2 * 4 + 0] = 0;
	m[2 * 4 + 1] = 0;
	m[2 * 4 + 2] = 1;
	m[2 * 4 + 3] = 0;
	m[3 * 4 + 0] = 0;
	m[3 * 4 + 1] = 0;
	m[3 * 4 + 2] = 0;
	m[3 * 4 + 3] = 1;
}
