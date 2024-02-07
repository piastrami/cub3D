/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:59:49 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 15:57:35 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "libft.h"
# include "mlx.h"
# include "prototypes_bonus.h"
# include "window_bonus.h"
# include "textures_bonus.h"
# include "img_bonus.h"
# include "player_bonus.h"
# include "colors_bonus.h"
# include "camera_bonus.h"
# include "rays_bonus.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_file	t_file;
typedef struct s_map	t_map;

typedef struct s_cub
{
	t_win	*win;
	t_img	*screen;
	t_tex	*textures;
	t_file	*file;
	t_map	*map;
	t_pos	*player;
	t_cam	*camera;
	t_ray	*rays;	
	int		**colors;
}	t_cub;

typedef struct s_map
{
	char	**map_grid;
	int		map_height;
	int		map_width;
}	t_map;

typedef struct s_file
{
	char	*cub_file;
	int		file_len;
	char	*filename;
	char	**file_grid;
}	t_file;

#endif
