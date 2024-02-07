/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:53:01 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 15:58:04 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_BONUS_H
# define CAMERA_BONUS_H

typedef struct s_cam
{
	t_vec	dir;
	t_vec	plane;
	double	rot_speed;
	double	cos_rot;
	double	sin_rot;

}	t_cam;

#endif