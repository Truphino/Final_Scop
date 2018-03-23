/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_vao.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:26:58 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/23 12:31:21 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

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

void		vbo_to_vao(GLuint vbo, int row_size, int counter)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(counter, row_size, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(counter);
}

GLuint		setup_vao(t_obj_data *od)
{
	GLuint	vao;
	GLuint	point_vbo;
	GLuint	colours_vbo;
	GLuint	texture_vbo;
	GLuint	normals_vbo;

	vao = 0;
	point_vbo = bind_buffer_vbo(od->triangle_vertices, od->n_triangle * 9);
	colours_vbo = bind_buffer_vbo(od->obj_colours, od->n_triangle * 9);
	texture_vbo = bind_buffer_vbo(od->final_textures, od->n_triangle * 6);
	normals_vbo = bind_buffer_vbo(od->final_normals, od->n_triangle * 9);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vbo_to_vao(point_vbo, 3, 0);
	vbo_to_vao(colours_vbo, 3, 1);
	vbo_to_vao(texture_vbo, 2, 2);
	vbo_to_vao(normals_vbo, 3, 3);
	return (vao);
}
