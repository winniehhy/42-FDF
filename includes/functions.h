/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:44:47 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:44:47 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*======================== BRESENHAM.C ===================================*/

void	init_bresenham_param(t_point *start, t_point *end,
			t_point *delta, t_point *sign);
void	bresenham(t_data *fdf, t_point start, t_point end);

/*========================= COLOR.C =====================================*/

double	calc_percentage(int start, int end, int cval);
int		calc_light(int start, int end, double percentage);
int		calc_color(t_point current, t_point start, t_point end, t_point delta);
int		calc_z_color(t_data *fdf, int cz);
void	change_color(t_data *fdf);

/*======================== DRAW.C ======================================*/

void	draw_map(t_data *fdf);
void	put_pixel_to_img(t_data *fdf, int x, int y, int color);
void	draw_control_menu(t_data *fdf);

/*========================= ERROR.C =====================================*/

void	exit_err(int exit_status);
void	exit_perr(const char *error_message);

/*======================= FREE.C ======================================*/

void	alloc_map_mem(t_map *map);
void	free_map_mem(t_map *map);
void	free_split(char **split);
int		close_window(t_data *fdf);

/*====================== INIT_DATA.C ==================================*/

t_data	*init_data(t_map *map);
void	reset_default(t_data *fdf);

/*======================= INIT_MAP.C ===================================*/

t_map	*init_map(char *file);

/*======================= KEYS.C ======================================*/

int		handle_keypress(int keycode, t_data *data);
void	adjust_rot(int keycode, t_data *fdf);

/*====================== MLX_MAIN.C ===================================*/

void	init_mlx(t_data *fdf);
void	begin_mlx(t_map *map);

/*======================== PARSE_MAP.C ==================================*/

void	parse_map_size(int fd, t_map *map);
void	parse_map_mem(int fd, t_map *map);

/*===================== PARSE_UTILS.C =================================*/

int		find_width(char **split);
int		calc_z_value(int z, t_map *map);
int		convert_hex_color(char *color, t_map *map);

/*===================== ROTATION.C ===================================*/

void	rot_x(t_data *fdf, int *y, int *z);
void	rot_y(t_data *fdf, int *x, int *z);
void	rot_z(t_data *fdf, int *x, int *y);

/*====================== TRANSFORMATION.C ===============================*/

t_point	transform_point(t_data *fdf, t_point point);
t_point	create_new_point(int x, int y, t_data *fdf);

/*==================== TRANSLATION.C =================================*/

void	adjust_trans(int keycode, t_data *fdf);

/*===================== ZOOM.C ======================================*/

void	adjust_zoom(int keycode, t_data *fdf);

/*=================== ALTITUDE.C ===================================*/

void	adjust_alt(int keycode, t_data *fdf);

/*==================== ISOMETRIC.C ===================================*/

void	isometric(t_data *fdf, int *x, int *y, int z);
