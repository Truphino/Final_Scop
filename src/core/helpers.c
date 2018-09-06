/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/06 14:24:04 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void					initialize_to_zero_2(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

void					multi_free_4(void *addr1, void *addr2,
						void *addr3, void *addr4)
{
	free_if(&addr1);
	free_if(&addr2);
	free_if(&addr3);
	free_if(&addr4);
}

void					free_obj_data_mem(t_obj_data *od)
{
	free_if((void **)&od->vertices);
	free_if((void **)&od->normals);
	free_if((void **)&od->face_indexes);
	free_if((void **)&od->normal_indexes);
	free_if((void **)&od);
}
