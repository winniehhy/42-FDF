/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:21:22 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:21:22 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Initializes the MiniLibX library and creates a new window.
 *
 * This function initializes the MiniLibX library, creates a new image, gets
 * the address of the image data, and creates a new window.
 *
 * @param fdf A pointer to a t_data structure that stores the MiniLibX variables
 */
void	init_mlx(t_data *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		free_map_mem(fdf->map);
		free(fdf);
		exit_err(MLX_ERROR);
	}
	fdf->img->img = mlx_new_image(fdf->mlx, W_WIDTH, W_HEIGHT);
	fdf->win = mlx_new_window(fdf->mlx, W_WIDTH, W_HEIGHT, "Winnie's 42 FDF");
	if (!fdf->win || !fdf->img)
	{
		close_window(fdf);
		exit_err(MLX_ERROR);
	}
	fdf->img->addr = mlx_get_data_addr(fdf->img->img,
			&fdf->img->bpp, &fdf->img->ln_len, &fdf->img->endian);
}

/**
 * @brief Starts the MiniLibX library and enters the main event loop.
 *
 * This function sets up a t_data structure initialized with default values,
 * and initializes all the mlx vairables in the `fdf` structure.
 *
 * In the main event loop, hooks are setup to handle events such as key press
 * and closing of window, draws the initial frame, and enters the main event
 * loop.
 *
 * @param map A pointer to a t_map structure that contains the map data.
 */
void	begin_mlx(t_map *map)
{
	t_data	*fdf;

	fdf = init_data(map);
	if (!fdf)
		exit_err(close_window(fdf));
	init_mlx(fdf);
	mlx_hook(fdf->win, 2, (1L << 0), &handle_keypress, fdf);
	mlx_hook(fdf->win, 17, 0, &close_window, fdf);
	draw_map(fdf);
	mlx_loop(fdf->mlx);
}
