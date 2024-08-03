/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:56:50 by hheng             #+#    #+#             */
/*   Updated: 2024/07/03 08:41:54 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_s(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_print_d(int num)
{
	char	*c;
	int		len;

	len = 0;
	c = ft_itoa(num);
	len = ft_print_s(c);
	free(c);
	return (len);
}
