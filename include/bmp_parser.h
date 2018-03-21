/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:50:18 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/21 15:18:22 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BMP_PARSER_H
# define __BMP_PARSER_H

# define HEADER_DATA_OFFSET 10
# define HEADER_IMAGE_SIZE 34
# define HEADER_IMAGE_WIDTH 18
# define HEADER_IMAGE_HEIGHT 22

typedef struct				s_bmp_parser
{
	unsigned char			header[55];
	unsigned char			*header_second_part;
	unsigned int			data_offset;
	unsigned int			width;
	unsigned int			height;
	unsigned int			image_size;
	unsigned char			*bmp_data;
}							t_bmp_parser;

#endif
