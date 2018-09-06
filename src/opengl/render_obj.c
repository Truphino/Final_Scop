/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:23:05 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/06 15:14:50 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void		set_uniform_variables(GLuint shader_programme, t_scene *scene)
{
	build_transformation_matrix(scene->model_matrix,
			scene->model_transformation);
	scene->uni_model_matrix =
		glGetUniformLocation(shader_programme, "model_matrix");
	glUniformMatrix4fv(scene->uni_model_matrix, 1, GL_TRUE,
			scene->model_matrix);
	scene->camera.fps_cam.uni_view_matrix =
		glGetUniformLocation(shader_programme, "fps_view_matrix");
	glUniformMatrix4fv(scene->camera.fps_cam.uni_view_matrix, 1, GL_TRUE,
			scene->camera.fps_cam.view_matrix);
	scene->uni_project_matrix =
		glGetUniformLocation(shader_programme, "projection_matrix");
	glUniformMatrix4fv(scene->uni_project_matrix, 1, GL_TRUE,
			scene->projection);
	scene->camera.uni_l_pos =
		glGetUniformLocation(shader_programme, "light_position");
	glUniform3fv(scene->camera.uni_l_pos, 1, scene->camera.light.position);
	scene->camera.uni_l_color =
		glGetUniformLocation(shader_programme, "light_color");
	glUniform3fv(scene->camera.uni_l_color, 1, scene->camera.light.colors);
	scene->od->uni_explode_coef =
		glGetUniformLocation(shader_programme, "explode_coef");
	glUniform1f(scene->od->uni_explode_coef, scene->od->explode_coef);
}

void		render_obj(t_scene *scene)
{
	t_obj_data	*od;
	t_window	*win;
	GLuint		vao;
	GLuint		shader_programme;
	GLuint		texture_id;

	win = &scene->window;
	od = load_object(scene->obj_file_name, scene);
	scene->od = od;
	if (scene->textures_enabled)
		texture_id = load_texture_bmp(scene->text_file_name);
	else
		od->obj_colours = generate_vbo(od);
	vao = setup_vao(od, scene->textures_enabled);
	shader_programme = create_program(scene->textures_enabled);
	activate_gl_options();
	free_obj_data(od);
	glClearColor(0.6, 0.6, 0.8, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shader_programme);
	set_uniform_variables(shader_programme, scene);
	glUniform1i(glGetUniformLocation(shader_programme, "tex"), 0);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, od->n_triangle * 3);
	SDL_GL_SwapWindow(win->window);
}
