/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:41:41 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 15:58:16 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_BONUS_H
# define IMG_BONUS_H

typedef struct s_img
{
	void			*ptr;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				offset;
	int				pixel;
	int				**pixel_matrix;
}	t_img;

#endif