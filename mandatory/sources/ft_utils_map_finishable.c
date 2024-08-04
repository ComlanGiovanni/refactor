/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_map_finishable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:24:37 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 14:34:24 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_mandatory.h"

void	ft_check_map_finishable(t_game *game)
{
	t_point	start;
	t_point	end;
	t_point	size;
	t_bool	exit_found;
	char	**map;
	int		coin;

	map = ft_split_map(game);
	ft_print_display_grid(map);
	size.x = game->width;
	size.y = game->height;
	coin = 0;
	exit_found = 0;
	start = ft_find_pos_char(map, size, 'P');
	end = ft_find_pos_char(map, size, 'E');
	if ((start.x == -1 && start.y == -1)
		|| (end.x == -1 && end.y == -1))
		ft_free_and_print(map, game, NO_POSITION_FOUND);
	ft_flood_fill(map, game, start, &exit_found, &coin);
	printf("coin - %d exit bool%d game->key%lld\n", coin, exit_found, game->key);
	if (!exit_found)
		ft_free_and_print(map, game, PATH_MAP_ERROR);
	if (coin != game->key)
	{
		ft_printf("%s %d\n%s %d\n", KEY_FOUND, coin, KEY_AVAILABLE,
			game->key);
		ft_free_and_print(map, game, COIN_MAP_ERROR);
	}
	ft_printf("%s", PATH_MAP_GOOD);
	ft_printf("%s", COIN_MAP_GOOD);
	ft_clean_grid_map(map, game->height);
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
	while (game->map[idx] != '\0')
	{
		column = 0;
		grid[row] = (char *)malloc(sizeof(char) * (game->width + 1));
		if (!grid[row])
			ft_clean_fail_malloc_split_map(game, grid, row);
		while (column < game->width)
			grid[row][column++] = game->map[idx++];
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
		free(grid[index]);
		index++;
	}
	free(grid);
}
