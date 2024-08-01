/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus_linux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:55 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 18:40:04 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 * 			map str is not the game->map struct
 *
 * 	first we need the height of the map to check if the map is well formatted
 * 		before reading it, then re-open the file to get every line in the
 * 			line variable.		(secure the open with a print message)
 * 		just before joining every line we initialized all the map info
 * 			step height width to 0 and map to the first line of the map with a
 * 						custom strdup of first line.
 * 	when we are able to open the map on READONLY we can get the next line of the
 * 		map aka the first line, we can now join the next line until the end
 * 			to the game->map(str), then free and close the fd
 * 							the get the full len of it
 *
 * @param game
 * @param map_name
 */
void	ft_read_map(t_game *game, char *map_name)
{
	int		fd;
	int		height;
	char	*line;

	height = get_map_height(map_name, game);
	check_ber_format(map_name, height, game);
	if (game->empty_line == 1)
		ft_print_error(EMPTY_LINE, game);
	fd = open(map_name, O_RDONLY);
	if (fd <= FALSE)
		ft_print_error(FAIL_OPEN_ERROR, game);
	line = get_next_line(fd);
	ft_init_map_info(game, line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
			game->map.map_str = ft_custom_strjoin(game->map.map_str, line);
	}
	close(fd);
	game->map.len = ft_strlen(game->map.map_str);
	game->map.size.x = game->width;
	game->map.size.y = game->height;
}

void	ft_print_map_info(t_game *game)
{
	ft_printf("[All item in map Number]\n\n");
	ft_printf("Player : [%c] -> {%d}\n", PLAYER_CHAR,
			game->map.info.nbr_player);
	ft_printf("wall   : [%c] -> {%d}\n", WALL_CHAR, game->map.info.nbr_wall);
	ft_printf("Void   : [%c] -> {%d}\n", VOID_CHAR, game->map.info.nbr_void);
	ft_printf("Life   : [%c] -> {%d}\n", LOVE_CHAR, game->map.info.nbr_love);
	ft_printf("Lava   : [%c] -> {%d}\n", LAVA_CHAR, game->map.info.nbr_lava);
	ft_printf("Key    : [%c] -> {%d}\n", KEY_CHAR, game->map.info.nbr_key);
	ft_printf("Exit   : [%c] -> {%d}\n", EXIT_CHAR, game->map.info.nbr_exit);
	ft_printf("Box    : [%c] -> {%d}\n", BOX_CHAR, game->map.info.nbr_box);
	ft_printf("Portal : [%c] -> {%d}\n", BOX_CHAR, game->map.info.nbr_portal_1
			+ game->map.info.nbr_portal_2);
	ft_printf("Border : [%c] -> {%d}\n\n", BORDER_CHAR,
			game->map.info.nbr_border);
}

void	ft_check_map(t_game *game)
{
	ft_map_fit_screen(game);
	ft_check_valid_char(game);
	ft_check_rectangular(game);
	ft_check_sealed(game);
	ft_init_game_info(game);
	ft_get_info_map(game);
	ft_check_playability(game);
	ft_check_map_finishable(game);
}

void	ft_init_game_info(t_game *game)
{
	game->map.info.nbr_player = FALSE;
	game->map.info.nbr_key = FALSE;
	game->map.info.nbr_exit = FALSE;
	game->map.info.nbr_lava = FALSE;
	game->map.info.nbr_love = FALSE;
	game->map.info.nbr_wall = TRUE;
	game->map.info.nbr_void = FALSE;
	game->map.info.nbr_box = FALSE;
	game->map.info.nbr_border = FALSE;
	game->map.info.nbr_portal_1 = FALSE;
	game->map.info.nbr_portal_2 = FALSE;
	game->map.border_width = BORDERS_WIDTH;
}

/**
 * @brief
 * 					11111CC11PE11111
 *
 * 1111	(game->map_len - game->width) 11111CC11PE * [11111] (idx near end)
 * 1CC1 (idx < game->width) [1111] * 1CC11PE11111 (idx less)
 * 1PE1	(idx % game->width == 0 || idx % game->width == game->width - 1)
 * 1111			(1111) [1CC1] [1PE1] (1111)
 *
 * 			*      *
 * 		[1CC1] [1PE1]	the first idx modulo width is alway 0
 * 						because we alway add the width because
 * 						its a perfect form square rectangle
 * 			*		*
 * 		[1CC1] [1PE1]	this last idx of a line modulo of width
 * 						is alway equal to width - 1 because
 * 						we are almost near to the next whose
 * 						modulo is 0 cf above
 *
 * 		first if it's for the last width bottom of map
 * 		second if it's for the first width top of the map
 * 		third if is for
 *
 *
 * @param game
 */
void	ft_check_sealed(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx < game->map.len)
	{
		if (idx > (game->map.len - game->width))
		{
			if (game->map.map_str[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR, game);
		}
		else if (idx < game->width)
		{
			if (game->map.map_str[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR, game);
		}
		else if (idx % game->width == FALSE || idx % game->width == game->width
				- TRUE)
		{
			if (game->map.map_str[idx] != WALL_CHAR)
				ft_print_error(WALL_ERROR, game);
		}
		idx++;
	}
}

/**
 * @brief
 * 		we loop in the map until we reach the end (map.len)
 * 			we get all the map info that we read previously
 * 		if we found any char 0 1 P E L S we inc the variable
 *
 * @param game
 */
void	ft_get_info_map(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx++ < game->map.len)
	{
		if (game->map.map_str[idx] == KEY_CHAR)
			game->map.info.nbr_key++;
		else if (game->map.map_str[idx] == PLAYER_CHAR)
			game->map.info.nbr_player++;
		else if (game->map.map_str[idx] == EXIT_CHAR)
			game->map.info.nbr_exit++;
		else if (game->map.map_str[idx] == LAVA_CHAR)
			game->map.info.nbr_lava++;
		else if (game->map.map_str[idx] == LOVE_CHAR)
			game->map.info.nbr_love++;
		else if (game->map.map_str[idx] == WALL_CHAR)
			game->map.info.nbr_wall++;
		else if (game->map.map_str[idx] == BOX_CHAR)
			game->map.info.nbr_box++;
		else if (game->map.map_str[idx] == PORTAL_1_CHAR)
			game->map.info.nbr_portal_1++;
		else if (game->map.map_str[idx] == PORTAL_2_CHAR)
			game->map.info.nbr_portal_2++;
		else if (game->map.map_str[idx] == BORDER_CHAR)
			game->map.info.nbr_border++;
		else
			game->map.info.nbr_void++;
	}
}

/**
 * @brief
 *
 * then check if there is at least one key one exit and
 * only one player otherwise we print the proper error msg
 *
 * @param game
 */
void	ft_check_playability(t_game *game)
{
	if (game->map.info.nbr_key == FALSE)
		ft_print_error(COIN_ERROR, game);
	if (game->map.info.nbr_player != TRUE)
		ft_print_error(PLAYER_ERROR, game);
	if (game->map.info.nbr_exit != TRUE)
		ft_print_error(EXIT_ERROR, game);
	if ((game->map.info.nbr_portal_1 > 1 || game->map.info.nbr_portal_2 > 1) ||
		(game->map.info.nbr_portal_1 == 1 && game->map.info.nbr_portal_2 == 0) ||
		(game->map.info.nbr_portal_1 == 0 && game->map.info.nbr_portal_2 == 1))
		ft_print_error("There must be either exactly one N portal and one Z portal, or no portals at all", game);
}
