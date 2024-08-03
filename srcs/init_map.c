/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:20:54 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:20:54 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

/**
 * @brief Creates a t_map structure and initialises it with
 * the parsed data from the map
 *
 * This function allocates memory for a t_map structure and
 * opens the map file to be read then parsed. It splits the parsing
 * into two functions, parse_map_size() and parse_map_mem().
 *
 * If memory allocation of t_map structure is unsuccessful,
 * the program will exit with a memory allocation error message.
 * The same error handling is done for opening the file and
 * throughout the code, the program will exit accordingly with
 * the appropriate error message.
 *
 * @param filename A string representing the map file to be opened
 */
t_map	*init_map(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_err(FILE_OPEN_ERROR);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_err(MEM_ALLOC_ERROR);
	parse_map_size(fd, map);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_err(FILE_OPEN_ERROR);
	parse_map_mem(fd, map);
	close(fd);
	return (map);
}
