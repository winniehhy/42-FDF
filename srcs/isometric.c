/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:21:01 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:21:01 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/**
 * @brief Converts the given coordinates to an isometric projection.
 *
 * This function checks if the isometric field of the vars structure is set.
 * If it is, it converts the given x and y coordinates to an isometric
 * projection using the given z coordinate. The conversion is done in-place,
 * meaning the original coordinates are modified.
 *
 * pi/6 = 0.52359877559
 *
 * @param vars A pointer to a t_display structure that contains display
 * settings. The isometric field of this structure
 * determines whether the conversion is performed.
 * @param x A pointer to the x coordinate to be converted.
 * @param y A pointer to the y coordinate to be converted.
 * @param z The z coordinate used in the conversion.
 */
void	isometric(t_data *fdf, int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	if (!fdf->isometric)
		return ;
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.52359877559);
	*y = -z + (prev_x + prev_y) * sin(0.52359877559);
}
