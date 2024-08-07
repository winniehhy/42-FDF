/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:22:21 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:22:21 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

/**
 * @brief Adjusts the zoom level of the display based on the provided keycode.
 *
 * If the keycode is PS_KEY, the zoom level is decreased, as long as it's greater
 * than 0.
 * If the keycode is MS_KEY, the zoom level is increased, as long as it's less
 * than INT_MAX.
 *
 * @param keycode The keycode that determines how the translation is adjusted.
 * @param fdf The display variables that include the zoom level to be adjusted.
 */
void	adjust_zoom(int keycode, t_data *fdf)
{
	if (keycode == MS_KEY)
	{
		if (fdf->zoom > 0)
			fdf->zoom -= ZOOM;
	}
	if (keycode == PS_KEY)
	{
		if (fdf->zoom < INT_MAX)
			fdf->zoom += ZOOM;
	}
}
