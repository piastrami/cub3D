/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:53:31 by pichatte          #+#    #+#             */
/*   Updated: 2024/02/02 16:42:41 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	tab_size(char **tab)
{
	int	i;

	if (!tab)
		return (-1);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**copy_grid(char **original, int len)
{
	char	**copy;
	int		size;
	int		i;

	size = tab_size(original);
	copy = ft_calloc(sizeof(char *), size + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = ft_calloc(sizeof(char), len + 1);
		if (!copy[i])
		{
			free_tab(copy);
			return (NULL);
		}
		ft_strlcpy(copy[i], original[i], len + 1);
		i++;
	}
	return (copy);
}

int	wrong_neighbour(char **grid, int y, int x, char *charset)
{
	if (in_charset (grid[y][x + 1], charset)
		&& (x > 0 && in_charset (grid[y][x - 1], charset))
		&& (grid[y + 1] && in_charset (grid[y + 1][x], charset))
		&& (y > 0 && in_charset (grid[y - 1][x], charset)))
		return (0);
	return (1);
}

int	set_len_for_nl(t_cub *cub, char *file)
{
	int	len;

	len = cub->file->file_len - 1;
	while ((len && file[len] == '\n')
		|| (len && all_whitespace(file + len, '\n')))
		len--;
	return (len);
}

int	all_whitespace(char	*str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		if (str[i] < 9 || (str[i] > 13 && str[i] != ' '))
			return (0);
		i++;
	}
	return (1);
}
