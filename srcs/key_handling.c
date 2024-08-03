/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:21:10 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:21:10 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Handles key inputs and performs corresponding actions.
 *
 * This function takes a keycode and a pointer to a display structure. Depending
 * on the keycode, it performs different actions:
 * - KEY_ESC: Closes the window.
 * - KEY_R: Resets the display variables.
 * - KEY_TAB: Toggles the isometric view and parallel view.
 * - KEY_I or KEY_O: Handles zooming in or out.
 * - KEY_S, KEY_W, KEY_D, or KEY_A: Handles moving the display.
 * - KEY_1 to KEY_6: Handles rotating the display.
 * - KEY_7 or KEY_8: Adjusts the flattening factor.
 * After performing the corresponding action, it redraws the display.
 *
 * @param keycode The keycode that determines which action to perform.
 * @param fdf The display variables that are used or modified by the actions.
 * @return Always returns 0.
 */
int	handle_keypress(int keycode, t_data *fdf)
{
	if (keycode == ESC_KEY)
		close_window(fdf);
	if (keycode == R_KEY)
		reset_default(fdf);
	if (keycode == TAB_KEY)
		fdf->isometric ^= 1;
	if (keycode == PS_KEY || keycode == MS_KEY)
		adjust_zoom(keycode, fdf);
	if (keycode == W_KEY || keycode == A_KEY
		|| keycode == S_KEY || keycode == D_KEY)
		adjust_trans(keycode, fdf);
	if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3
		|| keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6)
		adjust_rot(keycode, fdf);
	if (keycode == UP_KEY || keycode == DW_KEY)
		adjust_alt(keycode, fdf);
	if (keycode == C_KEY)
	{
		change_color(fdf);
		draw_map(fdf);
	}
	draw_map(fdf);
	return (0);
}

/**
 * @brief Adjusts the rotation of the display based on the provided keycode.
 *
 * If the keycode is KEY_1, the rotation around the x-axis is increased.
 * If the keycode is KEY_2, the rotation around the x-axis is decreased.
 * If the keycode is KEY_3, the rotation around the y-axis is increased.
 * If the keycode is KEY_4, the rotation around the y-axis is decreased.
 * If the keycode is KEY_5, the rotation around the z-axis is increased.
 * If the keycode is KEY_6, the rotation around the z-axis is decreased.
 *
 * @param keycode The keycode that determines how the rotation is adjusted.
 * @param fdf The display variables that include the rotation to be adjusted.
 */
void	adjust_rot(int keycode, t_data *fdf)
{
	if (keycode == KEY_1)
		fdf->rot_x += ROT;
	if (keycode == KEY_2)
		fdf->rot_x -= ROT;
	if (keycode == KEY_3)
		fdf->rot_y += ROT;
	if (keycode == KEY_4)
		fdf->rot_y -= ROT;
	if (keycode == KEY_5)
		fdf->rot_z += ROT;
	if (keycode == KEY_6)
		fdf->rot_z -= ROT;
}
