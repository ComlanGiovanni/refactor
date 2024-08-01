/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:17:50 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 04:30:50 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

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
	ft_free_ground(game);
	ft_free_sprites_list(&game->node, game->mlx);
}

void	ft_free_mlx(t_game *game)
{
	if (game->window.img)
		mlx_destroy_image(game->mlx, game->window.img);
	if (game->window.img_data)
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
