/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_transform_model.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:10:53 by trecomps          #+#    #+#             */
/*   Updated: 2018/09/13 16:13:30 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			rotate_model(t_scene *scene, int key)
{
	if (key == SDLK_RIGHT)
		scene->model_transformation.rotation.y += 10;
	else if (key == SDLK_LEFT)
		scene->model_transformation.rotation.y -= 10;
	else if (key == SDLK_DOWN)
		scene->model_transformation.rotation.x += 10;
	else if (key == SDLK_UP)
		scene->model_transformation.rotation.x -= 10;
	else if (key == SDLK_q)
		scene->model_transformation.rotation.z += 10;
	else if (key == SDLK_e)
		scene->model_transformation.rotation.z -= 10;
	send_model_mt_opengl(scene);
}

void			translate_model(t_scene *scene, int key)
{
	if (key == SDLK_w)
		scene->model_transformation.translation.y += scene->movement_speed;
	else if (key == SDLK_s)
		scene->model_transformation.translation.y -= scene->movement_speed;
	else if (key == SDLK_a)
		scene->model_transformation.translation.x -= scene->movement_speed;
	else if (key == SDLK_d)
		scene->model_transformation.translation.x += scene->movement_speed;
	else if (key == SDLK_f)
		scene->model_transformation.translation.z -= scene->movement_speed;
	else if (key == SDLK_g)
		scene->model_transformation.translation.z += scene->movement_speed;
	send_model_mt_opengl(scene);
}

void			reset_model(t_scene *scene)
{
	scene->model_transformation.translation = new_vector(0, 0, 0);
	scene->model_transformation.rotation = new_vector(0, 0, 0);
	send_model_mt_opengl(scene);
}

void			explode_model(t_scene *scene, int key)
{
	if (key == SDLK_j)
	{
		if (scene->od->explode_coef >= 0.1f)
			scene->od->explode_coef -= 0.1f;
		else
			scene->od->explode_coef = 0;
	}
	else if (key == SDLK_k)
		scene->od->explode_coef += 0.1f;
	glUniform1f(scene->od->uni_explode_coef, scene->od->explode_coef);
}

void			scale_model(t_scene *scene, int key)
{
	if (key == SDLK_y)
	{
		scene->model_transformation.scale.x *= 1.2;
		scene->model_transformation.scale.y *= 1.2;
		scene->model_transformation.scale.z *= 1.2;
	}
	else if (key == SDLK_u)
	{
		scene->model_transformation.scale.x /= 1.2;
		scene->model_transformation.scale.y /= 1.2;
		scene->model_transformation.scale.z /= 1.2;
	}
	send_model_mt_opengl(scene);
}
