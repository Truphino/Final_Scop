/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:16:02 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/28 11:14:48 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void		print_loop(t_scene *scene)
{
	t_window	*window;

	window = &scene->window;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, scene->od->n_triangle * 3);
	SDL_GL_SwapWindow(SDL_WINDOW);
}

void		send_model_mt_opengl(t_scene *scene)
{
	build_transformation_matrix(scene->model_matrix,
								scene->model_transformation);
	glUniformMatrix4fv(scene->uni_model_matrix, 1, GL_TRUE,
						scene->model_matrix);
}
