/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:30:23 by pichatte          #+#    #+#             */
/*   Updated: 2024/02/02 17:39:19 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

int	ft_check_file_ext(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (ft_strncmp(s + len - 4, ".cub", 4) != 0)
	{
		ft_dprintf(2, "Error\nYou must have a .cub file\n");
		return (1);
	}
	else
		return (0);
}

int	close_fd_perror(int fd, char *error_msg, int return_code)
{
	if (close (fd) == -1)
	{
		perror ("Error\nClose");
		return (1);
	}
	if (return_code)
		ft_dprintf(2, error_msg);
	return (return_code);
}

int	count_chars_in_file(char *filename)
{
	int		fd;
	char	buffer[100];
	int		bytes_read;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes_read = 1;
	i = 0;
	j = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer + i, 1);
		if (bytes_read == -1)
			return (close_fd_perror(fd, "Error\nRead error\n", -2));
		i += bytes_read;
		if (i == 99)
		{
			j += i;
			i = 0;
		}
	}
	return (close(fd), j + i);
}

int	copy_file(t_cub *cub3D)
{
	int	bytes_read;
	int	fd;

	cub3D->file->file_len = count_chars_in_file(cub3D->file->filename);
	cub3D->file->cub_file = (char *)ft_calloc(sizeof(char),
			cub3D->file->file_len + 1);
	if (!(cub3D->file->cub_file))
	{
		perror("Error\nMalloc");
		exit(EXIT_FAILURE);
	}
	fd = open(cub3D->file->filename, O_RDONLY);
	if (fd == -1)
		return (perror("Error\nOpen"), free(cub3D->file->cub_file), -1);
	bytes_read = read(fd, cub3D->file->cub_file, cub3D->file->file_len);
	cub3D->file->cub_file[cub3D->file->file_len] = 0;
	close(fd);
	if (bytes_read == -1)
		return (perror("Error\nRead"), free(cub3D->file->cub_file), -2);
	return (0);
}

int	check_file_pollution(t_cub *cub3D)
{
	int	i;

	if (!cub3D || !(cub3D->file) || !(cub3D->file->cub_file))
		return (1);
	cub3D->file->file_grid = ft_split(cub3D->file->cub_file, '\n');
	if (!cub3D->file->file_grid)
	{
		perror("Error\nMalloc");
		free(cub3D->file->cub_file);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (cub3D->file->file_grid[i])
	{
		if (!check_line_valid(cub3D->file->file_grid[i]))
		{
			free_all(cub3D, 0, 0);
			return (ft_dprintf(2, "Error\nInvalid .cub file\n"), 1);
		}
		i++;
	}
	return (0);
}
