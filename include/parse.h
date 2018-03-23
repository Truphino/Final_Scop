/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:04:40 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/22 14:48:49 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSE_H
# define __PARSE_H

# include "libft.h"
# include "get_next_line.h"
# include "scope.h"

enum	e_parse_errors
{
	BAD_FILE = 200,
	UNDERDETERMINED = 201,
	UNKNOWN_ELEMENT = 202,
	BAD_FORM = 203,
	DEGENERATE_SHAPE = 204,
	TOO_MANY_OBJECTS = 205,
	TOO_MANY_LIGHTS = 206,
	UNEXPECTED_SYMBOL = 207,
	REPEAT_SYMBOL = 208,
	CONFLICTING_IDS = 209,
	DEGENERATE_VALUE = 210,
	MEMORY_ERROR = 211,
	TEXTURE_ERROR = 212,
	CAMERA_UNDEFINED = 401,
	NO_OBJECTS = 402,
	NO_LIGHTS = 403,
	DENSE_SCENE = 404,
};

void		load_obj(t_obj_data *od, const int fd);
void		reset_counter(t_obj_data *od);
char		*file_to_string(const int fd);
int			capital_letter(char c);
int			lower_case_letter(char c);
int			balancing_symbol(char c);
int			is_digit(char c);
int			is_space(char c);
int			in_comments(char *s);
int			only_spaces(char *s);
void		fetch_obj_data_mem(t_obj_data *od);
void		push_obj_vertex(t_obj_data *od, char *line);
void		push_obj_normal(t_obj_data *od, char *line);
void		load_subfield(t_obj_data *od,char *tokens, size_t len, int pos);
void		push_obj_face_data(t_obj_data *od, char *line);
void		push_obj_texture(t_obj_data *od, char *line);
void		parse_line(t_obj_data *od, char *line);

#endif
