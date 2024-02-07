/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:39:41 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 15:59:11 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_BONUS_H
# define TEXTURES_BONUS_H
# include "img_bonus.h"

typedef struct s_cub	t_cub;
typedef struct s_img	t_img;

typedef enum s_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}	t_direction;

typedef struct s_tex
{
	char	*directions[4];
	int		h[4];
	t_img	tex_images[4];
	int		floor[3];
	int		ceiling[3];
}			t_tex;

typedef struct s_texline
{
	double	x_wall;
	int		tex_x;
	int		tex_y;
	int		scale;
	int		wall_start;
	int		wall_end;
	t_img	*texture;
}	t_texline;

#endif