/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:34:16 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/29 06:00:49 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

void	ft_print_fill_grid(char **map)
{
	ft_print_display_grid(map);
	//ft_secure_usleep(500000);
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

// void	ft_display_grid(char **array, int height, int width)
// {
// 	int	row;
// 	int	col;

// 	if (array == NULL)
// 		return ;
// 	if (height <= 0 || width <= 0)
// 		return ;
// 	row = 0;
// 	col = 0;
// 	while (row < height)
// 	{
// 		col = 0;
// 		while (col < width)
// 		{
// 			if (array[row] == NULL)
// 				return ;
// 			ft_printf("%c", array[row][col]);
// 			col++;
// 		}
// 		ft_printf("\n");
// 		row++;
// 	}


void	ft_display_start_end(t_point start, t_point end)
{
	// ft_printf("START x->%d y->%d\n", start.x, start.y);
	// ft_printf("END x->%d y->%d\n", end.x, end.y);
	ft_printf("\nStart position in grid x->%d y->%d\n", start.x, start.y);
	ft_printf("Exit position in grid x->%d y->%d\n\n", end.x, end.y);
}

void	ft_secure_usleep(int microseconds)
{
	if (usleep(microseconds) == -1)
	{
		perror("Usleep");
		return ;
	}
}
