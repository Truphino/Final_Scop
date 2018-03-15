/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:27:26 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/15 15:10:51 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MACROS_H
# define __MACROS_H

# define PI									3.14159265359
# define FOV								45.0
# define FOV_RADIANS						PI * (FOV / 180.0)
# define DEFAULT_WINDOW_HEIGHT				400
# define DEFAULT_WINDOW_WIDTH				600
# define ASPECT_RATIO						WIDTH / HEIGHT
# define INVERSE_AR							HEIGHT / WIDTH
# define BCKGD								new_vector(0, 0, 0)
# define UP_VECTOR							new_vector(0, -1, 0)
# define MAX_BOUND							FLT_MAX
# define MIN_PRECISION						0.00000001
# define Z_NEAR								1.0f
# define Z_FAR								100.0f
# define Z_RANGE							Z_FAR - Z_NEAR

# define MIN(a,b) (((a)<(b))?(a):(b))
# define MAX(a,b) (((a)>(b))?(a):(b))

#endif
