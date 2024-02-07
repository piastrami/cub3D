/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:18:29 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 14:26:33 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	init_color_tab(t_cub *cub)
{
	cub->colors[WHITE][0] = 255;
	cub->colors[WHITE][1] = 255;
	cub->colors[WHITE][2] = 255;
	cub->colors[BLACK][0] = 0;
	cub->colors[BLACK][1] = 0;
	cub->colors[BLACK][2] = 0;
	cub->colors[GREY][0] = 127;
	cub->colors[GREY][1] = 127;
	cub->colors[GREY][2] = 127;
	cub->colors[YELLOW][0] = 255;
	cub->colors[YELLOW][1] = 255;
	cub->colors[YELLOW][2] = 0;
	cub->colors[RED][0] = 255;
	cub->colors[RED][1] = 0;
	cub->colors[RED][2] = 0;
	cub->colors[GREEN][0] = 0;
	cub->colors[GREEN][1] = 255;
	cub->colors[GREEN][2] = 0;
	cub->colors[BLUE][0] = 0;
	cub->colors[BLUE][1] = 0;
	cub->colors[BLUE][2] = 255;
}

int	init_colors(t_cub *cub)
{
	int	i;

	i = 0;
	cub->colors = malloc(sizeof(int *) * NB_COLORS);
	if (!cub->colors)
		return (0);
	while (i < NB_COLORS)
	{
		cub->colors[i] = malloc(sizeof(int) * 3);
		if (!cub->colors[i])
			return (0);
		i++;
	}
	init_color_tab(cub);
	return (1);
}

int	init_gradient_value(t_cub *cub)
{
	int	i;
	int	end;

	i = 0;
	end = cub->win->half_pixels;
	cub->win->gradient = malloc(sizeof(double) * end);
	if (!cub->win->gradient)
		return (0);
	while (i < end)
	{
		cub->win->gradient[i] = ((double)i / (double)(end)) * 0.5;
		i++;
	}
	return (1);
}
