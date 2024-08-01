/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_finishable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:30:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 04:44:49 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

t_point	ft_find_pos_char(char **tab, t_point size, char c)
{
	int	x;
	int	y;

	if (!tab || size.x <= 0 || size.y <= 0)
		return ((t_point){-1, -1});
	y = 0;
	while (y < size.y)
	{
		if (tab[y] == NULL)
			return ((t_point){-1, -1});
		x = 0;
		while (x < size.x)
		{
			if (tab[y][x] == '\0')
				break ;
			if (tab[y][x] == c)
				return ((t_point){x, y});
			x++;
		}
		y++;
	}
	return ((t_point){-1, -1});
}

void	ft_flood_fill(char **tab, t_game *game, t_point start,
		t_bool *exit_found, int *coins)
{
	if (start.y < 0 || start.y >= game->height || start.x < 0
		|| start.x >= game->width || tab[start.y][start.x] == WALL_CHAR
		|| tab[start.y][start.x] == VISITED_CHAR)
		return ;
	if (tab[start.y][start.x] == EXIT_CHAR)
		*exit_found = TRUE;
	if (tab[start.y][start.x] == KEY_CHAR)
	{
		tab[start.y][start.x] = VOID_CHAR;
		(*coins)++;
	}
	tab[start.y][start.x] = VISITED_CHAR;
	ft_print_fill_grid(tab);
	ft_flood_fill(tab, game, (t_point){start.x - 1, start.y}, exit_found,
			coins);
	ft_flood_fill(tab, game, (t_point){start.x + 1, start.y}, exit_found,
			coins);
	ft_flood_fill(tab, game, (t_point){start.x, start.y - 1}, exit_found,
			coins);
	ft_flood_fill(tab, game, (t_point){start.x, start.y + 1}, exit_found,
			coins);
}
