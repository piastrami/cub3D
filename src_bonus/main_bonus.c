/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:43 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/01 14:23:32 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	main(int ac, char **av)
{
	t_cub	cub;
	t_tex	textures;
	t_file	file;
	t_map	map;

	if (ac != 2)
	{
		ft_dprintf(2, "Error\nYou must have 1 argument\n");
		return (1);
	}
	if (init_pointers(&cub, &file, &textures, av[1]))
		return (2);
	cub.map = &map;
	if (check_errors(&cub))
		return (1);
	if (init_cub3d(&cub) == 0)
		return (1);
	create_window(&cub);
	free_all(&cub, 3, 4);
	return (0);
}
