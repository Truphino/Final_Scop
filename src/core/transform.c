/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/20 11:21:23 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static t_transform	new_transformation(t_vector scale, t_vector rotation,
						t_vector translation, t_vector prerotation_translation)
{
	t_transform t;

	t.scale = scale;
	t.rotation = rotation;
	t.translation = translation;
	return (t);
}

void				default_transformation(t_transform *transformation)
{
	*transformation = new_transformation(new_vector(1, 1, 1),
		new_vector(0, 0, 0), new_vector(0, 0, 0), new_vector(0, 0, 0));
	transformation->flags = 0;
}
