/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:27:40 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 15:57:11 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_BONUS_H
# define COLORS_BONUS_H
# define NB_COLORS 7

enum e_colors {
	WHITE,
	BLACK,
	GREY,
	YELLOW,
	RED,
	GREEN,
	BLUE,
};

typedef struct s_pix
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}	t_pix;

#endif