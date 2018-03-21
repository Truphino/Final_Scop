/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:22:24 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/20 13:50:59 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

GLfloat			*opengl_matrix(GLfloat *gl_matrix, t_matrix matrix)
{
	gl_matrix[0] = matrix[0 * 4 + 0];
	gl_matrix[1] = matrix[0 * 4 + 1];
	gl_matrix[2] = matrix[0 * 4 + 2];
	gl_matrix[3] = matrix[0 * 4 + 3];
	gl_matrix[4] = matrix[1 * 4 + 0];
	gl_matrix[5] = matrix[1 * 4 + 1];
	gl_matrix[6] = matrix[1 * 4 + 2];
	gl_matrix[7] = matrix[1 * 4 + 3];
	gl_matrix[8] = matrix[2 * 4 + 0];
	gl_matrix[9] = matrix[2 * 4 + 1];
	gl_matrix[10] = matrix[2 * 4 + 2];
	gl_matrix[11] = matrix[2 * 4 + 3];
	gl_matrix[12] = matrix[3 * 4 + 0];
	gl_matrix[13] = matrix[3 * 4 + 1];
	gl_matrix[14] = matrix[3 * 4 + 2];
	gl_matrix[15] = matrix[3 * 4 + 3];
	return (gl_matrix);
}
