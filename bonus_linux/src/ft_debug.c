/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:34:16 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 00:49:30 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

void	ft_print_fill_grid(char **map)
{
	ft_print_display_grid(map);
	system("clear");
}

void	ft_print_display_grid(char **res)
{
	if (!res)
		return ;
	while (*res)
	{
		ft_printf("%s\n", *res);
		res++;
	}
}

void	ft_display_start_end(t_point start, t_point end)
{
	ft_printf("\nStart position in grid x->%d y->%d\n", start.x, start.y);
	ft_printf("Exit position in grid x->%d y->%d\n\n", end.x, end.y);
}
