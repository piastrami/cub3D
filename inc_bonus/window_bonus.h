/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:56:05 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 15:59:02 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BONUS_H
# define WINDOW_BONUS_H

# define SIZE_TILE 16
# include <stdbool.h>

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w;
	int		h;
	int		total_pixels;
	int		half_pixels;
	int		**index;
	bool	show_minimap;
	float	*gradient;
}				t_win;

#endif