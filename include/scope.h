/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 10:52:53 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/16 12:05:37 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCOPE_H
# define __SCOPE_H

# include "external_headers.h"
# include "local_headers.h"

typedef struct				s_scene
{
	t_obj_data				*od;
	int						flags;
	t_matrix				screen_space;
	t_camera				camera;
	t_window				window;
	t_matrix				model_matrix;
	t_transform				model_transformation;
	t_matrix				projection;
	GLuint					uni_project_matrix;
	GLuint					uni_model_matrix;
}							t_scene;

void						kill_sdl(t_scene *scene, char *str, int fd);
void						hello_triangle(t_scene *scene);
void						put_image(t_scene *scene);
void						initialize_scene(t_scene *scene);
void						poll_events(t_scene *scene);
void						swap(double *a, double *b);
void						free_if(void *ptr);
t_range						range(double min, double max);
void						free_obj_data_mem(t_obj_data *od);
void						multi_free_4(void *addr1, void *addr2,
								void *addr3, void *addr4);
void						initialize_to_zero_2(int *a, int *b);

#endif
