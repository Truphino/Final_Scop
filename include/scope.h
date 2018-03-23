/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:18:48 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/23 12:19:31 by trecomps         ###   ########.fr       */
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
	t_matrix				tr_projection;
	t_matrix				tr_model_matrix;
}							t_scene;

void						free_null_terminated_tab(void **ptr);
void						kill_sdl(t_scene *scene, char *str, int fd);
void						render_obj(t_scene *scene);
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
t_obj_data					*load_object(char *filename, t_scene *scene);
void						print_loop(t_scene *scene);
void						send_model_mt_opengl(t_scene *scene);

#endif
