/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:21:27 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:21:27 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

/**
 * @brief Parse the height and width from the map file.
 *
 * This function reads a new line from the file descriptor `fd`
 * and splits each line into an array of strings. It iterates over
 * each new line to calculate the `height` of the map. The first
 * split is used to calculate the `width` of the map.
 *
 * Error handling is done in `find_width`.
 *
 * @param fd The file descriptor of the map file
 * @param map A pointer to the uninitialised t_map structure
 */
void	parse_map_size(int fd, t_map *map)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	split = ft_split(line, ' ');
	map->width = find_width(split);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

/**
 * @brief Parse the z-values from the map file.
 *
 * This function allocates memory for the 'z-2D' and 'colors' fields
 * of the `map`. It reads lines from the file descriptor `fd` and
 * splits each line into an array of strings to be used in parsing.
 *
 * Each string in the split array is converted to an integer with `ft_atoi`
 * for `z_2d` and to a color with `convert_hex_color` for `colors`.
 *
 * @param fd The file descriptor of the map file
 * @param map A pointer to the uninitialised t_map structure
 */
void	parse_map_mem(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	i = -1;
	alloc_map_mem(map);
	while (++i < map->height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		if (!split[0] || !split[1])
		{
			free_map_mem(map);
			exit_err(ASIAN_FAILURE_ERROR);
		}
		j = -1;
		while (split[++j])
		{
			map->z_2d[i][j] = calc_z_value(ft_atoi(split[j]), map);
			map->colors[i][j] = convert_hex_color(split[j], map);
		}
		free(line);
		free_split(split);
	}
}
