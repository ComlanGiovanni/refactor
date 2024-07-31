/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_with_border_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 04:55:54 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/29 05:04:14 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

static char	**allocate_new_map(int new_height, int new_width, t_game *game)
{
	char	**new_map;
	int		row;

	new_map = (char **)malloc((new_height + 1) * sizeof(char *));
	if (!new_map)
		ft_print_error(BORDERS_MAP_ERROR, game);
	row = 0;
	while (row < new_height)
	{
		new_map[row] = (char *)malloc((new_width + 1) * sizeof(char));
		if (!new_map[row])
			ft_clean_fail_malloc_split_map(game, new_map, row);
		row++;
	}
	new_map[row] = NULL;
	return (new_map);
}

static void	fill_map_row(char **new_map, int row, t_game *game, int new_width)
{
	int	column;
	int	border_width;
	int	new_height;

	border_width = game->map.border_width;
	new_height = game->height + 2 * border_width;
	column = 0;
	while (column < new_width)
	{
		if (row < border_width || row >= new_height - border_width
			|| column < border_width || column >= new_width - border_width)
			new_map[row][column] = BORDER_CHAR;
		else
			new_map[row][column] = game->map.matrice[row - border_width][column
				- border_width];
		column++;
	}
	new_map[row][new_width] = '\0';
}

char	**ft_create_map_with_border(t_game *game)
{
	int		row;
	int		new_width;
	int		new_height;
	char	**new_map;

	new_width = game->width + 2 * game->map.border_width;
	new_height = game->height + 2 * game->map.border_width;
	new_map = allocate_new_map(new_height, new_width, game);
	row = 0;
	while (row < new_height)
	{
		fill_map_row(new_map, row, game, new_width);
		row++;
	}
	if (game->map.matrice)
		ft_clean_grid_map(game->map.matrice, game->height);
	game->height = new_height;
	game->width = new_width;
	game->map.size.x = game->height;
	game->map.size.y = game->width;
	return (new_map);
}
