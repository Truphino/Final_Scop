/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:23:05 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/23 12:31:35 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void		set_uniform_matrix(GLuint shader_programme, t_scene *scene)
{
	build_transformation_matrix(scene->model_matrix,
			scene->model_transformation);
	transpose_matrix(scene->tr_model_matrix, scene->model_matrix);
	transpose_matrix(scene->camera.tr_view_matrix, scene->camera.view_matrix);
	transpose_matrix(scene->tr_projection, scene->projection);
	scene->uni_model_matrix =
		glGetUniformLocation(shader_programme, "model_matrix");
	glUniformMatrix4fv(scene->uni_model_matrix, 1, GL_FALSE,
			scene->tr_model_matrix);
	scene->camera.uni_view_matrix =
		glGetUniformLocation(shader_programme, "view_matrix");
	glUniformMatrix4fv(scene->camera.uni_view_matrix, 1, GL_FALSE,
			scene->camera.tr_view_matrix);
	scene->uni_project_matrix =
		glGetUniformLocation(shader_programme, "projection_matrix");
	glUniformMatrix4fv(scene->uni_project_matrix, 1, GL_FALSE,
			scene->tr_projection);
}

void		render_obj(t_scene *scene)
{
	t_obj_data	*od;
	t_window	*win;
	GLuint		vao;
	GLuint		shader_programme;
	GLuint		texture_id;

	win = &scene->window;
	od = load_object("./object_files/42_texture.obj", scene);
	scene->od = od;
	od->obj_colours = generate_vbo(od);
	texture_id = load_texture_bmp("./texture/horse.bmp");
	vao = setup_vao(od);
	shader_programme = create_program();
	activate_gl_options();
	free_obj_data(od);
	glClearColor(0.6, 0.6, 0.8, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shader_programme);
	set_uniform_matrix(shader_programme, scene);
	glUniform1i(glGetUniformLocation(shader_programme, "tex"), 0);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, od->n_triangle * 3);
	SDL_GL_SwapWindow(win->window);
}
