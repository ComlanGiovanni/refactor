/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:10:08 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 22:21:31 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_player_sprites(t_game *game)
{
	ft_load_player_up_sprites(game);
	ft_load_player_down_sprites(game);
	ft_load_player_left_sprites(game);
	ft_load_player_right_sprites(game);
	ft_load_player_current(game);
}

void	ft_load_keke_sprites(t_game *game)
{
	ft_load_keke_up_sprites(game);
	ft_load_keke_down_sprites(game);
	ft_load_keke_left_sprites(game);
	ft_load_keke_right_sprites(game);
	ft_load_keke_current(game);
}

void	ft_load_gameplay_sprites(t_game *game)
{
	ft_load_love_sprites(game);
	ft_load_key_sprites(game);
	ft_load_portal_n_sprites(game);
	ft_load_portal_z_sprites(game);
	ft_load_door_closed_sprites(game);
	ft_load_door_open_sprites(game);
}

void	ft_load_enemies_sprites(t_game *game)
{
	ft_load_lava_sprites(game);
	ft_load_pawn_sprites(game);
}

void	ft_load_tree_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/tree/tree_frame_0.xpm",
		"assets/xpm/Bonus/tree/tree_frame_1.xpm",
		"assets/xpm/Bonus/tree/tree_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messaqge change soon",
		"Generic messagwe change soon",
		"Generic messaege change soon"};

	ft_load_animation_sprites(&(game->tree.animation), game, paths,
		error_messages);
}

void	ft_load_trees_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/trees/trees_frame_0.xpm",
		"assets/xpm/Bonus/trees/trees_frame_1.xpm",
		"assets/xpm/Bonus/trees/trees_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messgage change soon",
		"Generic messarge change soon",
		"Generic messagye change soon"};

	ft_load_animation_sprites(&(game->trees.animation), game, paths,
		error_messages);
}

void	ft_load_reed_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/reed/reed_frame_0.xpm",
		"assets/xpm/Bonus/reed/reed_frame_1.xpm",
		"assets/xpm/Bonus/reed/reed_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messauge change soon",
		"Generic meossage change soon",
		"Generic mepssage change soon"};

	ft_load_animation_sprites(&(game->reed.animation), game, paths,
		error_messages);
}

void	ft_load_husks_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/husks/husks_frame_0.xpm",
		"assets/xpm/Bonus/husks/husks_frame_1.xpm",
		"assets/xpm/Bonus/husks/husks_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message changbbe soon",
		"Generic message cbbhange soon",
		"Generic messaffge change soon"};

	ft_load_animation_sprites(&(game->husks.animation), game, paths,
		error_messages);
}

void	ft_load_fungus_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/fungus/fungus_frame_0.xpm",
		"assets/xpm/Bonus/fungus/fungus_frame_1.xpm",
		"assets/xpm/Bonus/fungus/fungus_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messxxage change soon",
		"Generic messxxage change soon",
		"Generic messaxxge change soon"};

	ft_load_animation_sprites(&(game->fungus.animation), game, paths,
		error_messages);
}

void	ft_load_fungi_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/fungi/fungi_frame_0.xpm",
		"assets/xpm/Bonus/fungi/fungi_frame_1.xpm",
		"assets/xpm/Bonus/fungi/fungi_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messagwwe change soon",
		"Generic message change soon",
		"Generic message change soon"};

	ft_load_animation_sprites(&(game->fungi.animation), game, paths,
		error_messages);
}

void	ft_load_flower_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/flower/flower_frame_0.xpm",
		"assets/xpm/Bonus/flower/flower_frame_1.xpm",
		"assets/xpm/Bonus/flower/flower_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message caahange soon",
		"Generic message cddhange soon",
		"Generic message cdfdfhange soon"};

	ft_load_animation_sprites(&(game->flower.animation), game, paths,
		error_messages);
}

void	ft_load_algae_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/algae/algae_frame_0.xpm",
		"assets/xpm/Bonus/algae/algae_frame_1.xpm",
		"assets/xpm/Bonus/algae/algae_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messayuyiyge change soon",
		"Generic messiyiyiage change soon",
		"Generic messayiyge change soon"};

	ft_load_animation_sprites(&(game->algae.animation), game, paths,
		error_messages);
}

void	ft_load_water_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/water/water_frame_0.xpm",
		"assets/xpm/Bonus/water/water_frame_1.xpm",
		"assets/xpm/Bonus/water/water_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messayuyiyge change soon",
		"Generic messiyiyiage change soon",
		"Generic messayiyge change soon"};

	ft_load_animation_sprites(&(game->water.animation), game, paths,
		error_messages);
}

void	ft_load_borders_sprite(t_game *game)
{
	ft_load_grass_sprites(game);
	ft_load_tree_sprites(game);
	ft_load_trees_sprites(game);
	ft_load_reed_sprites(game);
	ft_load_husks_sprites(game);
	ft_load_fungus_sprites(game);
	ft_load_fungi_sprites(game);
	ft_load_flower_sprites(game);
	ft_load_algae_sprites(game);
	ft_load_water_sprites(game);
}

void	ft_load_sprites(t_game *game)
{
	game->node = NULL;
	ft_load_enemies_sprites(game);
	ft_load_wall_sprites(game);
	ft_load_ground_sprites(game);
	ft_load_borders_sprite(game);
	ft_load_player_sprites(game);
	ft_load_keke_sprites(game);
	ft_load_gameplay_sprites(game);
	ft_load_digits_sprites(game);
	ft_load_box_sprites(game);
}

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
