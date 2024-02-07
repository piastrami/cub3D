/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:05:39 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 14:26:37 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	draw_tile(t_cub *cub, int map_x, int map_y, int color)
{	
	int	x_tile;
	int	y_tile;

	y_tile = 0;
	while (y_tile < SIZE_TILE)
	{
		x_tile = 0;
		while (x_tile < SIZE_TILE)
		{
			if (x_tile == 0 || y_tile == 0 || x_tile == SIZE_TILE - 1
				|| y_tile == SIZE_TILE - 1 || color == BLACK)
				set_pixelrgb(cub, cub->win->index[SIZE_TILE * map_y
					+ SIZE_TILE + y_tile][SIZE_TILE * map_x + SIZE_TILE
					+ x_tile], cub->colors[BLACK]);
			else
				set_pixelrgb(cub, cub->win->index[SIZE_TILE * map_y
					+ SIZE_TILE + y_tile][SIZE_TILE * map_x + SIZE_TILE
					+ x_tile], cub->colors[WHITE]);
			x_tile++;
		}
		y_tile++;
	}
}

void	draw_player(t_cub *cub, int color)
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;
	int	width;

	width = SIZE_TILE / 4;
	y_start = (int)(cub->player->pos.y * SIZE_TILE) - width;
	x_start = (int)(cub->player->pos.x * SIZE_TILE) - width;
	x_end = (int)(cub->player->pos.x * SIZE_TILE) + width;
	y_end = (int)(cub->player->pos.y * SIZE_TILE) + width;
	while (y_start < y_end)
	{
		x_start = (int)(cub->player->pos.x * SIZE_TILE) - width;
		while (x_start < x_end)
		{
			if (is_pixel_white(cub, cub->win->index[y_start
						+ SIZE_TILE][x_start + SIZE_TILE]) == 0)
				set_pixelrgb(cub, cub->win->index[y_start + SIZE_TILE]
				[x_start + SIZE_TILE], cub->colors[color]);
			x_start++;
		}
		y_start++;
	}
}	

void	draw_minimap(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map->map_grid[y])
	{
		x = 0;
		while (cub->map->map_grid[y][x])
		{
			if (cub->map->map_grid[y][x] == '1')
				draw_tile(cub, x, y, WHITE);
			else if (cub->map->map_grid[y][x] == '0'
				|| cub->map->map_grid[y][x] == 'W'
				|| cub->map->map_grid[y][x] == 'N'
				|| cub->map->map_grid[y][x] == 'E'
				|| cub->map->map_grid[y][x] == 'S')
				draw_tile(cub, x, y, BLACK);
			x++;
		}
		y++;
	}
}
