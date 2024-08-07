/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:21:52 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:21:52 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Adjusts the translation of the display based on the provided keycode.
 *
 * If the keycode is W_KEY, the y-axis shift is increased.
 * If the keycode is A_KEY, the x-axis shift is increased.
 * If the keycode is S_KEY, the y-axis shift is decreased.
 * If the keycode is D_KEY, the x-axis shift is decreased.
 *
 * @param keycode The keycode that determines how the translation is adjusted.
 * @param fdf The display variables that include the shift to be adjusted.
 */
void	adjust_trans(int keycode, t_data *fdf)
{
	if (keycode == W_KEY)
		fdf->shift_y += TRANS;
	if (keycode == A_KEY)
		fdf->shift_x += TRANS;
	if (keycode == S_KEY)
		fdf->shift_y -= TRANS;
	if (keycode == D_KEY)
		fdf->shift_x -= TRANS;
}
