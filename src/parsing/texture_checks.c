/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:03:52 by pichatte          #+#    #+#             */
/*   Updated: 2024/02/02 18:28:10 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	* RGB code just word
*/
#include "textures.h"
#include "cub3D.h"
#include "libft.h"

int	set_map_dimensions(t_cub *cub)
{
	int		first_line_map;
	char	**map_grid;
	int		i;
	int		len;

	first_line_map = first_line_of_map(cub);
	if (!first_line_map)
		return (1);
	map_grid = &(cub->file->file_grid[first_line_map]);
	cub->map->map_width = 0;
	i = 0;
	while (map_grid[i])
	{
		len = ft_strlen(map_grid[i]);
		if (len > cub->map->map_width)
			cub->map->map_width = len;
		i++;
	}
	cub->map->map_height = i;
	if (cub->map->map_height < 3 || cub->map->map_width < 3)
		return (2);
	return (0);
}

int	check_texture_number(char *identifier, t_cub *cub3D, int option)
{
	char	*first;

	if (!cub3D || !(cub3D->file->cub_file))
		return (1);
	first = ft_strnstr(cub3D->file->cub_file, identifier,
			cub3D->file->file_len);
	while (first && first != cub3D->file->cub_file && *(first - 1) != '\n')
		first = ft_strnstr(first + option, identifier, cub3D->file->file_len);
	if (!first)
	{
		ft_dprintf(2, "Error\nYou need 1 %stexture\n", identifier);
		return (2);
	}
	if (ft_strnstr(first + option, identifier, cub3D->file->file_len))
	{
		ft_dprintf(2, "Error\nToo many %stextures\n", identifier);
		return (3);
	}
	return (0);
}

void	set_texture_pointers(t_cub *cub3D, char **dir_pointer,
char *ID, int max_free)
{
	char		*pos;
	int			i;
	int			len;
	int			j;

	len = ft_strlen(ID);
	pos = ft_strnstr(cub3D->file->cub_file, ID, cub3D->file->file_len);
	i = 0;
	while (pos && pos[i] && pos[i] != '\n')
		i++;
	while (pos[i] == '\n' || pos[i] == ' ')
		i--;
	j = 0;
	while ((pos + len)[j] == ' ')
		j++;
	*dir_pointer = ft_substr(pos, len + j, i - len - j + 1);
	if (!(*dir_pointer))
	{
		free_all(cub3D, 1, max_free);
		exit (EXIT_FAILURE);
	}
}

int	check_textures_valid(t_cub *cub, char *ID)
{
	int		i;
	char	*pos;
	char	**values;

	i = 0;
	while (cub->file->file_grid[i])
	{
		if (ft_strnstr(cub->file->file_grid[i], ID,
				ft_strlen(cub->file->file_grid[i])) == cub->file->file_grid[i])
		pos = ft_strnstr(cub->file->file_grid[i], ID,
					ft_strlen(cub->file->file_grid[i])) + 2;
		i++;
	}
	values = ft_split(pos, ',');
	if (!values)
		return (1);
	if (check_rgb_valid(cub, ID, values))
		return (free_all(cub, 1, 4), 1);
	free_tab(values);
	return (0);
}

int	check_rgb_valid(t_cub *cub, char *ID, char **values)
{
	int		i;
	int		n;

	if (tab_size(values) != 3)
	{
		free_tab(values);
		return (ft_dprintf(2, "Error\n3 RGB codes required\n"), 2);
	}
	i = 0;
	while (i < 3 && values[i])
	{
		n = ft_atoi(values[i]);
		if ((!n && char_not_zero(values[i]))
			|| n < 0 || n > 255)
		{
			free_tab(values);
			return (ft_dprintf(2, "Error\nRGB codes invalid\n"), 2);
		}
		if (!ft_strncmp(ID, "C ", 10))
			(cub->textures->ceiling)[i] = n;
		if (!ft_strncmp(ID, "F ", 10))
			(cub->textures->floor)[i] = n;
		i++;
	}
	return (0);
}
