/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_xX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:49:03 by hheng             #+#    #+#             */
/*   Updated: 2024/07/03 08:42:20 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_addrs(uintptr_t ptr, char *base)
{
	if (ptr == 0)
		return (0);
	else
		return (print_addrs(ptr / 16, base) + write(1, &base[ptr % 16], 1));
}

int	print_hex(unsigned int ptr, char *base)
{
	if (ptr == 0)
		return (0);
	else
		return (print_hex(ptr / 16, base) + write(1, &base[ptr % 16], 1));
}

int	ft_print_p(uintptr_t ptr)
{
	int		len;

	len = write(1, "0x", 2);
	if (!ptr)
	{
		write(1, "0", 1);
		return (3);
	}
	len += print_addrs(ptr, "0123456789abcdef");
	return (len);
}

int	ft_print_x(unsigned int num, char c)
{
	if (!num)
		return (write(1, "0", 1));
	if (c == 'x')
		return (print_hex(num, "0123456789abcdef"));
	else
		return (print_hex(num, "0123456789ABCDEF"));
}
