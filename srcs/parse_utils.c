/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:21:33 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:21:33 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

/**
 * @brief Calculates the width based on the tokens of z-values in a row
 *
 * This function first checks if the the map given was empty based on
 * the return value of `ft_split`. If it's a valid map, it will go on
 * to count the number z-value strings, which is the map's width.
 *
 * @param split An array storing z-values as strings
 * @return The width of the map
 */
int	find_width(char **split)
{
	int	i;

	if (!split)
		exit_err(MAP_EMPTY_ERROR);
	if (!*split)
		exit_err(MAP_EMPTY_ERROR);
	i = 0;
	while (split[i])
		i++;
	free_split(split);
	return (i);
}

/**
 * @brief Parse the hexadecimal color string and updates the `iscolor` flag
 *
 * @param map A pointer to the map data structure.
 * @param cs A pointer to the color string to be parsed. This should be a string
 * representing a color in hexadecimal format.
 * @return The parsed color as an integer. If the color string does not start
 * with 'x', the function returns the default color (WHITE).
 */
int	convert_hex_color(char *color, t_map *map)
{
	while (ft_isdigit(*color) || *color == '-'
		|| *color == '+' || *color == ',')
		color++;
	if (*color && *color == 'x')
	{
		map->iscolor = 1;
		color++;
		return (ft_atoi_base(color, HEX_BASE));
	}
	return (WHITE);
}

int	calc_z_value(int z, t_map *map)
{
	if (z < map->min_z)
		map->min_z = z;
	if (z > map->max_z)
		map->max_z = z;
	return (z);
}
