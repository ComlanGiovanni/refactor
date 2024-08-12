/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_enums_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:24:20 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/09 17:20:33 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_ENUMS_BONUS_H
# define FT_SO_LONG_ENUMS_BONUS_H

enum	e_key_code
{
	LINUX_CLOSE_ICON = 17,
	LINUX_ESC_KEY = 65307,
	LINUX_KEY_PRESS = 2,
	LINUX_KEY_RELEASE = 3,
	LINUX_W_KEY = 119,
	LINUX_A_KEY = 97,
	LINUX_S_KEY = 115,
	LINUX_D_KEY = 100,
	LINUX_UP_ARROW_KEY = 65362,
	LINUX_DOWN_ARROW_KEY = 65364,
	LINUX_LEFT_ARROW_KEY = 65361,
	LINUX_RIGHT_ARROW_KEY = 65363,
	LINUX_UP_PAV_NUM_KEY = 65431,
	LINUX_DOWN_PAV_NUM_KEY = 65433,
	LINUX_LEFT_PAV_NUM_KEY = 65430,
	LINUX_RIGHT_PAV_NUM_KEY = 65432
};

enum	e_map_char
{
	LAVA_CHAR = 'L',
	EXIT_CHAR = 'E',
	LOVE_CHAR = 'S',
	KEY_CHAR = 'C',
	PLAYER_CHAR = 'P',
	WALL_CHAR = '1',
	VOID_CHAR = '0',
	BORDER_CHAR = '#',
	VISITED_CHAR = 'V',
	BOX_CHAR = 'B',
	PORTAL_1_CHAR = 'Z',
	PORTAL_2_CHAR = 'N',
	KEKE_CHAR = 'K',
	PAWN_CHAR = 'W',
};

enum	e_bool
{
	TRUE = 1,
	FALSE = 0
};

#endif // !FT_SO_LONG_ENUMS_BONUS_H
