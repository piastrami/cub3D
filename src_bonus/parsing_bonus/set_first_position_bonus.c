/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_first_position_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:38:16 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/02 17:00:40 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	allocate_structs(t_cub *cub)
{
	cub->player = malloc(sizeof(t_pos) * 1);
	if (!cub->player)
		return (ft_dprintf(2, "Error\nFailed memory allocation\n"), 1);
	cub->camera = malloc (sizeof(t_cam) * 1);
	if (!cub->camera)
	{
		ft_dprintf(2, "Error\nFailed memory allocation\n");
		return (free(cub->player), 2);
	}
	cub->camera->rot_speed = 0.1;
	cub->camera->cos_rot = cos(cub->camera->rot_speed);
	cub->camera->sin_rot = sin(cub->camera->rot_speed);
	cub->player->speed = 0.1;
	return (0);
}

static void	set_south(t_cub *cub)
{
	cub->camera->dir.x = 0;
	cub->camera->dir.y = 1;
	cub->camera->plane.x = -0.66;
	cub->camera->plane.y = 0;
}

static void	set_dir_vector(t_cub *cub, char dir)
{
	if (dir == 'N')
	{
		cub->camera->dir.x = 0;
		cub->camera->dir.y = -1;
		cub->camera->plane.x = 0.66;
		cub->camera->plane.y = 0;
	}	
	else if (dir == 'W')
	{
		cub->camera->dir.x = -1;
		cub->camera->dir.y = 0;
		cub->camera->plane.x = 0;
		cub->camera->plane.y = -0.66;
	}	
	else if (dir == 'E')
	{
		cub->camera->dir.x = 1;
		cub->camera->dir.y = 0;
		cub->camera->plane.x = 0;
		cub->camera->plane.y = 0.66;
	}	
	else if (dir == 'S')
		set_south(cub);
}

int	set_player_pos(t_cub *cub3D, int x, int y)
{
	if (allocate_structs(cub3D))
	{
		free_all(cub3D, 2, 4);
		exit (EXIT_FAILURE);
	}
	cub3D->player->pos.x = x + 0.5;
	cub3D->player->pos.y = y + 0.5;
	cub3D->player->map_x = x;
	cub3D->player->map_y = y;
	set_dir_vector(cub3D, cub3D->map->map_grid[y][x]);
	return (0);
}

int	set_first_position(t_cub *cub3D, bool player_exists, int x, int y)
{
	y = 0;
	while (cub3D->map->map_grid[y])
	{
		x = 0;
		while (cub3D->map->map_grid[y][x])
		{
			if (in_charset(cub3D->map->map_grid[y][x], "NWES"))
			{
				if (!player_exists)
				{
					set_player_pos(cub3D, x, y);
					player_exists = true;
				}
				else
					return (printf("Error\nToo many players\n"),
						free_all(cub3D, 3, 4), 2);
			}
			x++;
		}
		y++;
	}
	if (!player_exists)
		return (printf("Error\nPlayer not found\n"), free_all(cub3D, 2, 4), 3);
	return (0);
}
