/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:54:29 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/13 11:58:12 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

int			compile_shader_log(GLuint shader_index)
{
	int		params;

	params = -1;
	glCompileShader(shader_index);
	glGetShaderiv(shader_index, GL_COMPILE_STATUS, &params);
	if (params != GL_TRUE)
	{
		gl_log("Shader compilation error, index :");
		gl_log(ft_itoa(shader_index));
		gl_log("\n");
		print_shader_info_log(shader_index);
		exit(1);
	}

	return 1;
}

int			link_program_log(GLuint program)
{
	int		params;

	params = -1;
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &params);
	if (params != GL_TRUE)
	{
		gl_log("Prgram linking error, index :");
		gl_log(ft_itoa(program));
		gl_log("\n");
		print_program_info_log(program);
		exit(1);
	}

	return 1;
}
