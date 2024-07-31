/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_finishable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:30:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/29 13:01:17 by gicomlan         ###   ########.fr       */
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
	ft_flood_fill(tab, game, (t_point){start.x - 1, start.y}, exit_found, coins);
	ft_flood_fill(tab, game, (t_point){start.x + 1, start.y}, exit_found, coins);
	ft_flood_fill(tab, game, (t_point){start.x, start.y - 1}, exit_found, coins);
	ft_flood_fill(tab, game, (t_point){start.x, start.y + 1}, exit_found, coins);
}

// int manhattan_distance(t_point a, t_point b) {
//     return abs(a.x - b.x) + abs(a.y - b.y);
// }

// t_bool	ft_path_exists(char **tab, t_point size, t_point start, t_point end)
// {
// 	return (ft_path_founding(tab, size, start, end));
// }

// t_bool	ft_path_founding(char **tab, t_point size, t_point cur, t_point end)
// {
// 	char	temp;

// 	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
// 		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'V')
// 		return (FALSE);
// 	if (cur.x == end.x && cur.y == end.y)
// 		return (TRUE);
// 	temp = tab[cur.y][cur.x];
// 	tab[cur.y][cur.x] = 'V';
// 	//ft_print_fill_grid(tab);
// 	t_point directions[4] = {
//         {cur.x + 1, cur.y},
//         {cur.x - 1, cur.y},
//         {cur.x, cur.y + 1},
//         {cur.x, cur.y - 1}
//     };

// 	for (int i = 0; i < 4 - 1; i++) {
//         for (int j = i + 1; j < 4; j++) {
//             if (manhattan_distance(directions[i], end) > manhattan_distance(directions[j], end)) {
//                 t_point tmp = directions[i];
//                 directions[i] = directions[j];
//                 directions[j] = tmp;
//             }
//         }
//     }
//     for (int i = 0; i < 4; i++) {
//         if (ft_path_founding(tab, size, directions[i], end)) {
//             return TRUE;
//         }
//     }
// 	tab[cur.y][cur.x] = temp;
// 	return (FALSE);
// }

void	ft_get_all_collectable(char **tab, t_game *game, t_point start,
		int *coins)
{
	if (start.y < 0 || start.y >= game->height || start.x < 0
		|| start.x >= game->width || tab[start.y][start.x] == '1'
		|| tab[start.y][start.x] == 'M')
		return ;
	//  if (tab[start.y][start.x] == 'E') {
    //     printf("Error: Found 'E' at (%d, %d)\n", start.x, start.y);
    //     return ;
    // }
	if (tab[start.y][start.x] == 'C')
	{
		tab[start.y][start.x] = '0';
		(*coins)++;
	}
	//tab[start.y][start.x] = 'M';
	//ft_print_fill_grid(tab);
	//ft_printf("In-Bot %d On-map %d", (*coins), game->map.nbr_key);
	ft_get_all_collectable(tab, game, (t_point){start.x - 1, start.y}, coins);
	ft_get_all_collectable(tab, game, (t_point){start.x + 1, start.y}, coins);
	ft_get_all_collectable(tab, game, (t_point){start.x, start.y - 1}, coins);
	ft_get_all_collectable(tab, game, (t_point){start.x, start.y + 1}, coins);
}
