/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:18:39 by hemottu           #+#    #+#             */
/*   Updated: 2024/02/02 16:31:18 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_BONUS_H
# define PROTOTYPES_BONUS_H
# include <stdbool.h>

typedef struct s_cub	t_cub;
typedef struct s_file	t_file;
typedef struct s_tex	t_tex;
typedef struct s_img	t_img;

/*INIT*/
int		set_first_position(t_cub *cub3D, bool player_exists, int x, int y);
int		init_textures(t_cub *cub3D);
int		init_cub3d(t_cub *cub);
int		init_colors(t_cub *cub);
int		init_gradient_value(t_cub *cub);
int		init_pointers(t_cub *cub, t_file *file,
			t_tex *textures, char *filename);
void	set_index(t_cub *cub);

/*ERRORS GENERAL*/
int		check_errors(t_cub *cub3D);
int		ft_check_file_ext(char *s);
int		check_file_pollution(t_cub *cub3D);

/*PARSING UTILS*/
int		set_map_dimensions(t_cub *cub);
int		close_fd_perror(int fd, char *error_msg, int return_code);
int		count_chars_in_file(char *filename);
int		copy_file(t_cub *cub3D);
int		in_charset(int c, const char *charset);
int		check_line_valid(char *line);
int		first_line_of_map(t_cub *cub3D);
char	*last_char_of_map(t_cub *cub3D);
int		char_not_zero(char *n);
int		tab_size(char **tab);
char	**copy_grid(char **original, int len);
int		set_len_for_nl(t_cub *cub, char *file);
int		nl(t_cub *cub);
int		all_whitespace(char	*str, int c);

/*MAP CHECKS*/
int		check_map_printable(char *filename, int i);
int		map_is_last(t_cub *cub3D);
int		map_has_nl(t_cub *cub3D);
int		map_enclosed(t_cub *cub3D);
int		floodfill(t_cub *cub);
void	erase_outside_map(t_cub *cub, char **grid_copy);
int		wrong_neighbour(char **grid, int y, int x, char *charset);

/*TEXTURES*/
int		check_texture_number(char *identifier, t_cub *cub3D, int option);
void	set_texture_pointers(t_cub *cub3D, char **dir_pointer,
			char *ID, int max_free);
int		check_textures_valid(t_cub *cub3D, char *ID);
int		check_rgb_valid(t_cub *cub, char *ID, char **values);
int		check_texture_path(t_cub *cub);

/*FREES AND EXIT*/
void	free_all(t_cub *cub3D, int level, int directions);
void	free_tex_imgs(t_cub *cub);
void	free_tab(char **tab);

/*WINDOW*/
void	create_window(t_cub *cub3D);
int		close_window(t_cub *cub3D);

/*DRAW*/
int		loop(t_cub *cub3D);
void	draw_img(t_cub *cub);
void	draw_background(t_cub *cub3D);
void	draw_minimap(t_cub *cub3D);
void	draw_tile(t_cub *cub, int canvas_x, int canvas_y, int color);
void	set_pixelrgb(t_cub *cub, int index, const int *value);
int		pix_index(t_cub *cub, int x, int y);
void	draw_player(t_cub *cub, int color);
void	draw_pixcolumn(t_cub *cub, int x, int y0, int y1);
void	draw_walls(t_cub *cub);
void	texture_to_img(t_cub *cub, int x, int wall_start, int wall_end);
void	ft_put_pixel(t_img *canvas, int x, int y, t_img *img);
void	ft_get_pixel(t_img *img, int x, int y);
int		is_pixel_white(t_cub *cub, int index);

/*SIGNALS*/
int		handle_keypress(int keysym, t_cub *cub);
int		handle_keyrelease(int keysym, t_cub *cub3D);

/*MOVES*/
void	move_player(t_cub *cub, int keysym);
int		check_if_wall(t_cub *cub, double x, double y);

/*RAYCASTING*/
void	calculate_rays(t_cub *cub, int x, int hit);
void	draw_raycast(t_cub *cub);

/*ROTATE*/
void	rotate(t_cub *cub, int keysym);
#endif