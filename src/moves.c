/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:07:58 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/31 18:20:11 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	wall_colision(t_cub *cub, int keysym, t_vec pos, double speed)
{
	if (keysym == XK_w)
	{
		cub->player->n_pos.x = pos.x + (speed + 0.25) * cub->camera->dir.x;
		cub->player->n_pos.y = pos.y + (speed + 0.25) * cub->camera->dir.y;
	}
	else if (keysym == XK_s)
	{
		cub->player->n_pos.x = pos.x + (-speed - 0.25) * cub->camera->dir.x;
		cub->player->n_pos.y = pos.y + (-speed - 0.25) * cub->camera->dir.y;
	}
	else if (keysym == XK_d)
	{
		cub->player->n_pos.x = pos.x + (speed + 0.25) * cub->camera->plane.x;
		cub->player->n_pos.y = pos.y + (speed + 0.25) * cub->camera->plane.y;
	}
	else if (keysym == XK_a)
	{
		cub->player->n_pos.x = pos.x + (-speed - 0.25) * cub->camera->plane.x;
		cub->player->n_pos.y = pos.y + (-speed - 0.25) * cub->camera->plane.y;
	}
	if (in_charset(cub->map->map_grid[(int)(cub->player->n_pos.y)]
		[(int)(cub->player->n_pos.x)], "0NSEW"))
		return (0);
	return (1);
}

static void	actualise_player_position(t_cub *cub, int keysym,
			t_vec pos, double speed)
{
	if (keysym == XK_w)
	{
		cub->player->pos.x = pos.x + speed * cub->camera->dir.x;
		cub->player->pos.y = pos.y + speed * cub->camera->dir.y;
	}
	else if (keysym == XK_s)
	{
		cub->player->pos.x = pos.x + -speed * cub->camera->dir.x;
		cub->player->pos.y = pos.y + -speed * cub->camera->dir.y;
	}
	else if (keysym == XK_d)
	{
		cub->player->pos.x = pos.x + speed * cub->camera->plane.x;
		cub->player->pos.y = pos.y + speed * cub->camera->plane.y;
	}
	else if (keysym == XK_a)
	{
		cub->player->pos.x = pos.x + -speed * cub->camera->plane.x;
		cub->player->pos.y = pos.y + -speed * cub->camera->plane.y;
	}
	cub->player->map_x = (int)cub->player->pos.x;
	cub->player->map_y = (int)cub->player->pos.y;
}

void	move_player(t_cub *cub, int keysym)
{
	float	speed;

	speed = cub->player->speed;
	if (wall_colision(cub, keysym, cub->player->pos, speed))
		return ;
	actualise_player_position(cub, keysym, cub->player->pos, speed);
	draw_img(cub);
}
