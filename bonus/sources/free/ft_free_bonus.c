/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:17:50 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 17:29:27 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

/**
 * @brief
 *
 * 			Just exit the window by destroying
 * 		mlx and win with mlx_destroy_window and return
 * 			0 -> EXIT_SUCCESS hummm we exit the game
 * 		when we press esc so the exit for me is SUCCESS
 * 			think its good, this fct is call when
 * 				the mlx_hook in the game is trigger
 * 				by the x mask 17 -> CLOSE_ICON
 *
 * 		for ft_exit_game ft_win_game we should free the game malloc
 * 			if need send t_game * game to ft_print_error
 * 				for good free for linux version
 *
 * 			mlx_destroy_window(game->mlx, game->win);
 *
 * @param game
 * @return int
 */
int	ft_exit_game(t_game *game)
{
	//system("pkill vlc");
	system("pkill aplay");
	ft_printf("\n Game exited \n");//ascii art like win and lose
	ft_free_all(game);
	exit(EXIT_SUCCESS);
}

/**
 * @brief
 *
 * 		This fct is called only when the player win the game
 * 			so we print the number of step a the end
 * 					with a define win msg
 *
 * 		we also print the storage and the life of the player
 *
 *  			Just exit the window by destroying
 * 		mlx and win with mlx_destroy_window and return
 * 			0 -> EXIT_SUCCESS hummm we exit the game
 * 		when we player win so for me is SUCCESS var
 *
 *
 * 		for ft_exit_game ft_win_game we should free the game malloc
 * 			if need send t_game * game to ft_print_error
 * 				for good free for linux version
 *
 * 		mlx_destroy_window(game->mlx, game->win);
 *
 * @param game
 * @return int
 */

//make a fonction and add some interresting thing
int	ft_win_game(t_game *game)
{
	//system("pkill vlc");
	system("pkill aplay");
	game->player.step++;
	//ascii art for win and loos message or animation
	ft_printf(WIN_MSG "%d ", game->player.step);
	ft_printf("Storage : %d, ", game->player.storage);//put in macro header
	ft_printf("Life : %d\n", game->player.life);//put in macro header
	ft_free_all(game);
	exit(EXIT_SUCCESS);
}



/**
 * @brief
 *
 * 			This fct is call when the game->player.life is 0
 * 		this variable is dec only when we it a lava aka L see
 * 	ft_display_life_on_windows  all moving fct in -> input_bonus.c
 * 		he is set in ft_init_player_info in the main at 1
 *
 * 		we print storage at the death with the life 0 pretty dumb be meh is ok
 *
 * 		the we destroy the windows, we should probaly
 * 			free the game, check with valgrind
 * 					on the linux version
 *
 * 		return 1 because we fail hummmm legit ? or its 0
 *
 * 			mlx_destroy_window(game->mlx, game->win);
 *
 * @param game
 * @return int
 */
int	ft_lose_game(t_game *game)
{
	system("pkill aplay");
	//ascii art for win and loos message or animation
	ft_printf(LOSE_MSG "%d ", game->player.step);
	ft_printf("Storage : %d, ", game->player.storage);
	ft_printf("Life : %d\n\n", game->player.life);
	//ft_free_step_and_storage(game);
	ft_free_all(game);
	exit(EXIT_FAILURE);
}

void ft_free_pawns_array(t_game *game)
{
	//ft_free_pawns_array(game);
    // Free the allocated pawns array only once
    if (game->pawn.pawns_array)
    {
        free(game->pawn.pawns_array);
        game->pawn.pawns_array = NULL; // Set to NULL to avoid dangling pointer
    }
}

/**
 * @brief
 *
 * 	Free of last minutes, need to read the project again for better free fct
 * 	we need to free all the image load in sprites before so we check and free
 * 	then the map in str (alway check if exist)
 * 	then we destroy the game (mlx, win)
 * 	then the display (mlx)
 * 	and at the end we need to free the mlx and the game we malloc in the main
 *
 *
 * @param game
 */
void	ft_free_all(t_game *game)
{
	//add free pawn
	mlx_loop_end(game->mlx);
	ft_free_pawns_array(game);
	ft_free_animation(game);
	ft_free_sprites_list(&game->node, game->mlx);
	if (game->map.map_str)
		free(game->map.map_str);
	if (game->map.grid)
		ft_clean_grid_map(game->map.grid, game->height);
	ft_free_mlx(game);
}

void	ft_free_mlx(t_game *game)
{
	if (game->window.img)//usless if no buffering
		mlx_destroy_image(game->mlx, game->window.img);
	if (game->window.img_data)//usless if no buffering
		free(game->window.img);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game)
		free(game);
}


void	ft_free_sprites_list(t_sprite_node **head, void *mlx)
{
	t_sprite_node	*current;
	t_sprite_node	*next;

	current = *head;
	while (current)
	{
		if (current->frame)
		{
			mlx_destroy_image(mlx, current->frame);
			current->frame = NULL;
		}
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

void	ft_free_animation(t_game *game)
{
	ft_free_ground(game);// add this to node and remove this fct
	ft_free_sprites_list(&game->node, game->mlx);
}

/* add this with the fct and check it there is no use of this */

void	ft_free_sprite_frame(void **frame, void *mlx)
{
	if (*frame)
	{
		mlx_destroy_image(mlx, *frame);
		*frame = NULL;
	}
}

void	ft_free_ground(t_game *game)
{
	ft_free_sprite_frame((void **)&game->map.ground, game->mlx);
}

/* add this with the fct and check it there is no use of this */

void	ft_free_step_and_storage(t_game *game)
{
	if (game->hud.str_step != NULL)
		free(game->hud.str_step);
	if (game->hud.str_fps != NULL)
		free(game->hud.str_fps);
	if (game->hud.str_key_remain != NULL)
		free(game->hud.str_key_remain);
}
