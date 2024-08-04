/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:12:49 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 01:50:32 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

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

	game = NULL;
	if (argc != 2)
		ft_print_no_arg();
	else
	{
		ft_check_env(envp);
		game = ft_calloc(sizeof(t_game), sizeof(t_game));
		if (game == NULL)
			ft_print_error(MALLOC_GAME_ERROR, game);
		ft_init_game(game, argv[1]);
		ft_mlx_hook_loop(game);
	}
	return (EXIT_SUCCESS);
}
