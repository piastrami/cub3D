/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:50:34 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 14:26:43 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	set_index(t_cub *cub)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	while (i < cub->win->total_pixels)
	{
		cub->win->index[y][x] = i;
		i++;
		x++;
		if (x == cub->win->w)
		{
			y++;
			x = 0;
		}
	}
}

void	set_pixelrgb(t_cub *cub, int index, const int *value)
{
	t_pix	pixel;

	pixel.r = value[0];
	pixel.g = value[1];
	pixel.b = value[2];
	pixel.a = 255;
	cub->screen->addr[index * (cub->screen->bits_per_pixel / 8)] = pixel.b;
	cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 1] = pixel.g;
	cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 2] = pixel.r;
	cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 3] = pixel.a;
}

void	ft_get_pixel(t_img *img, int x, int y)
{
	if (y < 0)
		y = 0;
	if (x < 0)
		x = 0;
	img->offset = (x * (img->bits_per_pixel / 8)) + (y * img->size_line);
	if (img->offset < img->size_line * img->height)
		img->pixel = *(unsigned int *)(img->addr + img->offset);
}

void	ft_put_pixel(t_img *canvas, int x, int y, t_img *img)
{
	canvas->offset = (x * (canvas->bits_per_pixel / 8))
		+ (y * canvas->size_line);
	*(unsigned int *)(canvas->addr + canvas->offset) = img->pixel;
}

int	is_pixel_white(t_cub *cub, int index)
{
	t_pix	pixel;

	pixel.b = cub->screen->addr[index
		* (cub->screen->bits_per_pixel / 8)];
	pixel.g = cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 1];
	pixel.r = cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 2];
	if (pixel.b == 255 && pixel.g == 255 && pixel.r == 255)
		return (1);
	else
		return (0);
}
