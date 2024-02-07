/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:50:15 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 17:04:23 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "window.h"
#include "cub3D.h"

static int	check_texture_transparency(t_img *texture)
{
	int	y;
	int	x;

	y = 0;
	while (y < texture->height)
	{
		x = 0;
		while (x < texture->width)
		{
			ft_get_pixel(texture, x, y);
			if (texture->pixel == -16777216)
				return (1);
			x++;
		}		
		y++;
	}
	return (0);
}

static int	set_tex_img_ptr(t_cub *cub, t_img *texture, int i)
{
	texture->ptr = mlx_xpm_file_to_image(cub->win->mlx_ptr,
			cub->textures->directions[i], &(texture->width),
			&(texture->height));
	if (!texture->ptr)
		return (1);
	texture->addr = mlx_get_data_addr(texture->ptr, &(texture->bits_per_pixel),
			&(texture->size_line), &(texture->endian));
	if (!texture->addr)
		return (2);
	return (0);
}

int	init_textures(t_cub *cub3D)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (set_tex_img_ptr(cub3D, &(cub3D->textures->tex_images[i]), i))
			return (1);
		if (cub3D->textures->tex_images[i].height
			!= cub3D->textures->tex_images[i].width)
			return (ft_dprintf(2, "Error\nTexture not square\n"), 2);
		if (check_texture_transparency(&(cub3D->textures->tex_images[i])))
			return (ft_dprintf(2, "Error\nTexture invalid\n"), 3);
		i++;
	}
	return (0);
}
