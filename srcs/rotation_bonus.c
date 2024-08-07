/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:21:41 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:21:41 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/**
 * @brief Rotates a point around the x-axis.
 *
 * This function performs a rotation transformation matrix
 * onto a given point and rotates the point around
 * the x-axis by an angle specified inthe fdf structure.
 * The rotation is done in-place, meaning the original y
 * and z coordinates are modified.
 *
 * The following transformation matrix is applied:
 * | 1  0      0      |
 * | 0  cos(θ) -sin(θ)|
 * | 0  sin(θ)  cos(θ)|
 *
 * @param fdf A pointer to a t_data structure that contains the
 * rotation angle.
 * @param y A pointer to the y coordinate of the point.
 * @param z A pointer to the z coordinate of the point.
 */
void	rot_x(t_data *fdf, int *y, int *z)
{
	float	prev_y;

	prev_y = *y;
	*y = (prev_y * cos(fdf->rot_x)) + (*z * sin(fdf->rot_x));
	*z = (-prev_y * sin(fdf->rot_x)) + (*z * cos(fdf->rot_x));
}

/**
 * @brief Rotates a point around the y-axis.
 *
 * This function performs a rotation transformation matrix
 * onto a given point and rotates the point around
 * the y-axis by an angle specified inthe fdf structure.
 * The rotation is done in-place, meaning the original x
 * and z coordinates are modified.
 *
 * The following transformation matrix is applied:
 * | cos(θ)  0  sin(θ)|
 * | 0       1  0     |
 * |-sin(θ)  0  cos(θ)|
 *
 * @param fdf A pointer to a t_data structure that contains the
 * rotation angle.
 * @param x A pointer to the x coordinate of the point.
 * @param z A pointer to the z coordinate of the point.
 */
void	rot_y(t_data *fdf, int *x, int *z)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos(fdf->rot_y)) + (*z * sin(fdf->rot_y));
	*z = (-prev_x * sin(fdf->rot_y)) + (*z * cos(fdf->rot_y));
}

/**
 * @brief Rotates a point around the z-axis.
 *
 * This function performs a rotation transformation matrix
 * onto a given point and rotates the point around
 * the z-axis by an angle specified inthe fdf structure.
 * The rotation is done in-place, meaning the original x
 * and y coordinates are modified.
 *
 * The following transformation matrix is applied:
 * | cos(θ) -sin(θ) 0|
 * | sin(θ)  cos(θ) 0|
 * | 0       0      1|
 *
 * @param fdf A pointer to a t_data structure that contains the
 * rotation angle.
 * @param x A pointer to the x coordinate of the point.
 * @param y A pointer to the y coordinate of the point.
 */
void	rot_z(t_data *fdf, int *x, int *y)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos(fdf->rot_z)) - (*y * sin(fdf->rot_z));
	*y = (prev_x * sin(fdf->rot_z)) + (*y * cos(fdf->rot_z));
}
/*
 The rotations are performed in-place to optimize memory usage and
 avoid creating temporary variables or structures to hold the rotated
 coordinates. By modifying the original coordinates directly, the functions
 can work with the existing data structures without the need for additional
 memory allocations or copies.
*/