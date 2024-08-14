/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pawn_patrolling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:58:49 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 04:49:46 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

typedef struct s_direction_map {
    const char *name;
    t_point delta;
} t_direction_map;

t_point get_direction_delta(const char *direction) {
    static const t_direction_map direction_map[] = {
        {"down", {0, 1}},
        {"left", {-1, 0}},
        {"up", {0, -1}},
        {"right", {1, 0}},
        {"down-right", {1, 1}},
        {"down-left", {-1, 1}},
        {"up-right", {1, -1}},
        {"up-left", {-1, -1}}
    };

    size_t i = 0;
    t_point delta = {0, 0}; // Default to no movement

    while (i < sizeof(direction_map) / sizeof(direction_map[0])) {
        if (ft_strcmp((char *)direction, (char *)direction_map[i].name) == 0) {
            delta = direction_map[i].delta;
            break;
        }
        i++;
    }

    return delta;
}

t_point get_next_position(t_point current, const char *direction) {
    t_point delta = get_direction_delta(direction);
    current.x += delta.x;
    current.y += delta.y;
    return current;
}

// t_point get_next_position(t_point current, const char *direction)
// {
// 	if (ft_strcmp((char *)direction, "down") == 0)
// 		current.y += 1;
// 	else if (ft_strcmp((char *)direction, "left") == 0)
// 		current.x -= 1;
// 	else if (ft_strcmp((char *)direction, "up") == 0)
// 		current.y -= 1;
// 	else if (ft_strcmp((char *)direction, "right") == 0)
// 		current.x += 1;
// 	else if (ft_strcmp((char *)direction, "down-right") == 0)
// 	{
// 		current.x += 1;
// 		current.y += 1;
// 	} else if (ft_strcmp((char *)direction, "down-left") == 0)
// 	{
// 		current.x -= 1;
// 		current.y += 1;
// 	} else if (ft_strcmp((char *)direction, "up-right") == 0)
// 	{
// 		current.x += 1;
// 		current.y -= 1;
// 	} else if (ft_strcmp((char *)direction, "up-left") == 0)
// 	{
// 		current.x -= 1;
// 		current.y -= 1;
// 	}
// 	return (current);
// }

int ft_is_position_free_for_pawn(char **grid, t_point pos)
{
	return ((grid[pos.y][pos.x] == '0') || (grid[pos.y][pos.x] == 'P'));//macro
}

t_bool ft_is_position_within_bounds_for_pawn(t_point pos, t_point size) {
    return (pos.x >= 0 && pos.x < size.x && pos.y >= 0 && pos.y < size.y);
}

t_bool can_move_to_position(t_game *game, t_point pos) {
    return ft_is_position_within_bounds_for_pawn(pos, game->map.size) &&
           ft_is_position_free_for_pawn(game->map.grid, pos);
}

t_point ft_calculate_farthest_position(t_point start_position, const char *direction, t_game *game) {
    t_point current_position = start_position;
    t_point next_position;

    while (TRUE) {
        next_position = get_next_position(current_position, direction);
        if (!can_move_to_position(game, next_position)) {
            break;
        }
        current_position = next_position;
    }

    return current_position;
}

// t_point ft_calculate_farthest_position(t_point start_position, const char *direction, t_game *game)
// {
// 	t_point current_position;
// 	t_point next_position;

// 	current_position = start_position;
// 	while ("The prophecy is true !") //TRUE
// 	{
// 		next_position = get_next_position(current_position, direction);
// 		//put in same if
// 		if (next_position.x < 0 || next_position.x >= game->map.size.x || next_position.y < 0 || next_position.y >= game->map.size.y)
// 			break;
// 		if (!ft_is_position_free_for_pawn(game->map.grid, next_position))
// 			break;
// 		current_position = next_position;
// 	}

// 	return (current_position);
// }


size_t ft_calculate_steps(t_point start, t_point end, const char *direction) {
    if (ft_strcmp((char *)direction, "up") == 0 || ft_strcmp((char *)direction, "down") == 0 ||
        ft_strcmp((char *)direction, "up-left") == 0 || ft_strcmp((char *)direction, "up-right") == 0) {
        return ft_absolute_value(end.y - start.y);
    }
    return ft_absolute_value(end.x - start.x);
}

void ft_update_pawn_target(t_pawn_movement *pawn, t_point best_position, const char *best_dir, size_t max_steps) {
    pawn->target_position = best_position;
    pawn->direction = (char *)best_dir;
    pawn->steps_need = max_steps;
}

typedef struct s_direction_evaluation {
    size_t max_steps;
    t_point best_position;
    const char *best_dir;
} t_direction_evaluation;

void update_best_direction(t_pawn_movement *pawn, t_direction_evaluation *eval) {
    pawn->target_position = eval->best_position;
    pawn->direction = (char *)eval->best_dir;
    pawn->steps_need = eval->max_steps;
}

void evaluate_direction(t_game *game, t_pawn_movement *pawn, const char *direction, t_direction_evaluation *eval) {
    t_point temp_farthest_position = ft_calculate_farthest_position(pawn->current_position, direction, game);
    size_t steps = ft_calculate_steps(pawn->current_position, temp_farthest_position, direction);

    if (steps > eval->max_steps) {
        eval->max_steps = steps;
        eval->best_position = temp_farthest_position;
        eval->best_dir = direction;
    }
}

void ft_find_best_direction_for_pawn(t_game *game, t_pawn_movement *pawn) {
    const char *dir_names[8] = {
        "down", "down-left", "left", "up-left",
        "up", "up-right", "right", "down-right"
    };
    t_direction_evaluation eval = {0, pawn->current_position, dir_names[0]};
    int dir_index = 0;

    while (dir_index < 8) {
        evaluate_direction(game, pawn, dir_names[dir_index], &eval);
        dir_index++;
    }
    update_best_direction(pawn, &eval);
}

void print_pawn_info(int index, t_pawn_movement *pawn) {
    ft_printf("Pawn %d Initial Position (%d, %d) Target [%d, %d] in %s Direction with %u Steps.\n",
           index,
           pawn->initial_position.x, pawn->initial_position.y,
           pawn->target_position.x, pawn->target_position.y,
           pawn->direction, pawn->steps_need);
}

void ft_find_farthest_position_for_pawn(t_game *game) {
    int index = 0;
    while (index < game->map.info.nbr_pawn) {
        ft_find_best_direction_for_pawn(game, &game->pawn.pawns_array[index]);
		print_pawn_info(index, &game->pawn.pawns_array[index]);
        index++;
    }
}

// void ft_find_farthest_position_for_pawn(t_game *game)
// {
// 	t_point temp_farthest_position;
// 	t_point best_position;
// 	int index;
// 	size_t max_steps;
// 	const char *best_dir;
// 	int dir_index;
// 	size_t steps;

// 	index = 0;
// 	max_steps = 0;
// 	dir_index = 0;
// 	const char *dir_names[8] = {
// 		"down", "down-left", "left", "up-left",
// 		"up", "up-right", "right", "down-right"
// 	};
// 	while (index < game->map.info.nbr_pawn)
// 	{
// 		//ft_printf("Pawn %d at initial position [%d, %d]:\n", index, game->pawn.pawns_array[index].current_position.x, game->pawn.pawns_array[index].current_position.y);
// 		dir_index = 0;
// 		max_steps = 0;
// 		while (dir_index < 8)
// 		{
// 			temp_farthest_position = ft_calculate_farthest_position(game->pawn.pawns_array[index].current_position, dir_names[dir_index], game);
// 			if ((ft_strcmp((char *)dir_names[dir_index], "up") == 0) || (ft_strcmp((char *)dir_names[dir_index], "down") == 0) || (ft_strcmp((char *)dir_names[dir_index], "up-left") == 0) || (ft_strcmp((char *)dir_names[dir_index], "up-right") == 0))
// 				steps = ft_absolute_value(temp_farthest_position.y - game->pawn.pawns_array[index].current_position.y);//int ft_ft_absolute_valueolute_value(int value)
// 			else
// 				steps = ft_absolute_value(temp_farthest_position.x - game->pawn.pawns_array[index].current_position.x);
// 			// if (steps == 0)
// 			// 	ft_printf("  No movement position in %s direction.\n", dir_names[dir_index]);
// 			// else
// 			// 	printf("  Farthest Position in %s direction: [%d, %d] with %zu steps.\n", dir_names[dir_index], temp_farthest_position.x, temp_farthest_position.y, steps);
// 			if (steps > max_steps || (steps == max_steps && dir_index < 8))
// 			{
// 				max_steps = steps;
// 				best_position = temp_farthest_position;
// 				best_dir = dir_names[dir_index];
// 				game->pawn.pawns_array[index].target_position.x = best_position.x;
// 				game->pawn.pawns_array[index].target_position.y = best_position.y;
// 				game->pawn.pawns_array[index].direction = (char *)best_dir;
// 				game->pawn.pawns_array[index].steps_need = max_steps;
// 			}
// 			dir_index++;
// 		}
// 		//ft_printf("\nPawn %d Initial Position (%d, %d) Target %s Direction: [%d, %d] with %u steps.",index , best_dir, best_position.x, best_position.y, max_steps);
// 		ft_printf("\nPawn %d Initial Position (%d, %d) Target [%d, %d] in %s Direction with %u Steps.", index , game->pawn.pawns_array[index].initial_position.x, game->pawn.pawns_array[index].initial_position.y, best_position.x, best_position.y, best_dir, max_steps);
// 		index++;
// 	}
// }


void ft_init_pawns_array(t_game *game)
{
    // Allocate memory for the pawns array
    game->pawn.pawns_array = (t_pawn_movement *)malloc(game->map.info.nbr_pawn * sizeof(t_pawn_movement));

    // Check if the allocation failed
    if (!game->pawn.pawns_array)
        ft_print_error("Pawn array movement malloc failed", game);

    // Initialize the pawns' positions
    ft_find_pawn_positions(game);
	// for (long long int i = 0; i < game->map.info.nbr_pawn; i++)
	// {
	// 	ft_printf("Pawn %u - Position: (%d, %d)\n",
    //            i, game->pawn.pawns_array[i].current_position.x, game->pawn.pawns_array[i].current_position.y);
	// }
	ft_find_farthest_position_for_pawn(game);
	// for (long long int i = 0; i < game->map.info.nbr_pawn; i++)
	// {
	// 	printf("Pawn %llu - Position: (%d, %d), Target: (%d, %d), Direction: %s, Returning: %d\n\n",
    //            i, game->pawn.pawns_array[i].current_position.x, game->pawn.pawns_array[i].current_position.y,
    //            game->pawn.pawns_array[i].target_position.x, game->pawn.pawns_array[i].target_position.y,
    //            game->pawn.pawns_array[i].direction, game->pawn.pawns_array[i].is_returning);
	// }
	//ft_free_pawns_array(game);
}

void ft_free_pawns_array(t_game *game)
{
    // Free the allocated pawns array only once
    if (game->pawn.pawns_array)
    {
        free(game->pawn.pawns_array);
        game->pawn.pawns_array = NULL; // Set to NULL to avoid dangling pointer
    }
}

void	initialize_pawn(t_game *game, long long int index, int x, int y)
{
    if (index >= game->map.info.nbr_pawn)
        ft_print_error("Too much pawn found magic is happening\n", game);//macro
    game->pawn.pawns_array[index].initial_position = (t_point){x, y};
    game->pawn.pawns_array[index].current_position = (t_point){x, y};
    game->pawn.pawns_array[index].target_position = (t_point){x, y};
    game->pawn.pawns_array[index].direction = " ";
    game->pawn.pawns_array[index].is_returning = FALSE;
    game->pawn.pawns_array[index].is_active = FALSE;
    game->pawn.pawns_array[index].steps_taken = 0;
    game->pawn.pawns_array[index].steps_need = 0;
}

void	ft_check_valid_map_for_pawn_positions(t_game *game)
{
    if (!game || game->map.grid == NULL || game->map.size.x <= 0 || game->map.size.y <= 0)
        ft_print_error("Pawn position fail to get", game);//macro
}

void	ft_check_row_for_pawn_positions(char *row, t_game *game)
{
    if (row == NULL)
        ft_print_error("game->map.grid[y] == NULL", game);//macro
}

void	ft_find_pawn_positions(t_game *game)
{
    int x, y;
    long long int index = 0;

    ft_check_valid_map_for_pawn_positions(game);
    y = 0;
    while (y < game->map.size.y)
    {
        ft_check_row_for_pawn_positions(game->map.grid[y], game);
        x = 0;
        while (x < game->map.size.x)
        {
            if (game->map.grid[y][x] == '\0')
                break;
            if (game->map.grid[y][x] == 'W')
                initialize_pawn(game, index++, x, y);
            x++;
        }
        y++;
    }
    if (index < game->map.info.nbr_pawn)
        ft_print_error("Not enough pawns found", game);
}

// void ft_find_pawn_positions(t_game *game)
// {
// 	int	x;
// 	int	y;
// 	long long int index = 0;

// 	if (!game || game->map.grid == NULL || game->map.size.x <= 0 || game->map.size.y <= 0)
// 		ft_print_error("Pawn position fail to get", game);//macro
// 	y = 0;
// 	while (y < game->map.size.y)
// 	{
// 		if (game->map.grid[y] == NULL)
// 			ft_print_error("game->map.grid[y] == NULL", game);//macro
// 		x = 0;
// 		while (x < game->map.size.x)
// 		{
// 			if (game->map.grid[y][x] == '\0')
// 				break ;
// 			if (game->map.grid[y][x] == 'W')
// 			{
// 				if (index >= game->map.info.nbr_pawn)
// 					ft_print_error("Too much pawn found magic is happening\n", game);//macro
//                 game->pawn.pawns_array[index].initial_position = (t_point){x, y};
//                 game->pawn.pawns_array[index].current_position = (t_point){x, y};
//                 game->pawn.pawns_array[index].target_position = (t_point){x, y};
//                 game->pawn.pawns_array[index].direction = " ";
//                 game->pawn.pawns_array[index].is_returning = 0;
//                 game->pawn.pawns_array[index].steps_taken = 0;
//                 game->pawn.pawns_array[index].steps_need = 0;
//                 index++;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (index < game->map.info.nbr_pawn)
// 		ft_print_error("Not enough pawns found", game);//macro
// }

int is_obstacle(char **grid, t_point pos) {
    return (grid[pos.y][pos.x] != VOID_CHAR && grid[pos.y][pos.x] != PLAYER_CHAR);
}


void update_grid(t_game *game, t_point old_pos, t_point new_pos) {
    game->map.grid[old_pos.y][old_pos.x] = VOID_CHAR;
    game->map.grid[new_pos.y][new_pos.x] = PAWN_CHAR;
}

const char* get_reverse_direction(const char *direction)
{
    if (ft_strcmp((char *)direction, "down") == 0)
        return "up";
    else if (ft_strcmp((char *)direction, "left") == 0)
        return "right";
    else if (ft_strcmp((char *)direction, "up") == 0)
        return "down";
    else if (ft_strcmp((char *)direction, "right") == 0)
        return "left";
    else if (ft_strcmp((char *)direction, "down-right") == 0)
        return "up-left";
    else if (ft_strcmp((char *)direction, "down-left") == 0)
        return "up-right";
    else if (ft_strcmp((char *)direction, "up-right") == 0)
        return "down-left";
    else if (ft_strcmp((char *)direction, "up-left") == 0)
        return "down-right";
    return direction; // Default return the same direction if not recognized
}

int is_position_valid(t_game *game, t_point pos, t_pawn_movement *pawn) {
    return !(pos.x < 0 || pos.x >= game->map.size.x || pos.y < 0 || pos.y >= game->map.size.y ||
             !ft_is_position_free_for_pawn(game->map.grid, pos) ||
             ft_absolute_value(pos.x - pawn->initial_position.x) > pawn->steps_need ||
             ft_absolute_value(pos.y - pawn->initial_position.y) > pawn->steps_need);
}

void handle_returning(t_game *game, t_pawn_movement *pawn)
{
	if (!pawn->is_active) {
        return; // Skip processing if the pawn is not active
    }

    const char *reverse_direction = get_reverse_direction(pawn->direction);

    t_point next_pos = get_next_position(pawn->current_position, reverse_direction);

    if (game->map.grid[next_pos.y][next_pos.x] == PLAYER_CHAR) {
        game->map.grid[pawn->current_position.y][pawn->current_position.x] = VOID_CHAR;
		ft_player_get_hit(game);
		ft_camera_shake(game);
        pawn->is_active = 0;
        return;
    }

    if (!is_position_valid(game, next_pos, pawn) ||
        (pawn->current_position.x == pawn->initial_position.x && pawn->current_position.y == pawn->initial_position.y)) {
        pawn->is_returning = 0;
    } else {
        update_grid(game, pawn->current_position, next_pos);
        pawn->current_position = next_pos;
    }
}

void handle_movement(t_game *game, t_pawn_movement *pawn)
{
    if (!pawn->is_active) {
        return; // Skip processing if the pawn is not active
    }

    t_point next_pos = get_next_position(pawn->current_position, pawn->direction);

    if (game->map.grid[next_pos.y][next_pos.x] == PLAYER_CHAR) {
        game->map.grid[pawn->current_position.y][pawn->current_position.x] = VOID_CHAR;
	   ft_player_get_hit(game);
        pawn->is_active = 0;
        return;
    }
    if (!is_position_valid(game, next_pos, pawn)) {
        pawn->is_returning = 1;
    } else {
        update_grid(game, pawn->current_position, next_pos);
        pawn->current_position = next_pos;

        if (pawn->current_position.x == pawn->target_position.x && pawn->current_position.y == pawn->target_position.y) {
            pawn->is_returning = 1;
        }
    }
}

void move_pawn(t_game *game) {
    int index = 0;
    while (index < game->map.info.nbr_pawn) {
        t_pawn_movement *pawn = &game->pawn.pawns_array[index];

        if (pawn->is_returning) {
            handle_returning(game, pawn);
        } else {
            handle_movement(game, pawn);
        }
        index++;
    }
}

// void move_pawn(t_game *game) {
//     int index;
//     const char *reverse_direction;
//     t_point next_pos;
//     t_pawn_movement *pawn;

//     index = 0;
//     while (index < game->map.info.nbr_pawn) {
//         pawn = &game->pawn.pawns_array[index];

//         if (pawn->is_returning) {
//             reverse_direction = get_reverse_direction(pawn->direction);
//             next_pos = get_next_position(pawn->current_position, reverse_direction);

//             // Check if returning movement is valid
//             if (next_pos.x < 0 || next_pos.x >= game->map.size.x || next_pos.y < 0 || next_pos.y >= game->map.size.y ||
//                 !ft_is_position_free_for_pawn(game->map.grid, next_pos) ||
//                 (pawn->current_position.x == pawn->initial_position.x && pawn->current_position.y == pawn->initial_position.y)) {
//                 // If back to initial position or obstacle, stop returning
//                 pawn->is_returning = 0;
//             } else {
//                 update_grid(game, pawn->current_position, next_pos);
//                 pawn->current_position = next_pos;
//             }
//         } else {
//             // Calculate the next position based on the pawn's direction
//             next_pos = get_next_position(pawn->current_position, pawn->direction);

//             // Check if the next position is valid
//             if (next_pos.x < 0 || next_pos.x >= game->map.size.x || next_pos.y < 0 || next_pos.y >= game->map.size.y ||
//                 !ft_is_position_free_for_pawn(game->map.grid, next_pos) ||
//                 ft_absolute_value(next_pos.x - pawn->initial_position.x) > pawn->steps_need ||
//                 ft_absolute_value(next_pos.y - pawn->initial_position.y) > pawn->steps_need) {
//                 // If obstacle or out of steps limit, start returning int ft_ft_absolute_valueolute_value(int value)
//                 pawn->is_returning = 1;
//             } else {
//                 update_grid(game, pawn->current_position, next_pos);
//                 pawn->current_position = next_pos;

//                 // Check if the target position is reached
//                 if (pawn->current_position.x == pawn->target_position.x && pawn->current_position.y == pawn->target_position.y) {
//                     pawn->is_returning = 1;
//                 }
//             }
//         }
//        	// printf("Pawn %d moved to [%d, %d]\n", index, pawn->current_position.x, pawn->current_position.y);
//         index++;
//     }
// }
