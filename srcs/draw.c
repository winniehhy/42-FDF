/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:20:28 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:20:28 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

/**
 * @brief Draws the map with transformations applied to each point.
 *
 * This function first clears the image buffer. If the zoom factor is not zero,
 * it iterates over each point in the map.
 *
 * For each point, it applies a series of transformations and then draws a line
 * to the next point in the same row and the same column using the Bresenham's
 * line algorithm.
 * 
 * After all points have been processed, it puts the image to the window and
 * draws the menu on top of it.
 *
 * @param fdf A pointer to a t_display structure that contains parameters
 * to draw the map
 */
void	draw_map(t_data *fdf)
{
	int	x;
	int	y;

	ft_bzero(fdf->img->addr, W_WIDTH * W_HEIGHT * (fdf->img->bpp / 8));
	if (fdf->zoom)
	{
		y = -1;
		while (++y < fdf->map->height)
		{
			x = -1;
			while (++x < fdf->map->width)
			{
				if (x < fdf->map->width - 1)
					bresenham(fdf,
						transform_point(fdf, create_new_point(x, y, fdf)),
						transform_point(fdf, create_new_point(x + 1, y, fdf)));
				if (y < fdf->map->height - 1)
					bresenham(fdf,
						transform_point(fdf, create_new_point(x, y, fdf)),
						transform_point(fdf, create_new_point(x, y + 1, fdf)));
			}
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	draw_control_menu(fdf);
}

/**
 * @brief Puts a pixel onto the image.
 *
 * This function puts a pixel at the specified (x, y) coordinates in the image.
 * The color of the pixel is specified by the 'color' parameter. The function
 * stores the color value based off of the endianness of the system
 *
 * @param fdf A pointer to a t_display structure containing image data
 * information.
 * 
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color of the pixel.
 */
void	put_pixel_to_img(t_data *fdf, int x, int y, int color)
{
	int	pixel;

	if (x >= W_WIDTH || y >= W_HEIGHT || x < 0 || y < 0)
		return ;
	pixel = (y * fdf->img->ln_len) + (x * (fdf->img->bpp / 8));
	if (fdf->img->endian == 1)
	{
		fdf->img->addr[pixel + 0] = (color >> AS);
		fdf->img->addr[pixel + 1] = (color >> RS) & BM;
		fdf->img->addr[pixel + 2] = (color >> GS) & BM;
		fdf->img->addr[pixel + 3] = (color) & BM;
	}
	else if (fdf->img->endian == 0)
	{
		fdf->img->addr[pixel + 0] = (color) & BM;
		fdf->img->addr[pixel + 1] = (color >> GS) & BM;
		fdf->img->addr[pixel + 2] = (color >> RS) & BM;
		fdf->img->addr[pixel + 3] = (color >> AS);
	}
}

/**
 * @brief Draws a menu onto the windows displaying the control
 * keys and information.
 *
 * This function uses the mlx_string_put function to draw a menu containing
 * the control information on the window. The control information includes
 * the keys to press to perform various actions, such as resetting the view,
 * moving the view, zooming in and out, changing the
 * flattening factor, rotating the view, changing the perspective, and closing
 * the application.
 *
 * @param fdf A pointer to a t_display structure that contains the display
 * variables, including the MiniLibX connection and the window.
 */
void	draw_control_menu(t_data *fdf)
{
	void	*mlx;
	void	*win;
	int		vp;

	mlx = fdf->mlx;
	win = fdf->win;
	vp = 20;
	mlx_string_put(mlx, win, 25, vp += 30, WHITE, "CONSTROLS:");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'R' : RESET");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'W' : MOVE DOWN");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'A' : MOVE RIGHT");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'D' : MOVE LEFT");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'C' : CHANGE COLOR");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'+'/'-' : ZOOM IN/OUT");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'UP'/'DOWN' : FLATTEN");
	mlx_string_put(mlx, win, 25, vp += 30, WHITE, "ROTATE VIEW:");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'1'/'2' : X-AXIS");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'3'/'4' : Y-AXIS");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'5'/'6' : Z-AXIS");
	mlx_string_put(mlx, win, 25, vp += 30, WHITE, "TOGGLE PERSPECTIVE:");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'TAB' :  ISOMETRIC/PARALLEL");
	mlx_string_put(mlx, win, 25, vp += 30, WHITE, "EXIT:");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'ESC'/'(X)' : CLOSE WINDOW");
}
