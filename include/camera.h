/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:46:45 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/28 09:35:03 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAMERA_H
# define __CAMERA_H

# include "vector.h"
# include "transform.h"
# include "window.h"
# include "matrix.h"

typedef struct
{
	float			position[3];
	float			colors[3];
}					t_light;

typedef struct
{
	GLuint			uni_view_matrix;
	t_vector		eye;
	t_vector		look_at;
	t_matrix		view_matrix;
	t_matrix		inverse_view_matrix;
	float			fov;
	float			tan_half_height;
	t_light			light;
	GLuint			uni_l_pos;
	GLuint			uni_l_color;
}					t_camera;

void				default_camera(t_camera *camera);
void				compute_look_at_view_matrix(t_camera *camera);

#endif
