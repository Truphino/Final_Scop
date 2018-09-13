/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:46:45 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/09/13 15:25:14 by trecomps         ###   ########.fr       */
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

typedef struct		s_cs_angles
{
	float			sin_pitch;
	float			cos_pitch;
	float			sin_yaw;
	float			cos_yaw;
}					t_cs_angles;

typedef struct		s_fps_camera
{
	float			pitch;
	float			yaw;
	t_vector		eye;
	GLuint			uni_view_matrix;
	t_matrix		view_matrix;
	t_cs_angles		cs_angles;
	int				lock_camera;
}					t_fps_camera;

typedef struct		s_camera
{
	t_vector		eye;
	t_vector		look_at;
	t_matrix		view_matrix;
	t_matrix		inverse_view_matrix;
	float			fov;
	float			tan_half_height;
	t_light			light;
	GLuint			uni_l_pos;
	GLuint			uni_l_color;
	t_fps_camera	fps_cam;
	GLuint			uni_view_matrix;
}					t_camera;

void				default_camera(t_camera *camera);
void				compute_look_at_view_matrix(t_camera *camera);
void				compute_fps_view_matrix(t_fps_camera *fps_cam);
void				compute_cs_angles(t_fps_camera *fps_cam);

#endif
