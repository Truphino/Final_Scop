/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:23:41 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/09/14 14:31:47 by trecomps         ###   ########.fr       */
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
	float		*triangle_vertices;
	t_vector	*vertices;
	t_vector	*normals;
	t_vector	*textures;
	int			*vertex_indexes;
	int			*texture_indexes;
	int			*normal_indexes;
	int			n_vertices;
	int			n_normals;
	int			n_textures;
	int			n_triangles;
	GLuint		uni_text;
	GLuint		smooth_shading;
	float		*explodes_vectors;
	GLuint		uni_explode_coef;
	float		explode_coef;
}				t_obj_data;

t_obj_data		*new_obj_data(void);
void			load_mesh(t_obj_data *od, char *file_name);
void			free_obj_data(t_obj_data *od);

#endif
