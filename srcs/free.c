/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:20:42 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:20:42 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

/**
 * @brief Allocates memory for members in the `map` structure.
 *
 * This function allocates memory for the fields `z_2d` and `colors` in
 * the t_map structure. It creates a two-dimensional integer arrays to
 * store z-values of the map based on the map's size.
 * It also does error checking and handling for unsuccessful memory allocation.
 *
 * @param map A pointer to a t_map structure that contains the map data.
 */
void	alloc_map_mem(t_map *map)
{
	int	i;

	map->z_2d = ft_calloc(map->height, sizeof(int *));
	map->colors = ft_calloc(map->height, sizeof(int *));
	if (!map->z_2d || !map->colors)
	{
		free_map_mem(map);
		exit_err(MEM_ALLOC_ERROR);
	}
	i = -1;
	while (++i < map->height)
	{
		map->z_2d[i] = ft_calloc(map->width, sizeof(int));
		map->colors[i] = ft_calloc(map->width, sizeof(int));
		if (!map->z_2d[i] || !map->colors[i])
		{
			free_map_mem(map);
			exit_err(MEM_ALLOC_ERROR);
		}
	}
}

/**
 * @brief Frees the memory allocated for members in the `map` structure.
 *
 * This function frees the memory allocated integer array for the fields
 * `z_2d` and `colors` in the t_map structure. It also frees the memory
 * allocated for the t_map structure itself.
 *
 * @param map A pointer to a t_map structure that contains the map data.
 */
void	free_map_mem(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->z_2d)
	{
		i = -1;
		while (++i < map->height && map->z_2d[i])
			free(map->z_2d[i]);
		free(map->z_2d);
	}
	if (map->colors)
	{
		i = -1;
		while (++i < map->height && map->colors[i])
			free(map->colors[i]);
		free(map->colors);
	}
	free(map);
}

/**
 * @brief Frees the memory allocated from the return value of `ft_split`
 *
 * This function frees an array of strings by iterating
 * over each string until it encounters the last NULL pointer.
 *
 * @param split an array of memory allocated strings.
 */
void	free_split(char **split)
{
	int	j;

	j = 0;
	while (split[j])
		free(split[j++]);
	free(split);
}

/**
 * @brief Closes the window, frees the associated resources, and
 * exits the program successfully.
 *
 * This function frees the mlx resources stored within the display variables,
 * prints a message to the console to indicate the program ran successsfully,
 * and then exits the program with a success status code. It closes all
 * mlx-related resources and is the last event called in the mlx event loop.
 *
 * @param fdf A pointer to a t_data structure that contains the display
 * variables.
 *
 * @return Always returns 0.
 */
int	close_window(t_data *fdf)
{
	if (!fdf)
		return (MEM_ALLOC_ERROR);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	if (fdf->img)
		free(fdf->img);
	free_map_mem(fdf->map);
	free(fdf->mlx);
	free(fdf);
	exit_err(SUCCESS);
	return (SUCCESS);
}
