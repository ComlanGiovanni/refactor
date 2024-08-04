/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_founding_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:24:37 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 21:54:14 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_check_map_finishable(t_game *game)
{
	int		coin;
	t_bool	exit_found;

	coin = 0;
	exit_found = 0;
	game->map.matrice = ft_split_map(game);
	game->map.start = ft_find_pos_char(game->map.matrice, game->map.size, 'P');
	game->map.end = ft_find_pos_char(game->map.matrice, game->map.size, 'E');
	if ((game->map.start.x == -1 && game->map.start.y == -1)
		|| (game->map.end.x == -1 && game->map.end.y == -1))
		ft_free_and_print(game->map.matrice, game, NO_POSITION_FOUND);
	ft_flood_fill(game->map.matrice, game, game->map.start, &exit_found, &coin);
	printf("coin - %d exit bool%d game->key%lld\n", coin, exit_found, game->map.info.nbr_key);
	if (!exit_found)
		ft_free_and_print(game->map.matrice, game, PATH_MAP_ERROR);
	if (coin != game->map.info.nbr_key)
	{
		ft_printf("%s %d\n%s %d\n", KEY_FOUND, coin, KEY_AVAILABLE,
			game->map.info.nbr_key);
		ft_free_and_print(game->map.matrice, game, COIN_MAP_ERROR);
	}
	ft_printf("%s", PATH_MAP_GOOD);
	ft_printf("%s", COIN_MAP_GOOD);
}

void	ft_flood_fill(char **tab, t_game *game, t_point start,
		t_bool *exit_found, int *coins)
{
	if (start.y < 0 || start.y >= game->height || start.x < 0
		|| start.x >= game->width || tab[start.y][start.x] == WALL_CHAR
		|| tab[start.y][start.x] == VISITED_CHAR)
		return ;
	if (tab[start.y][start.x] == KEY_CHAR)
	{
		tab[start.y][start.x] = VOID_CHAR;
		(*coins)++;
	}
	if (tab[start.y][start.x] == EXIT_CHAR)
		*exit_found = TRUE;
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
