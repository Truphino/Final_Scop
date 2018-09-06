/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:47:53 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/06 14:16:46 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			free_obj_data(t_obj_data *od)
{
	free_if((void **)&od->obj_colours);
	free_if((void **)&od->final_textures);
	free_if((void **)&od->final_normals);
	free_if((void **)&od->vertices);
	free_if((void **)&od->normals);
	free_if((void **)&od->textures);
	free_if((void **)&od->face_indexes);
	free_if((void **)&od->texture_indexes);
	free_if((void **)&od->normal_indexes);
}
