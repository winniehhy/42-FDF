/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:19:59 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:19:59 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Adjusts the flattening factor based on the provided keycode.
 *
 * If the keycode is UP_KEY, the flattening factor is increased by 0.01,
 * up to a maximum of 10.
 * If the keycode is DW_KEY, the flattening factor is decreased by 0.01, d
 * own to a minimum of 0.
 *
 * @param keycode The keycode that determines how the flattening factor is
 * adjusted.
 * @param fdf The display variables that include the flattening factor to be
 * adjusted.
 */
void	adjust_alt(int keycode, t_data *fdf)
{
	if (keycode == UP_KEY)
	{
		if (fdf->ff < 10)
			fdf->ff += FF;
	}
	if (keycode == DW_KEY)
	{
		if (fdf->ff > 0)
			fdf->ff -= FF;
	}
}
