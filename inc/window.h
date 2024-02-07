/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:56:05 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/31 17:22:19 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

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