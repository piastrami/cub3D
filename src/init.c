/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:43:06 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/02 18:17:16 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_index(t_cub *cub)
{
	int	y;

	y = 0;
	cub->win->index = (int **)malloc(sizeof(int *) * cub->win->h);
	if (!cub->win->index)
		return (0);
	while (y < cub->win->h)
	{
		cub->win->index[y] = (int *)malloc(sizeof(int) * cub->win->w);
		if (!cub->win->index[y])
		{
			while (y > 0)
			{
				free(cub->win->index[y - 1]);
				y--;
			}
			return (free(cub->win->index), 0);
		}
		y++;
	}
	set_index(cub);
	return (1);
}

int	init_pointers(t_cub *cub, t_file *file, t_tex *textures, char *filename)
{
	cub->file = file;
	cub->file->filename = filename;
	cub->textures = textures;
	cub->file->cub_file = NULL;
	cub->file->file_grid = NULL;
	cub->file->file_len = 0;
	cub->textures->tex_images[0].ptr = NULL;
	cub->textures->tex_images[1].ptr = NULL;
	cub->textures->tex_images[2].ptr = NULL;
	cub->textures->tex_images[3].ptr = NULL;
	cub->player = NULL;
	cub->camera = NULL;
	return (0);
}

static int	init_window(t_cub *cub)
{
	cub->win = malloc(sizeof(t_win));
	if (cub->win == NULL)
		return (0);
	cub->win->mlx_ptr = mlx_init();
	if (cub->win->mlx_ptr == NULL)
		return (free(cub->win), 0);
	mlx_get_screen_size(cub->win->mlx_ptr, &cub->win->w, &cub->win->h);
	cub->win->total_pixels = cub->win->w * cub->win->h;
	cub->win->half_pixels = cub->win->total_pixels / 2;
	if (cub->map->map_width * SIZE_TILE > cub->win->w / 2
		|| cub->map->map_height * SIZE_TILE > cub->win->h / 2)
	{
		printf("Minimap too big\n");
		cub->win->show_minimap = false;
	}
	else
		cub->win->show_minimap = true;
	return (1);
}

static int	init_screen(t_cub *cub)
{
	cub->screen = malloc (sizeof(t_img) * 1);
	if (!cub->screen)
		return (0);
	cub->screen->ptr
		= mlx_new_image(cub->win->mlx_ptr, cub->win->w, cub->win->h);
	if (!cub->screen->ptr)
		return (free(cub->screen), 0);
	cub->screen->addr = mlx_get_data_addr(cub->screen->ptr,
			&cub->screen->bits_per_pixel, &cub->screen->size_line,
			&cub->screen->endian);
	if (!cub->screen->addr)
		return (mlx_destroy_image(cub->win->mlx_ptr, cub->screen->ptr),
			free(cub->screen), 0);
	return (1);
}

int	init_cub3d(t_cub *cub)
{
	if (init_window(cub) == 0)
		return (printf("Error\nWindow init\n"), free_all(cub, 3, 4), 0);
	if (init_screen(cub) == 0)
		return (printf("Error\nScreen init\n"), free_all(cub, 4, 4), 0);
	if (init_colors(cub) == 0)
		return (printf("Error\nColours init\n"), free_all(cub, 5, 4), 0);
	if (init_index(cub) == 0)
		return (printf("Error\nIndex init\n"), free_all(cub, 5, 4), 0);
	if (init_gradient_value(cub) == 0)
		return (printf("Error\nGradient init\n"), free_all(cub, 6, 4), 0);
	cub->rays = malloc(sizeof(t_ray) * cub->win->w);
	if (!cub->rays)
		return (printf("Error\nRays init\n"), free_all(cub, 7, 4), 0);
	if (init_textures(cub))
		return (printf("Error\nLoading texture\n"), free_all(cub, 9, 4), 0);
	return (1);
}
