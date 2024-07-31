/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_managements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:55:04 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 00:49:44 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

void	ft_print_no_arg(void)
{
	ft_printf("%s%s", ERROR_MSG, USAGE_MSG);
	exit(EXIT_FAILURE);
}

void	ft_print_error_empty_and_free(char *error_msg, t_game *game)
{
	ft_free_animation(game);
	ft_free_mlx(game);
	ft_printf("%s%s", ERROR_MSG, error_msg);
	exit(EXIT_FAILURE);
}
