/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:23:05 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/21 16:33:10 by trecomps         ###   ########.fr       */
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

GLuint		bind_buffer_vbo(float *buffer, int size)
{
	GLuint vbo;

	vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size,
			buffer,
			GL_STATIC_DRAW);
	return (vbo);
}

GLuint		setup_vao(t_obj_data *od)
{
	GLuint	vao;
	GLuint	point_vbo;
	GLuint	colours_vbo;
	GLuint	texture_vbo;

	vao = 0;
	point_vbo = bind_buffer_vbo(od->triangle_vertices, od->n_triangle * 9);
	colours_vbo = bind_buffer_vbo(od->obj_colours, od->n_triangle * 9);
	texture_vbo = bind_buffer_vbo(od->final_textures, od->n_triangle * 6);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, point_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, texture_vbo);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	return (vao);
}

void		render_obj(t_scene *scene)
{
	t_obj_data	*od;
	t_window	*win;
	GLuint		vao;
	GLuint		shader_programme;
	GLuint		texture_id;

	win = &scene->window;
	od = load_object("./object_files/42.obj", scene);
	scene->od = od;
	od->obj_colours = generate_vbo(od);
	texture_id = load_texture_bmp("./texture/bronze_copper.bmp");
	od->final_textures = generate_texture_vbo(od);
	vao = setup_vao(od);
	free(od->obj_colours);
	shader_programme = create_program();
	glUniform1i(glGetUniformLocation(shader_programme, "tex"), 0);
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	glFrontFace(GL_CCW);
	glClearColor(0.6, 0.6, 0.8, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shader_programme);
	set_uniform_matrix(shader_programme, scene);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, od->n_triangle * 3);
	SDL_GL_SwapWindow(win->window);
}
