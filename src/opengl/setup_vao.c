/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_vao.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:26:58 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/13 14:48:43 by trecomps         ###   ########.fr       */
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

	vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vbo_to_vao(bind_buffer_vbo(od->triangle_vertices, od->n_triangle * 9),
			3, 0);
	vbo_to_vao(bind_buffer_vbo(od->final_normals, od->n_triangle * 9),
			3, 1);
	vbo_to_vao(bind_buffer_vbo(od->explodes_vectors, od->n_triangle * 9),
			3, 2);
	vbo_to_vao(bind_buffer_vbo(od->final_textures, od->n_triangle * 6),
			2, 3);
	vbo_to_vao(bind_buffer_vbo(od->obj_colours, od->n_triangle * 9),
			3, 4);
	return (vao);
}
