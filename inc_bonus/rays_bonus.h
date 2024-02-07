/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:24:50 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 15:58:29 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_BONUS_H
# define RAYS_BONUS_H

typedef struct s_ray
{
	float	camera_x;
	float	ray_dirx;
	float	ray_diry;
	float	sidedist_x;
	float	sidedist_y;
	float	deltadist_x;
	float	deltadist_y;
	float	perpwalldist;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side;
	int		line_height;
}	t_ray;

#endif