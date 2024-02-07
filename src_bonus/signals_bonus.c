/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:39:28 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 15:54:45 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include "../inc_bonus/window_bonus.h"
//#include <X11/X.h>
//#include <X11/keysym.h>
#include "cub3D_bonus.h"

int	handle_keypress(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		close_window(cub);
	else if (keysym == XK_a || keysym == XK_d
		|| keysym == XK_s || keysym == XK_w)
		move_player(cub, keysym);
	else if (keysym == XK_Left || keysym == XK_Right)
		rotate(cub, keysym);
	return (1);
}
