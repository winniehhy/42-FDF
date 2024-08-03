/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:49:02 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:49:02 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_map    t_map;
typedef struct s_img    t_img;
typedef struct s_data   t_data;
typedef struct s_point  t_point;

/**
 * A structure representing a point in 3D space with color.
 *
 * Member 'x' represents the x-coordinate of the point.
 * Member 'y' represents the y-coordinate of the point.
 * Member 'z' represents the z-coordinate of the point.
 * Member 'color' is an integer representing the color of the point.
 */
typedef struct s_point
{
    int x;
    int y;
    int z;
    int color;
} t_point;

/**
 * A structure representing a 3D map.
 *
 * Member 'width' represents the width of the map.
 * Member 'height' represents the height of the map.
 * Member 'z_2d' is a 2D array representing the
  z-coordinates of the points on the map.
 * Member 'colors' is a 2D array representing the 
   colors of the points on the map.
 * Member 'min_z' is the minimum z-coordinate in the map.
 * Member 'max_z' is the maximum z-coordinate in the map.
 * Member 'iscolor' is a flag indicating whether color information is present in the map.
 */
typedef struct s_map
{
    int width;
    int height;
    int **z_2d;
    int **colors;
    int min_z;
    int max_z;
    int iscolor;
} t_map;

/**
 * A structure representing image data.
 *
 * Member 'img' is a pointer to the image object.
 * Member 'addr', address, is a pointer to the image data.
 * Member 'bpp' stands for bits per pixel, indicating the color depth of the image.
 * Member 'ln_len' represents the size of a line in the image data.
 * Member 'endian' indicates the byte order of the pixel color data. It can be either 0 (big endian) or 1 (little endian).
 */
typedef struct s_img
{
    void *img;
    char *addr;
    int bpp;
    int ln_len;
    int endian;
} t_img;

/**
 * A structure representing display parameters.
 *
 * Member 'mlx' is a pointer to the mlx instance.
 * Member 'win' is a pointer to the window object.
 * Member 'map' is a pointer to the map data.
 * Member 'img' is a pointer to the image data.
 * Member 'shift_x' represents the horizontal shift of the display.
 * Member 'shift_y' represents the vertical shift of the display.
 * Member 'rot_x' represents the rotation around the x-axis.
 * Member 'rot_y' represents the rotation around the y-axis.
 * Member 'rot_z' represents the rotation around the z-axis.
 * Member 'zoom' represents the zoom level of the display.
 * Member 'isometric' is a flag indicating whether the display is in isometric view.
 * Member 'ff' stands for flattening factor, controlling the flattening of the display.
 * Member 'color_change' represents the color change flag.
 */
typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_map   *map;
    t_img   *img;
    int     shift_x;
    int     shift_y;
    float   rot_x;
    float   rot_y;
    float   rot_z;
    float   zoom;
    int     isometric;
    float   ff;
    int     color_change;
} t_data;
