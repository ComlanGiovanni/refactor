/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pawn_patrolling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:58:49 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 21:19:09 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

t_point get_next_position(t_point current, const char *direction)
{
	if (ft_strcmp((char *)direction, "down") == 0)
		current.y += 1;
	else if (ft_strcmp((char *)direction, "left") == 0)
		current.x -= 1;
	else if (ft_strcmp((char *)direction, "up") == 0)
		current.y -= 1;
	else if (ft_strcmp((char *)direction, "right") == 0)
		current.x += 1;
	else if (ft_strcmp((char *)direction, "down-right") == 0)
	{
		current.x += 1;
		current.y += 1;
	} else if (ft_strcmp((char *)direction, "down-left") == 0)
	{
		current.x -= 1;
		current.y += 1;
	} else if (ft_strcmp((char *)direction, "up-right") == 0)
	{
		current.x += 1;
		current.y -= 1;
	} else if (ft_strcmp((char *)direction, "up-left") == 0)
	{
		current.x -= 1;
		current.y -= 1;
	}
	return (current);
}

int ft_is_position_free_for_pawn(char **grid, t_point pos)
{
	return ((grid[pos.y][pos.x] == '0') || (grid[pos.y][pos.x] == 'P'));
}

t_point calculate_farthest_position(t_point start_position, const char *direction, t_game *game)
{
	t_point current_position;
	t_point next_position;

	current_position = start_position;
	while ("The prophecy is true !") //TRUE
	{
		next_position = get_next_position(current_position, direction);
		//put in same if
		if (next_position.x < 0 || next_position.x >= game->map.size.x || next_position.y < 0 || next_position.y >= game->map.size.y)
			break;
		if (!ft_is_position_free_for_pawn(game->map.grid, next_position))
			break;
		current_position = next_position;
	}

	return (current_position);
}

void find_farthest_position_for_pawn(t_game *game)
{
	t_point temp_farthest_position;
	t_point best_position;
	int index;
	size_t max_steps;
	const char *best_dir;
	int dir_index;
	size_t steps;

	index = 0;
	max_steps = 0;
	dir_index = 0;
	const char *dir_names[8] = {
		"down", "down-left", "left", "up-left",
		"up", "up-right", "right", "down-right"
	};
	//{"d", "dl", "l", "ul", "u", "ur", "r", "dr"};
	//l'ordre de selection de la postion la plus lointaine
	//depends de l'ords dans la quel tu calcul la plus lointaine position
	//reflechis un peu , et enlever le doublong il est temps de clean_
	while (index < game->map.info.nbr_pawn)
	{
		//ft_printf("Pawn %d at initial position [%d, %d]:\n", index, game->pawn.pawns_array[index].current_position.x, game->pawn.pawns_array[index].current_position.y);
		dir_index = 0;
		max_steps = 0;
		while (dir_index < 8)
		{
			temp_farthest_position = calculate_farthest_position(game->pawn.pawns_array[index].current_position, dir_names[dir_index], game);
			if ((ft_strcmp((char *)dir_names[dir_index], "up") == 0) || (ft_strcmp((char *)dir_names[dir_index], "down") == 0) || (ft_strcmp((char *)dir_names[dir_index], "up-left") == 0) || (ft_strcmp((char *)dir_names[dir_index], "up-right") == 0))
				steps = abs(temp_farthest_position.y - game->pawn.pawns_array[index].current_position.y);//int ft_absolute_value(int value)
			else
				steps = abs(temp_farthest_position.x - game->pawn.pawns_array[index].current_position.x);
			if (steps == 0)
				ft_printf("  No movement position in %s direction.\n", dir_names[dir_index]);
			else
				printf("  Farthest Position in %s direction: [%d, %d] with %zu steps.\n", dir_names[dir_index], temp_farthest_position.x, temp_farthest_position.y, steps);
			if (steps > max_steps || (steps == max_steps && dir_index < 8))
			{
				max_steps = steps;
				best_position = temp_farthest_position;
				best_dir = dir_names[dir_index];
				game->pawn.pawns_array[index].target_position.x = best_position.x;
				game->pawn.pawns_array[index].target_position.y = best_position.y;
				game->pawn.pawns_array[index].direction = (char *)best_dir;
				game->pawn.pawns_array[index].steps_need = max_steps;
			}
			dir_index++;
		}
		//game->pawn.pawns_array->path = (t_point *)malloc(sizeof(t_point) * max_steps);
		printf("\n\n The Farthest Position for %c in %s direction: [%d, %d] with %zu steps.\n\n",index , best_dir, best_position.x, best_position.y, max_steps);
		index++;
	}
}

// t_point get_next_position(t_point current, char direction)
// {
//     if (direction == 'd') {
//         current.y += 1;
//     } else if (direction == 'l') {
//         current.x -= 1;
//     } else if (direction == 'u') {
//         current.y -= 1;
//     } else if (direction == 'r') {
//         current.x += 1;
//     }
//     return current;
// }


// int ft_is_position_free_for_pawn(char **grid, t_point pos)
// {
//     return grid[pos.y][pos.x] == '0';
// }

// t_point calculate_farthest_position(t_point start_position, char direction, t_game *game)
// {
//     t_point current_position = start_position;

//     // Continue moving in the given direction until the pawn hits a boundary or a non-free position
//     while (1)
//     {
//         // Get the next position in the given direction
//         t_point next_position = get_next_position(current_position, direction);

//         // Check if the next position is out of bounds
//         if (next_position.x < 0 || next_position.x >= game->map.size.x ||
//             next_position.y < 0 || next_position.y >= game->map.size.y)
//         {
//             break;
//         }

//         // Check if the next position is not free (i.e., it's not '0')
//         if (!ft_is_position_free_for_pawn(game->map.grid, next_position))
//         {
//             break;
//         }

//         // Update the current position to the next valid position
//         current_position = next_position;
//     }

//     // Return the farthest valid position reached in the given direction
//     return current_position;
// }


// // Function to find and display the farthest position for each pawn
// void find_farthest_position_for_pawn(t_game *game)
// {
//     //t_point farthest_position;
//     t_point temp_farthest_position;
//    // char chosen_direction;
//     int index;

//     // Define the possible directions
//     char dir_char[4] = {'u', 'd', 'l', 'r'};
//     const char *dir_name[4] = {"up", "down", "left", "right"};

//     // Iterate through all pawns
//     for (index = 0; index < game->map.info.nbr_pawn; index++)
//     {
//         printf("Pawn %d at initial position [%d, %d]:\n",
//                index,
//                game->pawn.pawns_array[index].current_position.x,
//                game->pawn.pawns_array[index].current_position.y);

//         // Check in all directions
//         for (int i = 0; i < 4; i++)
//         {
//             temp_farthest_position = calculate_farthest_position(game->pawn.pawns_array[index].current_position, dir_char[i], game);

//             // Calculate the number of steps moved in this direction
//             size_t steps = (dir_char[i] == 'u' || dir_char[i] == 'd') ?
//                 abs(temp_farthest_position.y - game->pawn.pawns_array[index].current_position.y) :
//                 abs(temp_farthest_position.x - game->pawn.pawns_array[index].current_position.x);

//             if (steps == 0)
//                 printf("  No movement position in %s direction.\n", dir_name[i]);
//             else
//                 printf("  Farthest Position in %s direction: [%d, %d] with %zu steps.\n",
//                        dir_name[i], temp_farthest_position.x, temp_farthest_position.y, steps);
//         }
//     }
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
	for (long long int i = 0; i < game->map.info.nbr_pawn; i++)
	{
		printf("Pawn %llu - Position: (%d, %d), Target: (%d, %d), Direction: %s, Returning: %d\n\n",
               i, game->pawn.pawns_array[i].current_position.x, game->pawn.pawns_array[i].current_position.y,
               game->pawn.pawns_array[i].target_position.x, game->pawn.pawns_array[i].target_position.y,
               game->pawn.pawns_array[i].direction, game->pawn.pawns_array[i].is_returning);
	}
	find_farthest_position_for_pawn(game);
	for (long long int i = 0; i < game->map.info.nbr_pawn; i++)
	{
		printf("Pawn %llu - Position: (%d, %d), Target: (%d, %d), Direction: %s, Returning: %d\n\n",
               i, game->pawn.pawns_array[i].current_position.x, game->pawn.pawns_array[i].current_position.y,
               game->pawn.pawns_array[i].target_position.x, game->pawn.pawns_array[i].target_position.y,
               game->pawn.pawns_array[i].direction, game->pawn.pawns_array[i].is_returning);
	}
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

void ft_find_pawn_positions(t_game *game)
{
	int	x;
	int	y;
	long long int index = 0;
	//printf("[w = %d, h = %d]\n", game->map.size.x, game->map.size.y);

	if (!game || game->map.grid == NULL || game->map.size.x <= 0 || game->map.size.y <= 0)
		ft_print_error("Pawn position fail to get", game);
	y = 0;
	//x = 0;
	while (y < game->map.size.y)
	{
		if (game->map.grid[y] == NULL)
			ft_print_error("game->map.grid[y] == NULL", game);
		x = 0;
		while (x < game->map.size.x)
		{
			if (game->map.grid[y][x] == '\0')
				break ;
			if (game->map.grid[y][x] == 'W')
			{
				//printf("Pawn %llu - [x = %d, y = %d]\n\n",index, x, y);
				if (index >= game->map.info.nbr_pawn)
					ft_print_error("Too much pawn found magic is happening\n", game);
                game->pawn.pawns_array[index].initial_position = (t_point){x, y};
                game->pawn.pawns_array[index].current_position = (t_point){x, y};
                game->pawn.pawns_array[index].target_position = (t_point){x, y};
                game->pawn.pawns_array[index].direction = " ";
                game->pawn.pawns_array[index].is_returning = 0;
                game->pawn.pawns_array[index].steps_taken = 0;
                game->pawn.pawns_array[index].steps_need = 0;
                index++;
			}
			x++;
		}
		y++;
	}
	if (index < game->map.info.nbr_pawn)
		ft_print_error("Not enough pawns found", game);
}

int is_obstacle(char **grid, t_point pos) {
    return (grid[pos.y][pos.x] != VOID_CHAR && grid[pos.y][pos.x] != PLAYER_CHAR);
}


void update_grid(t_game *game, t_point old_pos, t_point new_pos) {
    game->map.grid[old_pos.y][old_pos.x] = VOID_CHAR;
    game->map.grid[new_pos.y][new_pos.x] = PAWN_CHAR;
}

const char* get_reverse_direction(const char *direction) {
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

void move_pawn(t_game *game) {
    int index;
    const char *reverse_direction;
    t_point next_pos;
    t_pawn_movement *pawn;

    index = 0;
    while (index < game->map.info.nbr_pawn) {
        pawn = &game->pawn.pawns_array[index];

        if (pawn->is_returning) {
            reverse_direction = get_reverse_direction(pawn->direction);
            next_pos = get_next_position(pawn->current_position, reverse_direction);

            // Check if returning movement is valid
            if (next_pos.x < 0 || next_pos.x >= game->map.size.x || next_pos.y < 0 || next_pos.y >= game->map.size.y ||
                !ft_is_position_free_for_pawn(game->map.grid, next_pos) ||
                (pawn->current_position.x == pawn->initial_position.x && pawn->current_position.y == pawn->initial_position.y)) {
                // If back to initial position or obstacle, stop returning
                pawn->is_returning = 0;
            } else {
                update_grid(game, pawn->current_position, next_pos);
                pawn->current_position = next_pos;
            }
        } else {
            // Calculate the next position based on the pawn's direction
            next_pos = get_next_position(pawn->current_position, pawn->direction);

            // Check if the next position is valid
            if (next_pos.x < 0 || next_pos.x >= game->map.size.x || next_pos.y < 0 || next_pos.y >= game->map.size.y ||
                !ft_is_position_free_for_pawn(game->map.grid, next_pos) ||
                abs(next_pos.x - pawn->initial_position.x) > pawn->steps_need ||
                abs(next_pos.y - pawn->initial_position.y) > pawn->steps_need) {
                // If obstacle or out of steps limit, start returning int ft_absolute_value(int value)
                pawn->is_returning = 1;
            } else {
                update_grid(game, pawn->current_position, next_pos);
                pawn->current_position = next_pos;

                // Check if the target position is reached
                if (pawn->current_position.x == pawn->target_position.x && pawn->current_position.y == pawn->target_position.y) {
                    pawn->is_returning = 1;
                }
            }
        }
       	// printf("Pawn %d moved to [%d, %d]\n", index, pawn->current_position.x, pawn->current_position.y);
        index++;
    }
}





// void handle_returning_pawn(t_pawn_movement *pawn, t_game *game) {

// int is_obstacle(char **grid, t_point pos, char player_char) {
//     obstacle is exeything exept CHAR_PLAYER 'P'
// }

// void move_pawn(t_pawn_movement *pawn, t_game *game) {

//     if (is_obstacle(game->map.grid, next_pos, PLAYER_CHAR)) {
//         pawn->is_returning = 1; // If obstacle is encountered, return to initial position
//     } else {
//         update_grid(game, pawn->current_position, next_pos, PAWN_CHAR, VOID_CHAR);

//             pawn->is_returning = 1; // Start returning after reaching the target
//     }
// }

// // Main function to move pawn to target
// void move_pawn_to_target(t_pawn_movement *pawn, t_game *game) {
//     if (pawn->is_returning) {
//         handle_returning_pawn(pawn, game);
//     } else {
//         move_pawn(pawn, game);
//     }
// }

// // Function to update the grid after a pawn's move
// void update_grid(t_game *game, t_point old_pos, t_point new_pos, char pawn_char, char void_char)
// {
//         game->map.grid[old_pos.y][old_pos.x] = void_char;
//         game->map.grid[new_pos.y][new_pos.x] = pawn_char;
// }


// void find_pawn_positions(t_game *game)
// {
// 	int	x;
// 	int	y;
// 	long long int index = 0;
// 	printf("[w = %d, h = %d]\n", game->map.size.x, game->map.size.y);

// 	if (!game || game->map.grid == NULL || game->map.size.x <= 0 || game->map.size.y <= 0)
// 		return ; //return ((t_point){-1, -1});
// 	y = 0;
// 	x = 0;
// 	while (y < game->map.size.y)
// 	{
// 		if (game->map.grid[y] == NULL)
// 			return ;
// 			//return ((t_point){-1, -1});
// 		//x = 0;
// 		while (x < game->map.size.x)
// 		{
// 			if (game->map.grid[y][x] == '\0')
// 				break ;
// 			if (game->map.grid[y][x] == 'W')
// 			{
// 				printf("Pawn %llu - [x = %d, y = %d]\n",index, x, y);
// 				if (index >= game->map.info.nbr_pawn) {
//                     fprintf(stderr, "Error: Not enough space in pawn_array\n"); //
//                     return ;
//                 }
//                 index++;
// 				//return ((t_point){x, y});
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	//return ((t_point){-1, -1});
// }

// void find_pawn_positions(t_game *game, t_pawn_movement *pawn_array) {
//     long long int index = 0;

//     if (!game || !pawn_array || game->map.grid == NULL)
//         return ;

//     for (int y = 0; y < game->height; y++) {
//         for (int x = 0; x < game->width; x++) {
//             if (game->map.grid[y][x] == PAWN_CHAR) {
//                 // Check if we have enough space in pawn_array
//                 if (index >= game->map.info.nbr_pawn) {
//                     fprintf(stderr, "Error: Not enough space in pawn_array\n");
//                     return;
//                 }

//                 pawn_array[index].initial_position = (t_point){x, y};
//                 pawn_array[index].current_position = (t_point){x, y};
//                 pawn_array[index].target_position = (t_point){x, y}; // Initial target is the initial position
//                 pawn_array[index].direction = ' '; // No direction initially
//                 pawn_array[index].is_returning = 0; // Not returning initially
//                 index++;
//             }
//         }
//     }
// }



// Function to get the next position based on the direction
// t_point get_next_position(t_point current, char direction) {
//     if (direction == 'D') {
//         current.y += 1;
//     } else if (direction == 'L') {
//         current.x -= 1;
//     } else if (direction == 'U') {
//         current.y -= 1;
//     } else if (direction == 'R') {
//         current.x += 1;
//     }
//     return current;
// }

// // Function to check if a position is free
// int ft_is_position_free_for_pawn(char **grid, t_point pos) {
//     return grid[pos.y][pos.x] == VOID_CHAR;
// }

// // Function to check if a position contains an obstacle
// int is_obstacle(char **grid, t_point pos, char player_char) {
//     return grid[pos.y][pos.x] != player_char && grid[pos.y][pos.x] != VOID_CHAR;
// }

// // Function to calculate the farthest position in a given direction
// size_t calculate_farthest_position(char **grid, t_point current_pos, char direction, t_point *farthest_pos)
// {
//     size_t step = 0;
//     t_point next_pos = get_next_position(current_pos, direction);

//     while (ft_is_position_free_for_pawn(grid, next_pos)) {
//         current_pos = next_pos;
//         next_pos = get_next_position(current_pos, direction);
//         step++;
//     }

//     *farthest_pos = current_pos; // Set farthest position reached
//     return step;
// }

// // Function to handle returning pawns
// void handle_returning_pawn(t_pawn_movement *pawn, t_game *game) {
//     t_point next_pos;

//     if (pawn->current_position.x < pawn->initial_position.x) {
//         pawn->direction = 'R';
//     } else if (pawn->current_position.x > pawn->initial_position.x) {
//         pawn->direction = 'L';
//     } else if (pawn->current_position.y < pawn->initial_position.y) {
//         pawn->direction = 'D';
//     } else {
//         pawn->direction = 'U';
//     }

//     next_pos = get_next_position(pawn->current_position, pawn->direction);
//     if (!is_obstacle(game->map.grid, next_pos, PLAYER_CHAR)) {
//         update_grid(game, pawn->current_position, next_pos, PAWN_CHAR, VOID_CHAR);
//         pawn->current_position = next_pos;
//     }

//     if (pawn->current_position.x == pawn->initial_position.x &&
//         pawn->current_position.y == pawn->initial_position.y) {
//         pawn->is_returning = 0; // Reached the initial position
//     }
// }

// // Function to find the farthest position a pawn can move to


// // Function to move the pawn in the chosen direction
// void move_pawn(t_pawn_movement *pawn, t_game *game) {
//     t_point next_pos = get_next_position(pawn->current_position, pawn->direction);

//     if (is_obstacle(game->map.grid, next_pos, PLAYER_CHAR)) {
//         pawn->is_returning = 1; // If obstacle is encountered, return to initial position
//     } else {
//         update_grid(game, pawn->current_position, next_pos, PAWN_CHAR, VOID_CHAR);
//         pawn->current_position = next_pos;

//         if (pawn->current_position.x == pawn->target_position.x &&
//             pawn->current_position.y == pawn->target_position.y) {
//             pawn->is_returning = 1; // Start returning after reaching the target
//         }
//     }
// }

// // Main function to move pawn to target
// void move_pawn_to_target(t_pawn_movement *pawn, t_game *game) {
//     if (pawn->is_returning) {
//         handle_returning_pawn(pawn, game);
//     } else {
//         find_farthest_position_for_pawn(pawn, game);
//         move_pawn(pawn, game);
//     }
// }

// // Function to update the grid after a pawn's move
// void update_grid(t_game *game, t_point old_pos, t_point new_pos, char pawn_char, char void_char) {
//     // Ensure position is within grid bounds
//     if (old_pos.x >= 0 && old_pos.y >= 0 && old_pos.x < game->width && old_pos.y < game->height) {
//         game->map.grid[old_pos.y][old_pos.x] = void_char;
//     }

//     if (new_pos.x >= 0 && new_pos.y >= 0 && new_pos.x < game->width && new_pos.y < game->height) {
//         game->map.grid[new_pos.y][new_pos.x] = pawn_char;
//     }
// }

// // void	*ft_memset(void *b, int c, size_t len)
// // {
// // 	size_t			idx;
// // 	unsigned char	*s;

// // 	if (!b)
// // 		return (NULL);
// // 	idx = 0;
// // 	s = (unsigned char *)b;
// // 	while (idx < len)
// // 	{
// // 		s[idx] = c;
// // 		idx++;
// // 	}
// // 	return (s);
// // }

// Function to manage the movement of all pawns
// void ft_pawn_movement(t_game *game)
// {
// 	size_t number_of_pawns;
// 	size_t i = 0;
// 	t_pawn *pawns;

// 	number_of_pawns = game->map.info.nbr_pawn;
//     pawns = init_pawns(number_of_pawns);
//     if (!pawns)
// 		return;
// 	//ft_memset(pawns, 0, number_of_pawns);
//     // Find initial positions of all pawns
//     find_pawn_positions(game, pawns->pawn_array);

//     // Movement logic
// 	while (i < number_of_pawns)
// 	{
//         printf("Pawn %zu - Position: (%d, %d), Target: (%d, %d), Direction: %c, Returning: %d\n",
//                i, pawns->pawn_array[i].current_position.x, pawns->pawn_array[i].current_position.y,
//                pawns->pawn_array[i].target_position.x, pawns->pawn_array[i].target_position.y,
//                pawns->pawn_array[i].direction, pawns->pawn_array[i].is_returning);
// 		i++;
// 	}
// 	find_farthest_position_for_pawn(pawns->pawn_array, game);
// 	//move_pawn_to_target(&pawns->pawn_array[i], game);
//     // Free memory after movement processing
//     free_pawns(pawns);
// }



// // printf("Pawn %zu - Position: (%d, %d), Target: (%d, %d), Direction: %c, Returning: %d\n",
// //        i, pawn->current_position.x, pawn->current_position.y,
// //        pawn->target_position.x, pawn->target_position.y,
// //        pawn->direction, pawn->is_returning);
// // void update_grid(t_game *game, t_point old_pos, t_point new_pos, char pawn_char, char void_char) {
// //     // Remove pawn from old position
// //     if (old_pos.x >= 0 && old_pos.y >= 0 && old_pos.x < game->map.size.x && old_pos.y < game->map.size.y) {
// //         game->map.grid[old_pos.y][old_pos.x] = void_char;
// //     }

// //     // Place pawn at new position
// //     if (new_pos.x >= 0 && new_pos.y >= 0 && new_pos.x < game->map.size.x && new_pos.y < game->map.size.y) {
// //       	game->map.grid[new_pos.y][new_pos.x] = pawn_char;
// //     }
// // }
