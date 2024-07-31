/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_managements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:55:04 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/26 21:09:55 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

// write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
// write(STDERR_FILENO, USAGE_MSG, ft_strlen(USAGE_MSG));

void	ft_print_no_arg(void)
{
	ft_printf("%s%s", ERROR_MSG, USAGE_MSG);
	exit(EXIT_FAILURE);
}

//write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
//write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
void	ft_print_error_empty_and_free(char *error_msg, t_game *game)
{
	ft_free_animation(game);
	ft_free_mlx(game);
	ft_printf("%s%s", ERROR_MSG, error_msg);
	exit(EXIT_FAILURE);
}
