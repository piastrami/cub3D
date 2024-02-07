/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:46 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/02 17:42:15 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	free_map_grid_errors(t_cub *cub, int level, int i)
{
	int	j;

	if (level)
	{
		j = 0;
		while (j < i)
		{
			free (cub->map->map_grid[j]);
			j++;
		}
		free (cub->map->map_grid);
	}
	free_all(cub, 1, 4);
	printf("Error\nMalloc fail");
	exit(EXIT_FAILURE);
}

int	map_to_grid(t_cub *cub3D)
{
	int	i;
	int	first_line;

	cub3D->map->map_grid = ft_calloc(sizeof(char *),
			cub3D->map->map_height + 1);
	if (!cub3D->map->map_grid)
		free_map_grid_errors(cub3D, 0, 0);
	i = 0;
	first_line = first_line_of_map(cub3D);
	while (i < cub3D->map->map_height)
	{
		cub3D->map->map_grid[i]
			= ft_strdup(cub3D->file->file_grid[first_line + i]);
		if (!cub3D->map->map_grid[i])
			free_map_grid_errors(cub3D, 1, i);
		i++;
	}
	return (0);
}

int	check_map(t_cub *cub3D)
{
	bool	player_exists;

	if (!map_is_last(cub3D))
		return (free_all(cub3D, 1, 4), 1);
	if (map_has_nl(cub3D))
		return (free_all(cub3D, 1, 4), 2);
	if (set_map_dimensions(cub3D))
		return (printf("Error\nInvalid map\n"), free_all(cub3D, 1, 4), 3);
	if (map_to_grid(cub3D))
		return (3);
	player_exists = false;
	if (set_first_position(cub3D, player_exists, 0, 0))
		return (5);
	if (floodfill(cub3D))
		return (free_all(cub3D, 2, 4), 6);
	return (0);
}

int	check_textures(t_cub *cub3D)
{
	const char	textures_array[7][4] = {"NO ", "EA ", "SO ", "WE ", "C ", "F "};
	int			i;

	i = 0;
	while (textures_array[i] && textures_array[i][0])
	{
		if (check_texture_number((char *)(textures_array[i]), cub3D,
			ft_strlen(textures_array[i])))
		{
			free_all(cub3D, 1, i);
			return (1);
		}
		if (i < 4)
			set_texture_pointers(cub3D, &(cub3D->textures->directions[i]),
				(char *)textures_array[i], i);
		i++;
	}
	if (check_textures_valid(cub3D, "C "))
		return (1);
	if (check_textures_valid(cub3D, "F "))
		return (1);
	return (0);
}

int	check_errors(t_cub *cub3D)
{
	if (ft_check_file_ext(cub3D->file->filename))
		return (1);
	if (check_map_printable(cub3D->file->filename, 0))
		return (2);
	if (copy_file(cub3D))
		return (3);
	if (check_file_pollution(cub3D))
		return (4);
	if (check_textures(cub3D))
		return (5);
	if (check_map(cub3D))
		return (6);
	return (0);
}
