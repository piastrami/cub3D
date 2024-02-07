/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:37:07 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 14:23:39 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	close_window(t_cub *cub)
{
	mlx_destroy_window(cub->win->mlx_ptr, cub->win->win_ptr);
	free_all(cub, 9, 4);
	exit(0);
}

void	create_window(t_cub *cub)
{
	cub->win->win_ptr = mlx_new_window(cub->win->mlx_ptr,
			cub->win->w, cub->win->h, "CHIPS3D");
	if (cub->win->win_ptr == NULL)
	{
		mlx_destroy_display(cub->win->mlx_ptr);
		return ;
	}
	draw_img(cub);
	mlx_hook(cub->win->win_ptr, DestroyNotify, 0, close_window, cub);
	mlx_hook(cub->win->win_ptr, KeyPress, KeyPressMask, handle_keypress, cub);
	mlx_loop_hook(cub->win->mlx_ptr, loop, cub);
	mlx_loop(cub->win->mlx_ptr);
}
