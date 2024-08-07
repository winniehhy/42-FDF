/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:21:17 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:21:17 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int ac, char **av)
{
	char	*file;
	t_map	*map;

	if (ac != 2)
		exit_err(INVALID_ARGS_ERROR);
	
	file = av[1];
	check_filename(file);
	map = init_map(file);
	begin_mlx(map);
	free_map_mem(map);

	return (SUCCESS);
}
