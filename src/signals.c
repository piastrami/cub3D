/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:39:28 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/23 15:05:43 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/window.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include "cub3D.h"

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

// int handle_keyrelease(int keysym, t_cub *cub3D)
// {
// 	(void)cub3D; //
// 	if (keysym == XK_Left)
// 		; // arreter de rotate la camera ?
// 	else if (keysym == XK_Right)
// 		; // arreter de rotate la camera ?
// }