/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:23:52 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 14:24:31 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	calculate_steps(t_cub *cub, int x)
{
	if (cub->rays[x].ray_dirx < 0)
	{
		cub->rays[x].step_x = -1;
		cub->rays[x].sidedist_x = (cub->player->pos.x
				- cub->rays[x].map_x) * cub->rays[x].deltadist_x;
	}
	else
	{
		cub->rays[x].step_x = 1;
		cub->rays[x].sidedist_x = (cub->rays[x].map_x
				+ 1.0 - cub->player->pos.x) * cub->rays[x].deltadist_x;
	}
	if (cub->rays[x].ray_diry < 0)
	{
		cub->rays[x].step_y = -1;
		cub->rays[x].sidedist_y = (cub->player->pos.y
				- cub->rays[x].map_y) * cub->rays[x].deltadist_y;
	}
	else
	{
		cub->rays[x].step_y = 1;
		cub->rays[x].sidedist_y = (cub->rays[x].map_y
				+ 1.0 - cub->player->pos.y) * cub->rays[x].deltadist_y;
	}
}

void	dda_algo(t_cub *cub, int x, int hit)
{
	while (hit == 0)
	{
		if (cub->rays[x].sidedist_x < cub->rays[x].sidedist_y)
		{
			cub->rays[x].sidedist_x += cub->rays[x].deltadist_x;
			cub->rays[x].map_x += cub->rays[x].step_x;
			if (cub->rays[x].step_x > 0)
				cub->rays[x].side = EAST;
			else
				cub->rays[x].side = WEST;
		}
		else
		{
			cub->rays[x].sidedist_y += cub->rays[x].deltadist_y;
			cub->rays[x].map_y += cub->rays[x].step_y;
			if (cub->rays[x].step_y > 0)
			cub->rays[x].side = SOUTH;
			else
			cub->rays[x].side = NORTH;
		}
		if (cub->rays[x].map_y < 0 || cub->rays[x].map_x < 0
			|| cub->map->map_grid[cub->rays[x].map_y][cub->rays[x].map_x]
			== '1')
					hit = 1;
	}
}

void	calculate_rays(t_cub *cub, int x, int hit)
{
	while (x < cub->win->w)
	{
		cub->rays[x].camera_x = 2 * x / (double)cub->win->w - 1;
		cub->rays[x].ray_dirx = cub->camera->dir.x
			+ cub->camera->plane.x * cub->rays[x].camera_x;
		cub->rays[x].ray_diry = cub->camera->dir.y
			+ cub->camera->plane.y * cub->rays[x].camera_x;
		if (cub->rays[x].ray_dirx != 0)
			cub->rays[x].deltadist_x = fabs(1 / cub->rays[x].ray_dirx);
		else
			cub->rays[x].deltadist_x = 1e30;
		if (cub->rays[x].ray_diry != 0)
			cub->rays[x].deltadist_y = fabs(1 / cub->rays[x].ray_diry);
		else
			cub->rays[x].deltadist_y = 1e30;
		cub->rays[x].map_x = cub->player->map_x;
		cub->rays[x].map_y = cub->player->map_y;
		calculate_steps(cub, x);
		dda_algo(cub, x, hit);
		x++;
	}
}
