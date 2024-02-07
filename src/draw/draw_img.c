/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:12:51 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/02 19:38:46 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_sky(t_cub *cub)
{
	int	rgb[3];
	int	i;

	i = 0;
	while (i < cub->win->half_pixels)
	{
		rgb[0] = cub->textures->ceiling[0]
			- (int)(cub->win->gradient[cub->win->half_pixels - i - 1]
				* cub->textures->ceiling[0]);
		rgb[1] = cub->textures->ceiling[1]
			- (int)(cub->win->gradient[cub->win->half_pixels - i - 1]
				* cub->textures->ceiling[1]);
		rgb[2] = cub->textures->ceiling[2]
			- (int)(cub->win->gradient[cub->win->half_pixels - i - 1]
				* cub->textures->ceiling[2]);
		set_pixelrgb(cub, i, rgb);
		i++;
	}
}

static void	draw_sky_and_floor(t_cub *cub)
{
	int	rgb[3];
	int	i;

	draw_sky(cub);
	i = 0;
	while (i + cub->win->half_pixels < cub->win->total_pixels)
	{
		rgb[0] = cub->textures->floor[0]
			- (int)(cub->win->gradient[i] * 0.4 * cub->textures->floor[0]);
		rgb[1] = cub->textures->floor[1]
			- (int)(cub->win->gradient[i] * 0.4 * cub->textures->floor[1]);
		rgb[2] = cub->textures->floor[2]
			- (int)(cub->win->gradient[i] * 0.4 * cub->textures->floor[2]);
		set_pixelrgb(cub, (i + cub->win->half_pixels), rgb);
		i++;
	}
}

void	draw_img(t_cub *cub)
{
	draw_sky_and_floor(cub);
	calculate_rays(cub, 0, 0);
	draw_walls(cub);
}

int	loop(t_cub *cub)
{
	mlx_put_image_to_window(cub->win->mlx_ptr, cub->win->win_ptr,
		cub->screen->ptr, 0, 0);
	return (0);
}
