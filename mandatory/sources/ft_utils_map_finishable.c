/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_map_finishable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:24:37 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 00:02:08 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_mandatory.h"

void	ft_check_map_finishable(t_game *game)
{
	t_point	start;
	t_point	end;
	t_point	size;
	char	**map;
	int		coin;

	map = ft_split_map(game);
	ft_print_display_grid(map);
	size.x = game->width;
	size.y = game->height;
	coin = 0;
	start = ft_find_pos_char(map, size, 'P');
	end = ft_find_pos_char(map, size, 'E');
	if (!ft_path_exists(map, size, start, end))
		ft_free_and_print(map, game, PATH_MAP_ERROR);
	ft_get_all_collectable(map, game, start, &coin);
	if (coin != game->nbr_love)
		ft_free_and_print(map, game, COIN_MAP_ERROR);
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
