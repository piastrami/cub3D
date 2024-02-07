/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:59:49 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/30 18:43:03 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "prototypes.h"
# include "window.h"
# include "textures.h"
# include "img.h"
# include "player.h"
# include "colors.h"
# include "camera.h"
# include "rays.h"
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
