/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:58:48 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/31 16:36:04 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	rotate_left(t_cub *cub, float olddirx, float oldplanex)
{
	cub->camera->dir.x = olddirx * cub->camera->cos_rot + cub->camera->dir.y
		* cub->camera->sin_rot;
	cub->camera->dir.y = -olddirx * cub->camera->sin_rot + cub->camera->dir.y
		* cub->camera->cos_rot;
	cub->camera->plane.x = oldplanex * cub->camera->cos_rot
		+ cub->camera->plane.y * cub->camera->sin_rot;
	cub->camera->plane.y = -oldplanex * cub->camera->sin_rot
		+ cub->camera->plane.y * cub->camera->cos_rot;
}

void	rotate(t_cub *cub, int keysym)
{
	float	olddirx;
	float	oldplanex;

	olddirx = cub->camera->dir.x;
	oldplanex = cub->camera->plane.x;
	if (keysym == XK_Right)
	{
		cub->camera->dir.x = olddirx * cub->camera->cos_rot - cub->camera->dir.y
			* cub->camera->sin_rot;
		cub->camera->dir.y = olddirx * cub->camera->sin_rot + cub->camera->dir.y
			* cub->camera->cos_rot;
		cub->camera->plane.x = oldplanex * cub->camera->cos_rot
			- cub->camera->plane.y * cub->camera->sin_rot;
		cub->camera->plane.y = oldplanex * cub->camera->sin_rot
			+ cub->camera->plane.y * cub->camera->cos_rot;
	}
	else if (keysym == XK_Left)
		rotate_left(cub, olddirx, oldplanex);
	draw_img(cub);
}
