/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_finishable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:30:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 00:01:58 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_mandatory.h"

void	ft_get_number_collectible(t_game *game)
{
	int	idx;

	idx = FALSE;
	game->nbr_love = FALSE;
	while (idx++ < game->map_len)
	{
		if (game->map[idx] == COIN_CHAR)
			game->nbr_love++;
	}
}

t_point	ft_find_pos_char(char **tab, t_point size, char c)
{
	int	x;
	int	y;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (tab[y][x] == c)
				return ((t_point){x, y});
			x++;
		}
		y++;
	}
	return ((t_point){-1, -1});
}

t_bool	ft_path_exists(char **tab, t_point size, t_point start, t_point end)
{
	return (ft_path_founding(tab, size, start, end));
}

t_bool	ft_path_founding(char **tab, t_point size, t_point cur, t_point end)
{
	char	temp;

	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'V')
		return (FALSE);
	if (cur.x == end.x && cur.y == end.y)
		return (TRUE);
	temp = tab[cur.y][cur.x];
	tab[cur.y][cur.x] = 'V';
	if (ft_path_founding(tab, size, (t_point){cur.x + 1, cur.y}, end) ||
		ft_path_founding(tab, size, (t_point){cur.x - 1, cur.y}, end) ||
		ft_path_founding(tab, size, (t_point){cur.x, cur.y + 1}, end) ||
		ft_path_founding(tab, size, (t_point){cur.x, cur.y - 1}, end))
	{
		tab[cur.y][cur.x] = temp;
		return (TRUE);
	}
	tab[cur.y][cur.x] = temp;
	return (FALSE);
}

void	ft_get_all_collectable(char **tab, t_game *game, t_point start,
		int *coins)
{
	if (start.y < 0 || start.y >= game->height || start.x < 0
		|| start.x >= game->width || tab[start.y][start.x] == '1'
		|| tab[start.y][start.x] == 'V')
		return ;
	if (tab[start.y][start.x] == 'M')
	{
		tab[start.y][start.x] = '0';
		(*coins)++;
	}
	tab[start.y][start.x] = 'V';
	ft_get_all_collectable(tab, game, (t_point){start.x - 1, start.y}, coins);
	ft_get_all_collectable(tab, game, (t_point){start.x + 1, start.y}, coins);
	ft_get_all_collectable(tab, game, (t_point){start.x, start.y - 1}, coins);
	ft_get_all_collectable(tab, game, (t_point){start.x, start.y + 1}, coins);
}
