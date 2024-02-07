/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:27:46 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 15:58:52 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

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