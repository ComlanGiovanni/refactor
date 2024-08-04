/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:10:59 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 14:37:37 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//pout map screen info in struct create one etc
void	ft_map_fit_screen(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	width = 0;
	mlx_get_screen_size(game->mlx, &width, &height);
	if (game->width * 64 > width || game->height * 64 > height)
		ft_print_error(MAP_TOO_BIG, game);
}

int	ft_is_valid_char(char tile)
{
	return (tile == WALL_CHAR && tile == PLAYER_CHAR && tile == KEY_CHAR
		&& tile == EXIT_CHAR && tile == VOID_CHAR && tile == PLAYER_CHAR
		&& tile == BOX_CHAR && tile == LAVA_CHAR && tile == PORTAL_1_CHAR
		&& tile == PORTAL_2_CHAR);
}

/**
 * @brief
 *
 * 		we check if every char until the end is
 *  		equal to typedef enum e_map_char
 * 		if not quit and print the error msg for it
 *
 * @param game
 */
void	ft_check_valid_char(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (game->map.map_str[idx] != '\0')
	{
		if (ft_is_valid_char(game->map.map_str[idx]))
			ft_print_error(BAD_CHAR_MAP_ERROR, game);
		idx++;
	}
}

/**
 * @brief
 *
 * 			In Euclidean plane geometry,
 * 		a rectangle is a quadrilateral with four right angles.
 * 	A rectangle with four sides of equal length is a square.
 *
 * Les côtés d'un rectangle étant deux à deux de même longueur
 * 						a et b
 *
 * 		rec : a != b 		&& 		carr  a = b
 *
 * 				Mine de rien dans la rigolade
 * 		j'avais oublier qu'un carree est un rectangle
 *
 * 	du coup si height == width is a reactangle
 *
 * @param game
 */
void	ft_check_rectangular(t_game *game)
{
	if (game->height * game->width != game->map.len)
		ft_print_error(FORM_ERROR, game);
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
