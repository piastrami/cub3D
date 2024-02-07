/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:29:34 by pichatte          #+#    #+#             */
/*   Updated: 2024/02/01 14:24:44 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_all_3(t_cub *cub, int level)
{	
	int	i;

	if (level > 8)
		free_tex_imgs(cub);
	if (level > 7)
		free(cub->rays);
	if (level > 6)
		free(cub->win->gradient);
	i = 0;
	while (i < cub->win->h)
		free(cub->win->index[i++]);
	free(cub->win->index);
}

void	free_all_2(t_cub *cub, int level)
{
	int	i;

	i = NB_COLORS - 1;
	if (level > 5)
		free_all_3(cub, level);
	if (level > 4)
	{
		while (i >= 0)
		{
			if (cub->colors[i])
				free(cub->colors[i--]);
		}
		free(cub->colors);
		mlx_destroy_image(cub->win->mlx_ptr, cub->screen->ptr);
		free(cub->screen);
	}
	if (level > 3)
	{
		mlx_destroy_display(cub->win->mlx_ptr);
		free(cub->win->mlx_ptr);
		free(cub->win);
	}
}

void	free_all(t_cub *cub3D, int level, int directions)
{
	int	i;

	if (level > 2)
		free_all_2(cub3D, level);
	if (level > 1)
	{
		free(cub3D->camera);
		free(cub3D->player);
		free_tab(cub3D->map->map_grid);
	}
	if (level > 0)
	{
		i = 0;
		while (i < directions && i < 4)
		{	
			free((cub3D->textures->directions)[i]);
			(cub3D->textures->directions)[i] = NULL;
			i++;
		}
	}
	free (cub3D->file->cub_file);
	free_tab(cub3D->file->file_grid);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab[i]);
	tab[i] = NULL;
	free (tab);
	tab = NULL;
}

void	free_tex_imgs(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->textures->tex_images[i].ptr)
			mlx_destroy_image(cub->win->mlx_ptr,
				cub->textures->tex_images[i].ptr);
		i++;
	}
}
