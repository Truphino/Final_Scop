/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:47:53 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/23 11:51:52 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			free_obj_data(t_obj_data *od)
{
	free_if(od->obj_colours);
	free_if(od->final_textures);
	free_if(od->final_normals);
	free_if(od->vertices);
	free_if(od->normals);
	free_if(od->textures);
	free_if(od->face_indexes);
	free_if(od->texture_indexes);
	free_if(od->normal_indexes);
}
