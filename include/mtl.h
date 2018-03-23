/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:34:11 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/22 15:58:31 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MTL_H
# define __MTL_H

typedef struct					s_mtl
{
	char						*name;
	float						ambient_color[3];
	float						diffuse_color[3];
	float						specular_color[3];
	float						specular_exponent;
	float						transparency;
	float						optical_density;
	int							illumination_model;
}								t_mtl;

void							parse_mtl(t_mtl *mtl, char *filename);
void							print_mtl(t_mtl mtl);

#endif
