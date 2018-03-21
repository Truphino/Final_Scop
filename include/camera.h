/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:46:45 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/20 14:18:13 by trecomps         ###   ########.fr       */
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
	GLuint			uni_view_matrix;
	t_vector		eye;
	t_vector		look_at;
	t_matrix		view_matrix;
	t_matrix		inverse_view_matrix;
	float			fov;
	float			tan_half_height;
	t_matrix		tr_view_matrix;
}					t_camera;

void				default_camera(t_camera *camera);
void				compute_look_at_view_matrix(t_camera *camera);

#endif
