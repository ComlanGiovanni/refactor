/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:12:49 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 17:39:18 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 *
 * 		Gamers can feel when developers are passionate about their games.
 * 				They can s
 * smell it like a dog smells fear.
 * 			Don't be afraid to hold onto your unique vision:
 * 		Just be aware that it may not turn out exactly how you envisioned.
 *
 * 							-[Scott Rogers]-
 *  		> norminette bonus_* inc_* src_* lib main_*
 *
 * @param argc
 * @param argv
 * @param envp
 * @return int
 */
int	main(int argc, char *argv[], char **envp)
{
	t_game	*game;

	if (argc != 2)
		ft_print_no_arg();
	else
	{
		ft_check_env(envp);
		game = ft_calloc(sizeof(t_game), sizeof(t_game));
		if (game == NULL)
			ft_print_error(MALLOC_GAME_ERROR, game);
		ft_init_game(game, argv[1]);
		mlx_do_key_autorepeaton(game->mlx);
		mlx_hook(game->win, LINUX_KEY_PRESS, TRUE, &ft_input_manager, game);
		mlx_hook(game->win, LINUX_CLOSE_ICON, TRUE, &ft_exit_game, game);
		mlx_loop_hook(game->mlx, &ft_update, game);
		mlx_loop(game->mlx);
	}
	return (EXIT_SUCCESS);
}

double	ft_lerp(double start, double end, double t)
{
	return (start + t * (end - start));
}
void	ft_update_fps(t_game *game)
{
	clock_gettime(1, &game->fps.current_time);
	game->fps.elapsed = (game->fps.current_time.tv_sec
			- game->fps.last_time.tv_sec) +
		(game->fps.current_time.tv_nsec - game->fps.last_time.tv_nsec) / 1e9;
	game->fps.frame_count++;
	if (game->fps.elapsed >= 1.0)
	{
		game->fps.fps = game->fps.frame_count / game->fps.elapsed;
		game->fps.frame_count = 0;
		game->fps.last_time = game->fps.current_time;
	}
}

void	ft_zero_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_2;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_1;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_one_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_two_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_tree_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_four_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_five_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_six_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_seven_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_eight_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_nine_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_digits_animation(t_game *game)
{
	ft_zero_animation(&game->hud.digits.zero);
	ft_one_animation(&game->hud.digits.one);
	ft_two_animation(&game->hud.digits.two);
	ft_tree_animation(&game->hud.digits.tree);
	ft_four_animation(&game->hud.digits.four);
	ft_five_animation(&game->hud.digits.five);
	ft_six_animation(&game->hud.digits.six);
	ft_seven_animation(&game->hud.digits.seven);
	ft_eight_animation(&game->hud.digits.eight);
	ft_nine_animation(&game->hud.digits.nine);
}

void	ft_play_animation(t_game *game)
{
	ft_wall_animation(&game->wall.animation);
	ft_player_animation(&game->player);
	ft_lava_animation(&game->lava.animation);
	ft_key_animation(&game->key.animation);
	ft_box_animation(&game->box.animation);
	ft_portal_n_animation(&game->portal.n);
	ft_portal_z_animation(&game->portal.z);
	ft_door_open_animation(&game->door.open);
	ft_door_closed_animation(&game->door.closed);
	ft_grass_animation(&game->grass.animation);
	if (game->player.life == 6)
		game->love.animation.current = game->love.nope;
	else
		ft_love_animation(&game->love.animation);
	ft_digits_animation(game);
}

/**
 * @brief
 *
 * this fct is call every time int loop by mlx_loop_hook
 * and trigger the animation of wall player lava love key door
 * and then render the new sprite for each elem by cleaning the win
 * and printing again line by line all the sprite and also print a
 * hud type for player info in the windows
 *
 * put just before for lava moving all the time ft_random_lava_move(game);
 * my bad i dix it look in the comment to change the game dynamic
 *
 * usleep(25000); is for linux wack pc for validation
 * //make a fct to return the good usleep in fonction of the limitation
 * //fps limiation usleep(game->fps.limitation); usleep(15000);
 *
 * @param game
 * @return int
 */
int	ft_update(t_game *game)
{
	ft_update_fps(game);
	ft_update_camera(game);
	ft_play_animation(game);
	//ft_draw_sprite(game, game->grass.animation.current, 500, 500);
	if ((game->map.info.nbr_key == game->player.storage) && !game->finished)
	{
		game->finished = 1;
		system("cvlc sounds/FinishLevel.wav &");
	}
	mlx_clear_window(game->mlx, game->win);
	ft_put_sprites_by_line(game);
	//ft_put_buffer_image(game);
	//mlx_put_image_to_window(game->mlx, game->win, game->window.img, 0, 0);
    //mlx_destroy_image(game->mlx, game->window.img);
	ft_print_info_on_window(game);
	//system("clear");
	//ft_print_display_grid(game->map.grid);
	return (EXIT_SUCCESS);
}

void	ft_update_camera(t_game *game)
{
	game->camera.lerp_speed = 0.02;
	game->camera.target.x = (game->player.movement.current_position.x
			* IMG_SIZE) - ((game->width * IMG_SIZE) / 4);
	game->camera.target.y = (game->player.movement.current_position.y
			* IMG_SIZE) - ((game->height * IMG_SIZE) / 4);
	game->camera.current.x = ft_lerp(game->camera.current.x,
										game->camera.target.x,
										game->camera.lerp_speed);
	game->camera.current.y = ft_lerp(game->camera.current.y,
										game->camera.target.y,
										game->camera.lerp_speed);
}

/**
 * @brief
 *
 * 		This fct set all the player stat in game.player[]
 * 				1 life because 1 is enough
 * 			0 for storage step  and the frames is 9
 * 				after several test 9 feel good
 * 		we also generate randomly a direction of the first
 * 			int of the player to give player more life
 * 		we use srand rand of 4 digit (up down left right)
 * 						u d l r
 *
 * @param game
 */
void	ft_init_player_info(t_game *game)
{
	game->player.life = 3;
	game->player.storage = FALSE;
	game->player.step = 0;
	game->player.storage = FALSE;
	game->player.movement.moved = FALSE;
	game->player.movement.current_position.x = FALSE;
	game->player.movement.current_position.y = FALSE;
	ft_direction_by_pos_after_launch(game);
}

void	ft_display_digits_sprites(t_game *game, char *digits_str,
		t_point position)
{
	int		index;
	index = 0;
	while (digits_str[index] != '\0')
	{
		if ((digits_str[index] - '0') >= 0 && (digits_str[index] - '0') <= 9)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->hud.digits.tab[(digits_str[index] - '0')],
					position.x, position.y);
			position.x += 24;
		}
		index++;
	}
}

/**
 * @brief
 *
 * 	we display a itoa o step storage on the win and free it the end
 * 	we print all info in color define in the define header
 * 	we can make a fct for the print of up down life right but iam lazy
 * 	so in fct of the char in game->player.direction we print the
 * 	full word in color
 *
 * //mlx_string_put(game->mlx, game->win, 5, game->height - 10,
 * //YELLOW, "Press [Esc]-key to Rage-Quit");
 *
 * @param game
 */
void	ft_print_info_on_window(t_game *game)
{
	game->hud.str_step = ft_itoa(game->player.step);
	//game->hud.str_storage = ft_itoa(game->player.storage);
	game->hud.str_fps = ft_itoa(game->fps.fps);
	game->hud.str_key_remain = ft_itoa(game->map.info.nbr_key
			- game->player.storage);
	ft_display_life_on_windows(game);
	ft_display_digits_sprites(game, game->hud.str_step, game->hud.step);
	ft_display_digits_sprites(game, game->hud.str_fps, game->hud.fps);
	ft_display_digits_sprites(game, game->hud.str_key_remain, game->hud.keys);
	//ft_display_step_on_widows(game);
	// mlx_string_put(game->mlx, game->win, 5, 42, YELLOW, "Step-> ");
	// mlx_string_put(game->mlx, game->win, 69, 42, RED, game->hud.str_step);
	// mlx_string_put(game->mlx, game->win, 5, 52, RED, "Storage-> ");
	// mlx_string_put(game->mlx, game->win, 69, 52, RED,
	//			game->hud.str_storage );
	// mlx_string_put(game->mlx, game->win, 5, 62, AQUA, "Facing-> ");
	// if (game->player.storage == game->map.info.nbr_key) // the fuck is this ?
	// 	mlx_string_put(game->mlx, game->win, 69, 52, GREEN,
	//				game->hud.str_storage );
	// if (game->player.movement.direction == 'u')
	// 	mlx_string_put(game->mlx, game->win, 69, 62, LIME, "Up");
	// if (game->player.movement.direction == 'd')
	// 	mlx_string_put(game->mlx, game->win, 69, 62, YELLOW, "Down");
	// if (game->player.movement.direction == 'l')
	// 	mlx_string_put(game->mlx, game->win, 69, 62, PINK, "Left");
	// if (game->player.movement.direction == 'r')
	// 	mlx_string_put(game->mlx, game->win, 69, 62, TURQUOISE, "Right");
	// mlx_string_put(game->mlx, game->win, 62, 90, TURQUOISE, "FPS -> ");
	// mlx_string_put(game->mlx, game->win, 90, 90, TURQUOISE,
	//			game->hud.str_fps);
	//add lke esc, indication for deplacement
	ft_free_step_and_storage(game);
}

/*

			PERSONAL COMMENT IDEAD RANDOM STUFF

						/\     \
                      /  \     \
                     /    \_____\
                    _\    / ____/_
                   /\ \  / /\     \
                  /  \ \/_/  \     \
                 /    \__/    \_____\
                _\    /  \    / ____/_
               /\ \  /    \  / /\     \
              /  \ \/_____/\/_/  \     \
             /    \_____\    /    \_____\
            _\    /     /    \    / ____/_
           /\ \  /     /      \  / /\     \
          /  \ \/_____/        \/_/  \     \
         /    \_____\            /    \_____\
        _\    /     /            \    / ____/_
       /\ \  /     /              \  / /\     \
      /  \ \/_____/                \/_/  \     \
     /    \_____\                    /    \_____\
    _\    /     /_  ______  ______  _\____/ ____/_
   /\ \  /     /  \/\     \/\     \/\     \/\     \
  /  \ \/_____/    \ \     \ \     \ \     \ \     \
 /    \_____\ \_____\ \_____\ \_____\ \_____\ \_____\
 \    /     / /     / /     / /     / /     / /     /
  \  /     / /     / /     / /     / /     / /     /
   \/_____/\/_____/\/_____/\/_____/\/_____/\/_____/

		[Dont work harder work smarter]
			[TODO IF NOT TOO LAZY]

*		rename all file name with prefix ft_
*		for bonus use mlx string pu with a
		special font or sprite like life
*		put commun fct in spefic file to share
			btw bonus and mandatory
*	read all the project to found repetition
			and make 5 in 1 ex :
  		try to make modularity for move ?
*		share define or define file for mandatory
*	better file organisation and include order
* 		add start and end windows
* 			status iddle or mouving
* 		ft_print_spite_error char path
* 			ft_split_path char * path
* 		reset button r to reload the game
* 			try to limit int overflow long long
			or life storage limit
* 			versus mode 1v1
* 		make file cross platform
				make linux make os

* 		make a simple step by step for 100
* 			make a simple step by step for bonus
* 		mlx_get_screen_size

		//ft_free_all(game);
		//ft_print_error(USAGE_MSG, game);



			[WHAT I HAVE FOUND]

			ImageMagick
		convert key.xpm -scale 64x64 key.xpm
//mlx_key_hook(game->win, &ft_input_manager, game);

#	@make --no-print-directory -C ft_printf
#	@make --no-print-directory -C mlx lib_so_long.a

-L$./mlx-linux/ -lmlx -lXext -lX11
 -L$./MLX_MAC/ -lmlx -framework OpenGL -framework AppKit

FLAGS += -I$(MLXDIR)
//mlx_do_key_autorepeatoff(game->mlx);
OS := $(shell uname)

 ifeq ($(OS),Darwin)
	MLXDIR = $(MACDIR)
	MLXFLAGS = $(MACFLAGS)
else ifeq ($(OS),Linux)
	MLXDIR = $(LINUXDIR)
	MLXFLAGS = $(LINUXFLAGS)
else
$(error Incompatable OS Detected)
endif




# 		$(GCC) -o $(NAME) $(SRC) -L.
$(LIB_NAME) -L. $(MLX_PATH)/$(MLX_NAME) $(FRAME_WORK)
# 		-lXext -lX11

 		$(GCC) $(SRC) $(INC) $(OBJ)
 			-Lmlx_linux -lmlx_Linux -L/usr/lib
 		-Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

			[DEFENSE]
		-g3 -fsanitize=addres
		envi -i check necessaire ??

			[IDEA]

				konamie code
	konami code for invisibility on everyting

	moving ennemie (maybe tracing)
	* Theme song
		* song when take item
			* song when die
* try to nake a difference btw normal iddel instant and delay iddle
*	random idea : save the file name in struc
		to display it in error msg
IDEAD : add timer counter because frame is every seconde in upadte ???

//random idea : save the file name in struc to display it in error msg

place pillar instead of wall inside the map only

add versus mode only 2 player
Jai envie dajouter un timer, un vs mode un stysteme
 de path founding pour les ennemies

*/

/*
			IDEA

    on parcour la  map
    si inc une valeur pur trouver la position de p
    si on trouve l position on arrete et on sort de la boucle
    on a pas bessoin de verifier que p existe dans la map on
    le fait deja dan check playabibliity

    du coup si la pos de p est sup a a la moitier de la longeur
    de la map on regarde a gquche don l
        sinon r
        et si on est au mileu top on regarde vers le baa
        milieu bas on regarde vers le haut

        0                           0
            r       d           l


            r        u          l

        0                           0

    Just realiszed that i could like the face only if there is nothing in face
    managee case where he can not move
        like defaut looking or looking by the pos in map

*/

/*
				IDEAD
		DIAGONAL MOVE IF 7 9 1 3 is pressed
	fct who combine move (up + left) by the  vailableness up up or let etc


    else
        iddle animation counter 5 sec

*/

/*
	not a problem but for future futur me with more skill
	there is a astetic problem of the print diirectly on the
	windows, cool if you can make a more cool way to see it i
	dont realy know

		idea font or sprite for step
		or info like ft_print_game_info)
		on screen
		with a map tracking only if there
		is a camera zoom
*/

/*
			int temp;
			int temp1;
			int temp11;
			int temp111;
	Because using temp2, temp3 would be too mainstream.
			char coal
			float away;
			long long ago;
			char mander;
	long timeAgo;	// In a galaxy far far away
			bool dozer;
			int erNalExam;
			short circuit;
			short onTime;
			double trouble;
Exception	up = new Exception("Something is wrong");
			throw up;
*/

//mlx_hook(game->win, MAC_KEY_PRESS, FALSE, &ft_input_manager, game);
/*
		mlx_loop_hook(game.mlx, sl_loop_hook, &game);
		int	key_press_hook(unsigned long keysym, t_game *game)
		int	key_press_hook(unsigned long keysym, t_game *game)

			mlx_hook(game.win, 2, 1 << 0, key_press_hook, &game);
	mlx_hook(game.win, 3, 1 << 1, key_release_hook, &game);

			if (keysym == UP_KEY)
		game->lvl.press_up = true;
	else if (keysym == LEFT_KEY)
		game->lvl.press_left = true;
	else if (keysym == DOWN_KEY)
		game->lvl.press_down = true;
	else if (keysym == RIGHT_KEY)
		game->lvl.press_right = true;

		*/
