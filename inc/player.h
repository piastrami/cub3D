/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:27:46 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/31 13:02:03 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_vec
{
	float	x;
	float	y;
}	t_vec;

typedef struct s_pos
{
	t_vec	pos;
	t_vec	n_pos;
	float	speed;
	int		map_x;
	int		map_y;
}	t_pos;

#endif