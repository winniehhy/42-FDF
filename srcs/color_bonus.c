/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:20:18 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:20:18 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Calculates the percentage of a value within a range.
 *
 * This function calculates the relative position of a value within a specified
 * range, expressed as a percentage. The percentage is calculated as follows:
 * (current value - start of range) / (end of range - start of range).
 * If the range is zero (i.e., the start and end are the same), the function
 * returns 1.0.
 *
 * @param start The start of the range.
 * @param end The end of the range.
 * @param value The current value for which the percentage within the range is to
 * be calculated.
 * @return The percentage of the current value within the range, expressed as a
 * double. If the range is zero, the function returns 1.0.
 */
double	calc_percentage(int start, int end, int value)
{
	double	range;
	double	position;

	range = end - start;
	position = value - start;
	if (!range)
		return (1.0);
	return (position / range);
}

/**
 * @brief Calculates the light intensity based on the start, end, and
 * percentage.
 *
 * This function calculates the light intensity based on the start intensity,
 * end intensity, and the percentage.
 * The formula used is: (1 - percentage) * start + percentage * end.
 *
 * @param start The start intensity.
 * @param end The end intensity.
 * @param percentage The percentage.
 * @return The calculated light intensity.
 */
int	calc_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

/**
 * @brief Calculates interpolated color based on the current, start,
 * end pointsand the delta.
 *
 * This function uses linear interpolation to calculate an intermediate
 * color value of the current point based on the color of the start and
 * end point. First, it checks if the color of the current point is the
 * same as the end point, if so, it returns the current color. Then it
 * calculates the percentage based on the larger delta (x or y). Finally,
 * it calculates the red, green, and blue components of the color using
 * the `calc_light` function and the percentage, and combines them
 * into a single color.
 *
 * Colors are stored in the following hex format:
 * 0 x | F F | F F   | F F  |
 *     | red | green | blue |
 *
 * So what we can do is mask and isolate each color channel using bit shifting
 * and perform linear interpolation on each channel before recombining.
 * Each channel is 8 bits.
 *
 * @param current The current point.
 * @param start The start point.
 * @param end The end point.
 * @param delta The delta.
 * @return The calculated color.
 */
int	calc_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = calc_percentage(start.x, end.x, current.x);
	else
		percentage = calc_percentage(start.y, end.y, current.y);
	r = calc_light((start.color >> RS) & BM, (end.color >> RS) & BM,
			percentage);
	g = calc_light((start.color >> GS) & BM, (end.color >> GS) & BM,
			percentage);
	b = calc_light(start.color & BM, end.color & BM, percentage);
	return ((r << RS) | (g << GS) | b);
}

/**
 * @brief Calculates the gradient color based on the current z value.
 *
 * This function calculates the gradient color based on the current z value.
 * It first calculates the percentage of the current z value within the range of
 * z values in the map. Then it returns a color based on the percentage.
 *
 * @param fdf The display variables.
 * @param height The current z value.
 * @return The calculated gradient color.
 */
int	calc_z_color(t_data *fdf, int height)
{
	double	percentage;

	percentage = calc_percentage(fdf->map->min_z, fdf->map->max_z, height);
	if (fdf->color_change)
	{
		if (percentage < 0.7)
			return (WHITE);
		else
			return (N_BLUE);
	}
	else
	{
		if (percentage < 0.1)
			return (N_ORANGE);
		else if (percentage < 0.5)
			return (N_PINK);
		else if (percentage < 0.7)
			return (WHITE);
		else
			return (N_YELLOW);
	}
}

void	change_color(t_data *fdf)
{
	fdf->color_change =!fdf->color_change;
}
