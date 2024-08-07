/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:20:34 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:20:34 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// #include <string.h>

/** @brief Exits the program with a custom errror message based
 * on the exit_status
 *
 * This function terminates the program with prints error messages
 * based on type of error from the `exit_status` parameter. It colors
 * the teminal output to yellow for displaying messages. If the program
 * runs successfully, it exits the program with a success status code.
 * Otherwise, it will print out the exit with the appropriate error status.
 *
 * It exits the program with the same exit_status passed in as
 * parameter.
 *
 * @param exit_status the exit status indicating the type of error
 */
void	exit_err(int exit_status)
{
	ft_printf("%s", COLOR_ERR_MSG);
	if (exit_status == INVALID_ARGS_ERROR)
		ft_printf("INVALID_ARGS_ERROR: { Usage: ./fdf <map>.fdf }\n");
	else if (exit_status == FILE_OPEN_ERROR)
		ft_printf("FILE_OPEN_ERROR: Failed to open file\n");
	else if (exit_status == MEM_ALLOC_ERROR)
		ft_printf("MEM_ALLOC_ERROR: Failed in allocating memory\n");
	else if (exit_status == MAP_EMPTY_ERROR)
		ft_printf("MAP_EMPTY_ERROR: Map is empty...just like your soul\n");
	else if (exit_status == LIBFT_ERROR)
		ft_printf("LIBFT_ERROR: Your libft function failed\n");
	else if (exit_status == MLX_ERROR)
		ft_printf("MLX_ERROR: Your minilibx function failed\n");
	else if (exit_status == SUCCESS)
		ft_printf("SUCCESS: The program ran successfully\n");
	else if (exit_status == INVALID_FILENAME_ERROR)
		ft_printf("INVALID_FILENAME_ERROR: The filename must end with .fdf\n");
	else
		ft_printf("That's not a valid map!\n");
	ft_printf("%s", RESET_ERR_MSG);
	exit(exit_status);
}

void	check_filename(const char *filename)
{
	const char *extension = ".fdf";
	size_t len = ft_strlen(filename);
	size_t ext_len = ft_strlen(extension);

	if (len < ext_len || ft_strcmp(filename + len - ext_len, extension) != 0)
		exit_err(INVALID_FILENAME_ERROR);
}
