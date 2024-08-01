/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_bonus_linux.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:49 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 04:41:09 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

void	ft_add_sprite_to_list(t_sprite_node **head, void *frame)
{
	t_sprite_node	*new_node;

	new_node = (t_sprite_node *)malloc(sizeof(t_sprite_node));
	if (!new_node)
		return ;
	new_node->frame = frame;
	new_node->next = *head;
	*head = new_node;
}

void	ft_load_sprite_frame(void **frame, t_game *game, const char *path,
		const char *error_message)
{
	int	width;
	int	height;

	*frame = mlx_xpm_file_to_image(game->mlx, (char *)path, &width, &height);
	if (*frame == NULL)
		ft_print_error((char *)error_message, game);
	ft_add_sprite_to_list(&game->node, *frame);
}

void	ft_load_animation_sprites(t_animation *animation, t_game *game,
		const char **paths, const char **error_messages)
{
	ft_load_sprite_frame(&(animation->frame_0), game, paths[0],
		error_messages[0]);
	ft_load_sprite_frame(&(animation->frame_1), game, paths[1],
		error_messages[1]);
	ft_load_sprite_frame(&(animation->frame_2), game, paths[2],
		error_messages[2]);
	animation->current = animation->frame_0;
	if (animation->current == NULL)
		ft_print_error((char *)error_messages[0], game);
}

void	ft_load_lava_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/lava/lava_frame_0.xpm",
		"assets/xpm/Bonus/lava/lava_frame_1.xpm",
		"assets/xpm/Bonus/lava/lava_frame_2.xpm"};
	const char	*error_messages[] = {
		LAVA_0_XPM_ERROR,
		LAVA_1_XPM_ERROR,
		LAVA_2_XPM_ERROR};

	ft_load_animation_sprites(&(game->lava.animation), game, paths,
		error_messages);
}

void	ft_load_key_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/key/key_frame_0.xpm",
		"assets/xpm/Bonus/key/key_frame_1.xpm",
		"assets/xpm/Bonus/key/key_frame_2.xpm"};
	const char	*error_messages[] = {
		KEY_0_XPM_ERROR,
		KEY_1_XPM_ERROR,
		KEY_2_XPM_ERROR};

	ft_load_animation_sprites(&(game->key.animation), game, paths,
		error_messages);
}

void	ft_load_wall_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/wall/wall_frame_0.xpm",
		"assets/xpm/Bonus/wall/wall_frame_1.xpm",
		"assets/xpm/Bonus/wall/wall_frame_2.xpm"};
	const char	*error_messages[] = {
		WALL_0_XPM_ERROR,
		WALL_1_XPM_ERROR,
		WALL_2_XPM_ERROR};

	ft_load_animation_sprites(&(game->wall.animation), game, paths,
		error_messages);
}

void	ft_load_borders_sprite(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/grass/grass_frame_0.xpm",
		"assets/xpm/Bonus/grass/grass_frame_1.xpm",
		"assets/xpm/Bonus/grass/grass_frame_0.xpm"};
	const char	*error_messages[] = {
		GRASS_0_XPM_ERROR,
		GRASS_1_XPM_ERROR,
		GRASS_2_XPM_ERROR};

	ft_load_animation_sprites(&(game->grass.animation), game, paths,
		error_messages);
}

void	ft_load_ground_sprites(t_game *game)
{
	int	width;
	int	height;

	game->map.ground = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/ground/ground.xpm", &width, &height);
	if (game->map.ground == NULL)
		ft_print_error(GROUND_XPM_ERROR, game);
}

void	ft_load_love_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/love/love_frame_0.xpm",
		"assets/xpm/Bonus/love/love_frame_1.xpm",
		"assets/xpm/Bonus/love/love_frame_2.xpm",
	};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon",
	};

	ft_load_animation_sprites(&(game->love.animation), game, paths,
		error_messages);
	ft_load_sprite_frame(&(game->love.icon), game,
		"assets/xpm/Bonus/love/love_small_icon.xpm",
		"Generic message error replace soon");
	ft_load_sprite_frame(&(game->love.nope), game,
		"assets/xpm/Bonus/love/love_frame_nope.xpm",
		"Generic message error replace soon");
}

void	ft_load_digit_zero(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/0/digit_0_frame_0.xpm",
		"assets/xpm/Bonus/digits/0/digit_0_frame_1.xpm",
		"assets/xpm/Bonus/digits/0/digit_0_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.zero), game, paths,
		error_messages);
}

void	ft_load_digit_one(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/1/digit_1_frame_0.xpm",
		"assets/xpm/Bonus/digits/1/digit_1_frame_1.xpm",
		"assets/xpm/Bonus/digits/1/digit_1_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.one), game, paths,
		error_messages);
}

void	ft_load_digit_two(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/2/digit_2_frame_0.xpm",
		"assets/xpm/Bonus/digits/2/digit_2_frame_1.xpm",
		"assets/xpm/Bonus/digits/2/digit_2_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.two), game, paths,
		error_messages);
}

void	ft_load_digit_tree(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/3/digit_3_frame_0.xpm",
		"assets/xpm/Bonus/digits/3/digit_3_frame_1.xpm",
		"assets/xpm/Bonus/digits/3/digit_3_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.tree), game, paths,
		error_messages);
}

void	ft_load_digit_four(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/4/digit_4_frame_0.xpm",
		"assets/xpm/Bonus/digits/4/digit_4_frame_1.xpm",
		"assets/xpm/Bonus/digits/4/digit_4_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.four), game, paths,
		error_messages);
}

void	ft_load_digit_five(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/5/digit_5_frame_0.xpm",
		"assets/xpm/Bonus/digits/5/digit_5_frame_1.xpm",
		"assets/xpm/Bonus/digits/5/digit_5_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.five), game, paths,
		error_messages);
}

void	ft_load_digit_six(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/6/digit_6_frame_0.xpm",
		"assets/xpm/Bonus/digits/6/digit_6_frame_1.xpm",
		"assets/xpm/Bonus/digits/6/digit_6_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.six), game, paths,
		error_messages);
}

void	ft_load_digit_seven(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/7/digit_7_frame_0.xpm",
		"assets/xpm/Bonus/digits/7/digit_7_frame_1.xpm",
		"assets/xpm/Bonus/digits/7/digit_7_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.seven), game, paths,
		error_messages);
}

void	ft_load_digit_eight(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/8/digit_8_frame_0.xpm",
		"assets/xpm/Bonus/digits/8/digit_8_frame_1.xpm",
		"assets/xpm/Bonus/digits/8/digit_8_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.eight), game, paths,
		error_messages);
}

void	ft_load_digit_nine(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/9/digit_9_frame_0.xpm",
		"assets/xpm/Bonus/digits/9/digit_9_frame_1.xpm",
		"assets/xpm/Bonus/digits/9/digit_9_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.nine), game, paths,
		error_messages);
}

void	ft_load_digit_tab(t_game *game)
{
	game->hud.digits.tab[0] = game->hud.digits.zero.current;
	game->hud.digits.tab[1] = game->hud.digits.one.current;
	game->hud.digits.tab[2] = game->hud.digits.two.current;
	game->hud.digits.tab[3] = game->hud.digits.tree.current;
	game->hud.digits.tab[4] = game->hud.digits.four.current;
	game->hud.digits.tab[5] = game->hud.digits.five.current;
	game->hud.digits.tab[6] = game->hud.digits.six.current;
	game->hud.digits.tab[7] = game->hud.digits.seven.current;
	game->hud.digits.tab[8] = game->hud.digits.eight.current;
	game->hud.digits.tab[9] = game->hud.digits.nine.current;
}

void	ft_load_digits_sprites(t_game *game)
{
	ft_load_digit_zero(game);
	ft_load_digit_one(game);
	ft_load_digit_two(game);
	ft_load_digit_tree(game);
	ft_load_digit_four(game);
	ft_load_digit_five(game);
	ft_load_digit_six(game);
	ft_load_digit_seven(game);
	ft_load_digit_eight(game);
	ft_load_digit_nine(game);
	ft_load_digit_tab(game);
}
