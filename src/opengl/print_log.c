/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:53:08 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/13 11:58:23 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void		print_shader_info_log(GLuint shader_index)
{
	int max_length = 2048;
	int actual_length = 0;
	char shader_log[2048];

	glGetShaderInfoLog(shader_index, max_length, &actual_length, shader_log);
	gl_log("Shader info log for GL index ");
	gl_log(ft_itoa(shader_index));
	gl_log(":\n");
	gl_log(shader_log);
	gl_log("\n");
}

void		print_program_info_log(GLuint program)
{
	int max_length = 2048;
	int actual_length = 0;
	char program_log[2048];
	glGetProgramInfoLog(program, max_length, &actual_length, program_log);
	gl_log("Program info log for GL index ");
	gl_log(ft_itoa(program));
	gl_log(":\n");
	gl_log(program_log);
	gl_log("\n");
}
