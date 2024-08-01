/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:34:16 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 15:16:00 by gicomlan         ###   ########.fr       */
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

void	ft_display_position(t_point start, t_point end, t_point z, t_point n)
{
	ft_printf("\nPlayer Start  position in grid x->%d y->%d\n", start.x,
			start.y);
	ft_printf("Player Exit     position in grid x->%d y->%d\n", end.x, end.y);
	ft_printf("Portal 1 : {%c} position in grid x->%d y->%d\n", PORTAL_1_CHAR,
			z.x, z.y);
	ft_printf("Portal 2 : {%c} position in grid x->%d y->%d\n\n", PORTAL_2_CHAR,
			n.x, n.y);
}
