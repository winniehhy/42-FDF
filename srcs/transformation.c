/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:21:46 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:21:46 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

/**
 * @brief Applies a series of transformations to a point.
 *
 * This function applies a series of transformations to the
 * x, y, and z coordinates of the point given as a parameter.
 * The order of transformation goes like this:
 *
 * 		Scaling -> Rotation -> Translation
 *
 * The z coordinate is scaled by a smaller factor than the x and y
 * coordinates to reduce its impact on the final position of the point.
 *
 * The combined effect of these transformations is achieved by applying
 * them sequentially to each point in the landscape. The order in which
 * these transformations are applied can affect the final result, as
 * matrix multiplication is not commutative.
 *
 * @param fdf A pointer to a t_data structure that contains the display
 * variables and the transformation parameters.
 * @param point The point to which the transformations are applied.
 * @return The transformed point.
 */
t_point	transform_point(t_data *fdf, t_point point)
{
	point.x *= fdf->zoom;
	point.y *= fdf->zoom;
	point.z *= (fdf->zoom / SF) * fdf->ff;
	rot_x(fdf, &point.y, &point.z);
	rot_y(fdf, &point.x, &point.z);
	rot_z(fdf, &point.x, &point.y);
	isometric(fdf, &point.x, &point.y, point.z);
	point.x += fdf->shift_x;
	point.y += fdf->shift_y;
	return (point);
}

/**
 * @brief Creates a new point with the given x and y coordinates and
 * the corresponding z coordinate and color from the map.
 *
 * This function creates a new point with the given x and y coordinates.
 * It sets the z coordinate of the point to the corresponding
 * value from the map's z_2d array. If the map has color data, it sets the
 * color of the point to the corresponding value from the
 * map's colors array. Otherwise, it calculates the color based on the z
 * coordinate.
 *
 * @param x The x coordinate of the new point.
 * @param y The y coordinate of the new point.
 * @param fdf A pointer to a t_data structure that contains the display
 * variables and the map data.
 * @return The new point.
 */
t_point	create_new_point(int x, int y, t_data *fdf)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = fdf->map->z_2d[y][x];
	if (fdf->map->iscolor)
		point.color = fdf->map->colors[y][x];
	else
		point.color = calc_z_color(fdf, point.z);
	return (point);
}
