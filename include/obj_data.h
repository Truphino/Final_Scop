/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:23:41 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/23 11:48:52 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OBJ_DATA_H
# define __OBJ_DATA_H

# include "vector.h"

typedef struct	s_obj_data
{
	float		*obj_colours;
	GLfloat		*final_textures;
	GLfloat		*final_normals;
	t_vector	*vertices;
	t_vector	*normals;
	t_vector	*textures;
	int			*face_indexes;
	int			*texture_indexes;
	int			*normal_indexes;
	int			n_normal_indexes;
	int			n_vertices;
	int			n_normals;
	int			n_textures;
	int			n_faces;
	int			n_triangle;
	float		*triangle_vertices;
	GLuint		uni_text;
	GLuint		smooth_shading;
}				t_obj_data;

t_obj_data		*new_obj_data(void);
void			load_mesh(t_obj_data *od, char *file_name);
void			free_obj_data(t_obj_data *od);

#endif
