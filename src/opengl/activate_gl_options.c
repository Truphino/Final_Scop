/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activate_gl_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:38:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/23 12:35:12 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

static void		activate_cull_face(void)
{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
}

void			activate_gl_options(void)
{
	glEnable(GL_TEXTURE_2D);
	if (ACTIVATE_CULL_FACE)
		activate_cull_face();
}
