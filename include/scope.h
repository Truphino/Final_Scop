/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:18:48 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/13 18:58:37 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCOPE_H
# define __SCOPE_H

# include "external_headers.h"
# include "local_headers.h"

typedef struct				s_transition
{
	GLuint					uni_enabled;
	GLuint					uni_time;
	int						enabled;
	clock_t					time;
}							t_transition;

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
	char					*obj_file_name;
	char					*text_file_name;
	float					movement_speed;
	int						texture_enabled;
	GLuint					uni_tex_enabled;
	t_transition			transition;
}							t_scene;

void						free_null_terminated_tab(void **ptr);
void						kill_sdl(t_scene *scene, char *str, int fd);
void						render_obj(t_scene *scene);
void						put_image(t_scene *scene);
void						initialize_scene(t_scene *scene);
void						swap(double *a, double *b);
void						free_if(void **ptr);
t_range						range(double min, double max);
void						free_obj_data_mem(t_obj_data *od);
void						multi_free_4(void *addr1, void *addr2,
										void *addr3, void *addr4);
void						initialize_to_zero_2(int *a, int *b);
t_obj_data					*load_object(char *filename, t_scene *scene);
void						print_loop(t_scene *scene);
void						send_model_mt_opengl(t_scene *scene);
void						poll_events(t_scene *scene);
void						scale_model(t_scene *scene, int key);
void						explode_model(t_scene *scene, int key);
void						reset_model(t_scene *scene);
void						translate_model(t_scene *scene, int key);
void						rotate_model(t_scene *scene, int key);
void						handle_mouse(t_scene *s, SDL_MouseMotionEvent e);
void						handle_keys(t_scene *scene, int key);
void						switch_texture_colours(t_scene *scene, int key);
void						change_movement_speed(t_scene *scene, int key);

#endif
