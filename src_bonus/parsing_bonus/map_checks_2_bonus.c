/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:53:54 by pichatte          #+#    #+#             */
/*   Updated: 2024/02/02 19:27:58 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	replace_floor(char ***grid, int y, int x)
{
	if ((*grid)[y][x] == '1' || (*grid)[y][x] == 'X' || (*grid)[y][x] == 'I')
		return ;
	else if ((*grid)[y][x] == ' ')
		(*grid)[y][x] = 'I';
	else
		(*grid)[y][x] = 'X';
	if ((*grid)[y][x + 1])
		replace_floor(grid, y, x + 1);
	if (x > 0)
		replace_floor(grid, y, x - 1);
	if ((*grid)[y + 1])
		replace_floor(grid, y + 1, x);
	if (y > 0)
		replace_floor(grid, y - 1, x);
}

int	check_for_char(char **grid, char c)
{
	int	y;
	int	x;

	if (!grid || !(*grid))
		return (-1);
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == c)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_for_boundaries(char **grid)
{
	int	y;
	int	x;

	if (!grid)
		return (-1);
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'X' && wrong_neighbour(grid, y, x, "1X"))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	floodfill(t_cub *cub)
{
	char	**grid_copy;

	grid_copy = copy_grid(cub->map->map_grid, cub->map->map_width);
	if (!grid_copy)
		return (1);
	replace_floor(&grid_copy, cub->player->map_y, cub->player->map_x);
	if (check_for_char(grid_copy, 'I'))
	{
		free_tab(grid_copy);
		return (ft_dprintf(2, "Error\nMap not closed\n"), 1);
	}
	if (check_for_boundaries(grid_copy))
		return (free_tab(grid_copy),
			ft_dprintf(2, "Error\nMap not closed\n"), 1);
	erase_outside_map(cub, grid_copy);
	free_tab(grid_copy);
	return (0);
}

void	erase_outside_map(t_cub *cub, char **grid_copy)
{
	int	y;
	int	x;

	y = 0;
	while (grid_copy[y])
	{
		x = 0;
		while (grid_copy[y][x])
		{
			if (grid_copy[y][x] == '0')
				cub->map->map_grid[y][x] = ' ';
			x++;
		}
		y++;
	}
}
