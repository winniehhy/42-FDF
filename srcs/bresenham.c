/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:20:11 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:20:11 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

/**
 * @brief Initializes the parameters for the Bresenham line algorithm.
 *
 * This function calculates the absolute differences between the x and y
 * coordinates of the start and end points,
 * and sets the sign of the x and y directions based on the relative positions
 * of the start and end points.
 *
 * @param start The start point of the line.
 * @param end The end point of the line.
 * @param delta The absolute differences in the x and y coordinates
 * between the start and end points.
 * @param sign The signs of the x and y directions.
 */
void	init_bresenham_param(t_point *start, t_point *end,
	t_point *delta, t_point *sign)
{
	delta->x = ft_abs(end->x - start->x);
	delta->y = -ft_abs(end->y - start->y);
	sign->x = -1;
	sign->y = -1;
	if (start->x < end->x)
		sign->x = 1;
	if (start->y < end->y)
		sign->y = 1;
}

/**
 * @brief Draws a line using the Bresenham line algorithm.
 *
 * This function initializes the parameters for the Bresenham line algorithm,
 * then iterates over the points on the line,
 * drawing each one using the `put_pixel_to_img` function and updating the
 * current point and line error as it goes.
 *
 * @param fdf The display variables.
 * @param start The start point of the line.
 * @param end The end point of the line.
 */
void	bresenham(t_data *fdf, t_point start, t_point end)
{
	t_point	c;
	t_point	sign;
	t_point	delta;
	int		line;
	int		tmp;

	init_bresenham_param(&start, &end, &delta, &sign);
	line = delta.x + delta.y;
	c = start;
	while (c.x != end.x || c.y != end.y)
	{
		put_pixel_to_img(fdf, c.x, c.y, calc_color(c, start, end, delta));
		tmp = line * 2;
		if (tmp > delta.y)
		{
			line += delta.y;
			c.x += sign.x;
		}
		if (tmp < delta.x)
		{
			line += delta.x;
			c.y += sign.y;
		}
	}
}
