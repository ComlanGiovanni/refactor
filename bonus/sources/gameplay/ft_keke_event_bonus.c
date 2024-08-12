/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keke_event_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:40:59 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 12:06:39 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int ft_absolute_value(int value)
{
	if (value < 0)
		return -value;
	return value;
}

int ft_manhattan_heuristic_distance(t_point a, t_point b)
{
	return ft_absolute_value(a.x - b.x) + ft_absolute_value(a.y - b.y);
}

int ft_is_same_point(t_point a, t_point b)
{
	return ((a.x == b.x) && (a.y == b.y));
}

int ft_is_keke_walkable_point(char **grid, int x, int y)
{
	return grid[y][x] != WALL_CHAR && grid[y][x] != KEY_CHAR && grid[y][x] != LOVE_CHAR && grid[y][x] != EXIT_CHAR
	&& grid[y][x] != PORTAL_1_CHAR && grid[y][x] != PORTAL_2_CHAR && grid[y][x] != LAVA_CHAR && grid[y][x] != PAWN_CHAR;
}

void ft_free_a_star_lists_nodes_elements(t_a_star_node **list, int count)
{
	int index;

	index = 0;
	while (index < count)
	{
		if (list[index])
		{
			free(list[index]);
			list[index] = NULL;
		}
		index++;
	}
	free(list);
}

void ft_free_a_star_lists_nodes(t_a_star_node **open_list, int open_count, t_a_star_node **closed_list, int closed_count)
{
	ft_free_a_star_lists_nodes_elements(open_list, open_count);
	ft_free_a_star_lists_nodes_elements(closed_list, closed_count);
}

t_a_star_node *ft_init_keke_start_node(t_point start, t_point goal)
{
	t_a_star_node *start_node;
	start_node = (t_a_star_node *)malloc(sizeof(t_a_star_node));
	if (!start_node)
		return (NULL);
	start_node->pos = start;
	start_node->g = 0;
	start_node->f = ft_manhattan_heuristic_distance(start, goal);
	start_node->parent = NULL;
	return (start_node);
}

void ft_add_to_open_list(t_a_star_node **open_list, int *open_count, t_a_star_node *new_node)
{
	open_list[*open_count] = new_node;
	(*open_count)++;
}

void ft_sort_open_list(t_a_star_node **open_list, int open_count)
{
	int current_index;
	int insertion_index;
	t_a_star_node *current_node;

	insertion_index = 0;
	current_index = 1;
	current_node = NULL;
	while (current_index < open_count)
	{
		current_node = open_list[current_index];
		insertion_index = current_index - 1;
		while (insertion_index >= 0 && open_list[insertion_index]->f > current_node->f)
		{
			open_list[insertion_index + 1] = open_list[insertion_index];
			insertion_index--;
		}
		open_list[insertion_index + 1] = current_node;
		current_index++;
	}
}

void	ft_init_neighbor_data(t_game *game, t_point goal)
{
	game->keke.a_star.neighbor.goal = goal;
	game->keke.a_star.neighbor.directions[0] = (t_point){0, -1};
	game->keke.a_star.neighbor.directions[1] = (t_point){0, 1};
	game->keke.a_star.neighbor.directions[2] = (t_point){-1, 0};
	game->keke.a_star.neighbor.directions[3] = (t_point){1, 0};
	game->keke.a_star.neighbor.dir_char[0] = 'u';
	game->keke.a_star.neighbor.dir_char[1] = 'd';
	game->keke.a_star.neighbor.dir_char[2] = 'l';
	game->keke.a_star.neighbor.dir_char[3] = 'r';
}

void ft_find_keke_direction(t_game *game, t_a_star_node *current, t_point start, t_point directions[], char dir_char[])
{
	int index;

	while (current->parent && !ft_is_same_point((current->parent->pos) , start))
		current = current->parent;

	index = 0;
	while (index < 4) //maccor for direction
	{
		if (ft_is_same_point((t_point){start.x + directions[index].x, start.y + directions[index].y}, current->pos))
		{
			game->keke.direction = dir_char[index];
			break;
		}
		index++;
	}
}

void ft_check_if_current_node_is_player_pos(t_game *game, t_a_star_node *current, t_point directions[], char dir_char[])
{
	t_point start;
	start = ft_find_pos_char(game->map.grid, game->map.size, KEKE_CHAR);

	// Si l'objectif est atteint, trouver la direction
	if (ft_is_same_point(current->pos, game->player.movement.current_position))
		ft_find_keke_direction(game, current, start, directions, dir_char);
	//return ;
}

void ft_remove_from_open_list(t_a_star_node **open_list, int *open_count)
{
	int index;

	index = 0;
	while (index < (*open_count - 1))
	{
		open_list[index] = open_list[index + 1];
		index++;
	}
	(*open_count)--;
}

int ft_check_if_point_is_in_list(t_a_star_node **list, int count, t_point pos)
{
	int index;

	index = 0x0;
	while (index < count)
	{
		if (ft_is_same_point((list[index]->pos), pos)) {
			return (TRUE);  // Le nœud est déjà dans la liste
		}
		index++;
	}
	return (FALSE);  // Le nœud n'est pas dans la liste
}

t_a_star_node *create_neighbor_node(t_game *game, t_a_star_node *current, t_point pos)
{
	t_a_star_node *node;
	node = (t_a_star_node *)malloc(sizeof(t_a_star_node));

	if (!node)
		ft_print_error("init neighbor node fail malloc", game); //MACRO
	node->pos = pos;
	node->g = current->g + 1;
	node->f = node->g + ft_manhattan_heuristic_distance(pos, game->keke.a_star.neighbor.goal);
	node->parent = current;
	return (node);
}

int ft_node_is_valid_neighbor(t_game *game, int x, int y)
{
	return x >= 0 && y >= 0 && x < game->width && y < game->height && ft_is_keke_walkable_point(game->map.grid, x, y);
}

t_point get_neighbor_pos(t_game *game, t_a_star_node *current, int index)
{
	// int x;
	// int y;

	// x = current->pos.x + game->keke.a_star.neighbor.directions[index].x;
	// y = current->pos.y + game->keke.a_star.neighbor.directions[index].y;
	return (t_point){current->pos.x + game->keke.a_star.neighbor.directions[index].x,
		current->pos.y + game->keke.a_star.neighbor.directions[index].y};
}

t_bool ft_node_is_valid_and_not_in_closed(t_game *game, t_point pos)
{
	return ft_node_is_valid_neighbor(game, pos.x, pos.y) &&
		!ft_check_if_point_is_in_list(game->keke.a_star.lists.closed, game->keke.a_star.lists.closed_count, pos);
}

void ft_check_neighbor_node(t_game *game, t_a_star_node *current, t_point pos)
{
	t_a_star_node *node;

	node = create_neighbor_node(game, current, pos);
	if (!ft_check_if_point_is_in_list(game->keke.a_star.lists.open, game->keke.a_star.lists.open_count, pos))
		ft_add_to_open_list(game->keke.a_star.lists.open, &(game->keke.a_star.lists.open_count), node);
	else
		free(node);
}
void ft_explore_neighbors_node(t_game *game, t_a_star_node *current)
{
	int index;
	t_point neighbor_pos;

	index = 0;
	while (index < 4)//macro for direction position
	{
		neighbor_pos = get_neighbor_pos(game, current, index);
		if (ft_node_is_valid_and_not_in_closed(game, neighbor_pos))
			ft_check_neighbor_node(game, current, neighbor_pos);
		index++;
	}
}

//put in ini folder
void ft_init_a_star_lists(t_game *game)
{
	game->keke.a_star.lists.open_count = 0;
	game->keke.a_star.lists.closed_count = 0;
	game->keke.a_star.lists.open = (t_a_star_node **)malloc(game->map.len * sizeof(t_a_star_node *));
	game->keke.a_star.lists.closed = (t_a_star_node **)malloc(game->map.len * sizeof(t_a_star_node *));
	if (!game->keke.a_star.lists.open || !game->keke.a_star.lists.closed)
		ft_print_error("Memory allocation failed for A* lists", game);
}

void	ft_a_star_keke_movement(t_game *game)
{
	t_point start;
	t_point goal;
	t_a_star_node *start_node;
	t_a_star_node *current;

	start = ft_find_pos_char(game->map.grid, game->map.size, KEKE_CHAR);
	goal = game->player.movement.current_position;
	start_node = ft_init_keke_start_node(start, goal);
	if (!start_node)
		ft_print_error("init start node for path founding fall", game);
	ft_init_a_star_lists(game);
	ft_add_to_open_list(game->keke.a_star.lists.open, &(game->keke.a_star.lists.open_count), start_node);
	ft_init_neighbor_data(game, goal); //we can init in init fonction game->keke.a_star.neighbor.goal = goal;
	while (game->keke.a_star.lists.open_count > 0)
	{
		ft_sort_open_list(game->keke.a_star.lists.open, game->keke.a_star.lists.open_count);
		//qsort(game->keke.a_star.lists.open, game->keke.a_star.lists.open_count, sizeof(t_a_star_node *), compare_nodes);
		current = game->keke.a_star.lists.open[0];// Prendre le nœud avec le coût le plus bas
		ft_check_if_current_node_is_player_pos(game, current, game->keke.a_star.neighbor.directions, game->keke.a_star.neighbor.dir_char);
		ft_remove_from_open_list(game->keke.a_star.lists.open, &(game->keke.a_star.lists.open_count));
		game->keke.a_star.lists.closed[game->keke.a_star.lists.closed_count++] = current;
		ft_explore_neighbors_node(game, current);
	}
	ft_free_a_star_lists_nodes(game->keke.a_star.lists.open, game->keke.a_star.lists.open_count,
		game->keke.a_star.lists.closed, game->keke.a_star.lists.closed_count);
	ft_move_keke(game);
}


void	ft_move_keke(t_game *game)
{
	if (game->keke.direction == 'u')
		ft_keke_move_up(game);
	if (game->keke.direction == 'd')
		ft_keke_move_down(game);
	if (game->keke.direction == 'l')
		ft_keke_move_left(game);
	if (game->keke.direction == 'r')
		ft_keke_move_right(game);
}
