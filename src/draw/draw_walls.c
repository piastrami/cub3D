/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:45:04 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/31 12:57:45 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_walls(t_cub *cub)
{
	int	x;
	int	wall_start;
	int	wall_end;

	x = 0;
	while (x < cub->win->w)
	{
		if (cub->rays[x].side == EAST || cub->rays[x].side == WEST)
			cub->rays[x].perpwalldist
				= (cub->rays[x].sidedist_x - cub->rays[x].deltadist_x);
		else
			cub->rays[x].perpwalldist
				= (cub->rays[x].sidedist_y - cub->rays[x].deltadist_y);
		cub->rays[x].line_height
			= (int)(cub->win->h / cub->rays[x].perpwalldist);
		wall_start = -cub->rays[x].line_height / 2 + cub->win->h / 2;
		if (wall_start < 0)
			wall_start = 0;
		wall_end = cub->rays[x].line_height / 2 + cub->win->h / 2;
		if (wall_end >= cub->win->h)
			wall_end = cub->win->h - 1;
		texture_to_img(cub, x, wall_start, wall_end);
		x++;
	}
}

static void	draw_tex_on_wall(t_cub *cub, t_texline *texline, int x)
{
	while (texline->wall_start < texline->wall_end)
	{
		texline->scale = texline->wall_start * texline->texture->width
			- cub->win->h * texline->texture->width / 2
			+ cub->rays[x].line_height * texline->texture->width / 2;
		if (texline->scale < 0)
			texline->scale *= texline->scale;
		texline->tex_y = ((texline->scale * texline->texture->height)
				/ cub->rays[x].line_height) / texline->texture->width;
		ft_get_pixel(texline->texture, texline->tex_x, texline->tex_y);
		ft_put_pixel(cub->screen, x, texline->wall_start, texline->texture);
		texline->wall_start++;
	}
}

void	texture_to_img(t_cub *cub, int x, int wall_start, int wall_end)
{
	t_texline		texline;

	texline.texture = &(cub->textures->tex_images[cub->rays[x].side]);
	texline.wall_start = wall_start;
	texline.wall_end = wall_end;
	if (texline.texture)
	{
		if (cub->rays[x].side == NORTH || cub->rays[x].side == SOUTH)
			texline.x_wall = (float)(cub->player->pos.x
					+ cub->rays[x].ray_dirx * cub->rays[x].perpwalldist);
		else
			texline.x_wall = (float)(cub->player->pos.y
					+ cub->rays[x].ray_diry * cub->rays[x].perpwalldist);
		texline.x_wall -= floor((texline.x_wall));
		texline.tex_x = (int)(texline.x_wall
				* (double)(texline.texture->width));
		if ((cub->rays[x].side == EAST && cub->rays[x].ray_dirx > 0)
			|| (cub->rays[x].side == WEST && cub->rays[x].ray_dirx > 0)
			|| (cub->rays[x].side == NORTH && cub->rays[x].ray_diry < 0)
			|| (cub->rays[x].side == SOUTH && cub->rays[x].ray_diry < 0))
			texline.tex_x = texline.texture->width - (int)texline.tex_x - 1;
		draw_tex_on_wall(cub, &texline, x);
	}
}

// void	draw_pixcolumn(t_cub *cub, int x, int y0, int y1)
// {
// 	int	*color;
// 	if (cub->rays[x].side == NORTH)
// 		color = &cub->colors[GREEN][0];
// 	else if (cub->rays[x].side == EAST)
// 		color = &cub->colors[BLUE][0];
// 	else if (cub->rays[x].side == SOUTH)
// 		color = &cub->colors[RED][0];
// 	else if (cub->rays[x].side == WEST)
// 		color = &cub->colors[YELLOW][0];
// 	while (y0 < y1)
// 	{
// 		set_pixelRGB(cub, cub->win->index[y0][x], color);
// 		y0++;
// 	}
// }