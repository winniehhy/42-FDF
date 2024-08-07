/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stderr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:53:51 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:53:51 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/// This macro converts the parameter (x) into a string literal.
// #define ERROR_TYPE(x) #x

/*This macro is the ANSI escape code for setting
 terminal output color to yellow.*/
#define COLOR_ERR_MSG "\033[33m"

// This macro is to reset ANSI escape code coloring.
#define RESET_ERR_MSG "\033[0m"

// This macro defines the exit status SUCCESS for error handling.
#define SUCCESS 0

// This macro defines the exit status FAILURE for error handling.
#define FAILURE 1

// This macro defines the exit status INVALID_ARGS_ERROR for error handling.
#define INVALID_ARGS_ERROR 2

// This macro defines the exit status FILE_OPEN_ERROR for error handling.
#define FILE_OPEN_ERROR 3

// This macro defines the exit status MEM_ALLOC_ERROR for error handling.
#define MEM_ALLOC_ERROR 4

// This macro defines the exit status MAP_EMPTY_ERROR for error handling.
#define MAP_EMPTY_ERROR 5

// This macro defines the exit status LIBFT_ERROR for error handling.
#define LIBFT_ERROR 6

// This macro defines the exit status MLX_ERROR for error handling.
#define MLX_ERROR 7

// This macro defines the exit status ASIAN_FAILURE_ERROR for error handling.
#define ASIAN_FAILURE_ERROR 8

//filename must end with .fdf
#define INVALID_FILENAME_ERROR 9