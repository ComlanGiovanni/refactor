/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_map_finishable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:24:37 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 01:14:33 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

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

void	ft_free_and_print(char **map, t_game *game, char *str)
{
	ft_clean_grid_map(map, game->height);
	ft_print_error(str, game);
}

char	**ft_split_map(t_game *game)
{
	int		idx;
	int		row;
	int		column;
	char	**grid;

	idx = 0;
	row = 0;
	grid = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!grid)
		ft_print_error(SPLIT_MAP_ERROR, game);
	while (game->map.map_str[idx] != '\0')
	{
		column = 0;
		grid[row] = (char *)malloc(sizeof(char) * (game->width + 1));
		if (!grid[row])
			ft_clean_fail_malloc_split_map(game, grid, row);
		while (column < game->width)
			grid[row][column++] = game->map.map_str[idx++];
		grid[row][column] = '\0';
		row++;
	}
	grid[row] = NULL;
	return (grid);
}

void	ft_clean_fail_malloc_split_map(t_game *game, char **grid, int row)
{
	ft_clean_grid_map(grid, row);
	ft_print_error(SPLIT_MAP_ERROR, game);
}

void	ft_clean_grid_map(char **grid, int row)
{
	int	index;

	index = 0;
	while (index < row)
	{
		if (grid[index])
			free(grid[index]);
		index++;
	}
	if (grid)
		free(grid);
}
