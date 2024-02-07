/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:30:13 by pichatte          #+#    #+#             */
/*   Updated: 2024/02/02 19:48:24 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

int	check_map_printable(char *filename, int i)
{
	char	buffer[100];
	int		fd;
	int		bytes_read;

	fd = open(filename, __O_DIRECTORY);
	if (fd != -1)
		return (close(fd), ft_dprintf(2, "Error\n%s is dir\n", filename), 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("Error\nOpen"), -1);
	ft_bzero(buffer, 100);
	bytes_read = 1;
	i = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer + i, 1);
		if (bytes_read <= -1)
			return (close_fd_perror(fd, "Error\nRead\n", -2));
		if (!in_charset(buffer[i], "\t\n\f\v\r\n") && !ft_isprint(buffer[i]))
			return (close_fd_perror(fd, "Error\nMap is not printable\n", 2));
		i++;
		if (i == 99)
			i = 0;
	}
	return (close_fd_perror(fd, "", 0));
}

int	map_is_last(t_cub *cub3D)
{
	int		len;
	char	*charset_last;
	int		last_line;

	last_line = 1;
	charset_last = "1 0\n";
	len = cub3D->file->file_len;
	while (in_charset(cub3D->file->cub_file[len - 1], " \t\n\f\v\r\n"))
		len--;
	while (len - 1 && last_line)
	{
		if (!in_charset(cub3D->file->cub_file[len - 1], charset_last))
			return (ft_dprintf(2, "Error\nMap is not last or invalid\n"), 0);
		if (cub3D->file->cub_file[len - 1] == '\n')
			last_line = 0;
		len--;
	}
	return (1);
}

int	map_has_nl(t_cub *cub3D)
{
	int			first_line;
	const char	*charset = "10 ";

	if (nl(cub3D))
		return (1);
	first_line = first_line_of_map(cub3D);
	if (!first_line)
		return (ft_dprintf(2, "Error\nClosed map not found\n"), 2);
	while (cub3D->file->file_grid[first_line])
	{
		if (!in_charset(cub3D->file->file_grid[first_line][0], charset))
			return (ft_dprintf(2, "Error\nInvalid map\n"), 3);
		first_line++;
	}
	return (0);
}

int	first_line_index(char *file)
{
	int			i;
	const char	*charset = "1 ";
	int			j;

	i = 0;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			j = i + 1;
			while (in_charset(file[j], charset))
				j++;
			if (file[j] == '\n' && j != i + 1
				&& !all_whitespace(file + i + 1, '\n'))
				break ;
		}
		i++;
	}
	if (!file[i])
		return (0);
	return (i + 1);
}

int	nl(t_cub *cub)
{
	char		*file;
	int			len;
	int			i;

	file = cub->file->cub_file;
	i = first_line_index(file);
	if (!i)
		return (ft_dprintf(2, "Error\nClosed map not found\n"), 1);
	len = set_len_for_nl(cub, file);
	while (len && len != i)
	{
		if ((file[len] == '\n' && len - 1 && file[len - 1] == '\n')
			|| (len - 1 && file[len - 1] == '\n'
				&& all_whitespace(file + len, '\n')))
			return (ft_dprintf(2, "Error\nNewline in map\n"), 2);
		len--;
	}
	return (0);
}
