/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus_linux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:11 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/31 20:37:18 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 *
 * 		this fct will be trigger by mlx_hook in the main
 * 	mlx_hook is alway listening if there i KEY_PRESS -> 2 x_event
 * the send it to input manager as a int, look at the mlx_hook
 * 	prototype, the here i manager wasd up down left right arrow
 * 				and also 4 8 6 2 pav num
 * 		those are set in the enumeration in .h  t_key_code
 *
 * for each direction we call the good fct and seed the t_game pointer
 * 			alway returning 0 -> EXIT_SUCCESS
 *
 *
 *  //recup key_code and put in game struct
 *
 * @param key_code
 * @param game
 * @return int
 */
int	ft_input_manager(int key_code, t_game *game)
{
	//remove if we need to press to moved
	ft_random_lava_move(game);
	if (key_code == LINUX_ESC_KEY)
		ft_exit_game(game);
	if ((key_code == LINUX_W_KEY || key_code == LINUX_UP_ARROW_KEY
			|| key_code == LINUX_UP_PAV_NUM_KEY))
		ft_input_up(game);
	if ((key_code == LINUX_S_KEY || key_code == LINUX_DOWN_ARROW_KEY
			|| key_code == LINUX_DOWN_PAV_NUM_KEY))
		ft_input_down(game);
	if ((key_code == LINUX_A_KEY || key_code == LINUX_LEFT_ARROW_KEY
			|| key_code == LINUX_LEFT_PAV_NUM_KEY))
		ft_input_left(game);
	if ((key_code == LINUX_D_KEY || key_code == LINUX_RIGHT_ARROW_KEY
			|| key_code == LINUX_RIGHT_PAV_NUM_KEY))
		ft_input_right(game);
	//ft_print_game_info(game);
	return (EXIT_SUCCESS);
}

void	play_movement_sound(t_game *game)
{
	game->player.step++;
	// if ((game->fps.current_time.tv_sec - game->fps.last_time.tv_sec) > 1.0)
	system("cvlc sounds/baba-move.wav &");
}

void	ft_player_take_coin(t_game *game)
{
	game->player.storage++;
	system("cvlc sounds/babatakekey.wav &");
}

void	ft_player_take_life(t_game *game)
{
	game->player.life++;
	system("cvlc sounds/baba_take_life.wav &");
}

void	ft_camera_shake(t_game *game)
{
	double	shake_offset_x;
	double	shake_offset_y;
	double	shake_time;

	double shake_intensity = 30; // Adjust the intensity of the camera shake
	double shake_speed = 1.0;    // Adjust the speed of the camera shake
	shake_offset_x = sin(game->fps.elapsed * shake_speed) * shake_intensity;
	double shake_duration = 4.84; // Duration of the camera shake in seconds
	shake_offset_y = 0.0;
	shake_time = fmod(game->fps.elapsed, shake_duration);
	shake_offset_y = sin(shake_time * shake_speed) * shake_intensity;
	game->camera.current.x += shake_offset_x;
	game->camera.current.y += shake_offset_y;
}

void	ft_player_get_hit(t_game *game)
{
	game->player.life--;
	system("cvlc sounds/baba_take_damage.wav &");
	ft_camera_shake(game);
}

void	ft_baba_forbidden(t_game *game)
{
	ft_camera_shake(game);
}

void	ft_handle_tile_action(t_game *game, char next_tile)
{
	if (next_tile == LOVE_CHAR)
	{
		// Only take the life if player has less than 6 lives
		if (game->player.life < 6)
			ft_player_take_life(game);
		else {
			ft_baba_forbidden(game); // Indicate that life cannot be taken
			return;
		}
	}
	// Handle taking coins only if the player's life is less than 6
	if (next_tile == KEY_CHAR)
	{
		ft_player_take_coin(game);
	}
	if (next_tile == LAVA_CHAR)
	{
		ft_player_get_hit(game);
	}
	if (next_tile == EXIT_CHAR
		&& game->map.info.nbr_key == game->player.storage)
	{
		ft_win_game(game);
	}
}

/**
 * @brief
 *
 *  the player is never at map[0] so we can idx++ right away in the first line
 * 	so if we found the p char we get out of the while to manage P behaviour
 * 					-        +
 * 			str "11111PC11CE11111"  len 16 	width 	4	height 4
 * 1111
 * 1CC1		-(width) is for up because in str up is before
 * 1PE1  so game->map[idx - game->width] is the char just in font of map[idx]
 * 1111
 *
 * 		we inc storage life if KEY_CHAR LOVE_CHAR and lose life i LAVA_CHAR
 *
 * so if in front the player there is a wall or exit you can not move
 * else move the p and change the char at the previous index to void char 0
 * and the [idx - game->width] is now the player char
 *
 * 		if the player is down front of a exit and he collect all the coin
 * 			game->key == game->storage we exit the game by calling
 * 					ft_win_game(game);
 *
 *	so if we move inc step and print the game->step in console
 * 	then display again all the sprite line by line because we change position
 *
 * @param game
 */
void	ft_move_up(t_game *game)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	// double time_now = (double)clock() / CLOCKS_PER_SEC;
	//     double elapsed_time = time_now - game->last_time;
	if (y > 0)
	{
		next_tile = game->map.grid[y - 1][x];
		ft_handle_tile_action(game, next_tile);
if (next_tile != WALL_CHAR && next_tile != EXIT_CHAR && !(next_tile == LOVE_CHAR && game->player.life >= 6)) {
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y - 1][x] = PLAYER_CHAR;
			game->player.movement.current_position.y -= 1;
			play_movement_sound(game);
			// game->player.position.y -= game->player.y_speed * elapsed_time;
			// game->player.position.x += game->player.x_speed * elapsed_time;
			//ft_put_sprites_by_line(game);
				// look useleep because every update do it
			//printf("Moved down to: (%d, %d)\n", x, game->player.position.y);
			//game->last_time = time_now;
		}
	}
}

/**
 * @brief
 *
 *  the player is never at map[0] so we can idx++ right away in the first line
 * 	so if we found the p char we get out of the while to manage P behaviour
 * 					-        +
 * 			str "11111PC11CE11111"  len 16 	width 	4	height 4
 * 1111
 * 1CC1		+(width) is for down because in str down is moving forward so ++
 * 1PE1  so game->map[idx + game->width] is the char just in bottom of map[idx]
 * 1111
 *
 * 		we inc storage life if KEY_CHAR LOVE_CHAR and lose life i LAVA_CHAR
 *
 * so if in bottom the player there is a wall or exit you can not move
 * else move the p and change the char at the previous index to void char 0
 * and the [idx + game->width] is now the player char
 *
 * 		if the player is in up of a exit and he collect all the coin
 * 			game->key == game->storage we exit the game by calling
 * 					ft_win_game(game);
 *
 *	so if we move inc step and print the game->step in console
 * 	then display again all the sprite line by line because we change position
 *
 * @param game
 */
void	ft_move_down(t_game *game)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	// Vérifier si le joueur peut se déplacer vers le bas
	if (y < game->height - 1)
	{
		next_tile = game->map.grid[y + 1][x];
		if (next_tile != WALL_CHAR && !(next_tile == EXIT_CHAR
				&& game->map.info.nbr_key != game->player.storage)
			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
		{
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y + 1][x] = PLAYER_CHAR;
			play_movement_sound(game);
			game->player.movement.current_position.y += 1;
		ft_handle_tile_action(game, next_tile);
			//ft_put_sprites_by_line(game);
				// look useleep because every update do it
			//printf("Moved down to: (%d, %d)\n", x, game->player.position.y);
		}
	}
}

/**
 * @brief
 *
 *  the player is never at map[0] so we can idx++ right away in the first line
 * 	so if we found the p char we get out of the while to manage P behaviour
 * 					-        +
 * 			str "11111PC11CE11111"  len 16 	width 	4	height 4
 * 1111
 * 1CC1		-(1) is for left because in str left is moving downward so --
 * 1PE1  so game->map[idx - 1] is the char just in left of map[idx]
 * 1111
 *
 * 		we inc storage life if KEY_CHAR LOVE_CHAR and lose life i LAVA_CHAR
 *
 * so if in the of left the player there is a wall or exit you can not move
 * else move the p and change the char at the previous index to void char 0
 * and the [idx - 1] is now the player char
 *
 * 		if the player is in right of a exit and he collect all the coin
 * 			game->key == game->storage we exit the game by calling
 * 					ft_win_game(game);
 *
 *	so if we move inc step and print the game->step in console
 * 	then display again all the sprite line by line because we change position
 *ewr
 * @param game
 */
void	ft_move_left(t_game *game)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	// Vérifier si le joueur peut se déplacer vers la gauche
	if (x > 0)
	{
		next_tile = game->map.grid[y][x - 1];
if (next_tile != WALL_CHAR && next_tile != EXIT_CHAR && !(next_tile == LOVE_CHAR && game->player.life >= 6)) {
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y][x - 1] = PLAYER_CHAR;
			play_movement_sound(game);
			game->player.movement.current_position.x -= 1;
		ft_handle_tile_action(game, next_tile);
			// ft_put_sprites_by_line(game);// look useleep because every update do it
			//printf("Moved down to: (%d, %d)\n", game->player.position.x, y);
		}
	}
}

/**
 * @brief
 *
 *  the player is never at map[0] so we can idx++ right away in the first line
 * 	so if we found the p char we get out of the while to manage P behaviour
 * 					-        +
 * 			str "11111PC11CE11111"  len 16 	width 	4	height 4
 * 1111
 * 1CC1		+(1) is for right because in str left is moving forward so ++
 * 1PE1  so game->map[idx + 1] is the char just in right of map[idx]
 * 1111
 *
 * 		we inc storage life if KEY_CHAR LOVE_CHAR and lose life i LAVA_CHAR
 *
 * so if in the right of the player there is a wall or exit you can not move
 * else move the p and change the char at the previous index to void char 0
 * and the [idx - 1] is now the player char
 *
 * 		if the player is in left of a exit and he collect all the coin
 * 			game->key == game->storage we exit the game by calling
 * 					ft_win_game(game);
 *
 *	so if we move inc step and print the game->step in console
 * 	then display again all the sprite line by line because we change position
 *
 * @param game
 */
void	ft_move_right(t_game *game)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	// Vérifier si le joueur peut se déplacer vers la droite
	if (x < game->width - 1)
	{
		next_tile = game->map.grid[y][x + 1];
if (next_tile != WALL_CHAR && next_tile != EXIT_CHAR && !(next_tile == LOVE_CHAR && game->player.life >= 6)) {
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y][x + 1] = PLAYER_CHAR;
			play_movement_sound(game);
			game->player.movement.current_position.x += 1;
		ft_handle_tile_action(game, next_tile);
			//ft_put_sprites_by_line(game);// look useleep because every update do it
			//printf("Moved down to: (%d, %d)\n", game->player.position.x, y);
		}
	}
}
