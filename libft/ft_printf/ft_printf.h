/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:05:26 by hheng             #+#    #+#             */
/*   Updated: 2024/07/03 08:43:20 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

int		ft_print_c(char c);
int		ft_print_s(char *str);
int		ft_print_p(uintptr_t ptr);
int		ft_print_d(int num);
int		ft_print_u(unsigned int num);
int		ft_print_x(unsigned int num, char c);
#endif