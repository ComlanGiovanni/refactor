/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_functions_bonus.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:24:23 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 19:52:49 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_FUNCTIONS_BONUS_H
# define FT_SO_LONG_FUNCTIONS_BONUS_H

//=================================================================== [ file.c ]

void	ft_play_animation(t_game *game);
void	ft_door_open_animation(t_anim_door *animation);
void	ft_door_closed_animation(t_anim_door *animation);
void	ft_generic_animation(t_animation *animation, int *frame);
void	ft_digits_animation(t_game *game);

//=================================================================== [ file.c ]


void	ft_zero_animation(t_animation *animation);
void	ft_one_animation(t_animation *animation);
void	ft_two_animation(t_animation *animation);
void	ft_three_animation(t_animation *animation);
void	ft_four_animation(t_animation *animation);

//=================================================================== [ file.c ]

void	ft_player_animation(t_player *player);
void	ft_keke_animation(t_keke *keke);

//=================================================================== [ file.c ]

void	ft_five_animation(t_animation *animation);
void	ft_six_animation(t_animation *animation);
void	ft_seven_animation(t_animation *animation);
void	ft_eight_animation(t_animation *animation);
void	ft_nine_animation(t_animation *animation);

//=================================================================== [ file.c ]

void	ft_wall_animation(t_animation *animation);
void	ft_pawn_animation(t_animation *animation);
void	ft_lava_animation(t_animation *animation);
void	ft_key_animation(t_animation *animation);
void	ft_love_animation(t_animation *animation);
void	ft_grass_animation(t_animation *animation);
void	ft_box_animation(t_animation *animation);
void	ft_portal_n_animation(t_animation *animation);
void	ft_portal_z_animation(t_animation *animation);

//=================================================================== [ file.c ]

void	ft_camera_shake(t_game *game);
void	ft_update_camera(t_game *game);
float	ft_linear_interpolation(float interpolation_factor, float start,
		float end);

//=================================================================== [ file.c ]

int		ft_check_extension(char *map_name, char *extension);
void	ft_check_env(char **envp);

//=================================================================== [ file.c ]

void	ft_check_map(t_game *game);
void	ft_map_fit_screen(t_game *game);
void	ft_check_valid_char(t_game *game);
void	ft_check_sealed(t_game *game);
void	ft_check_rectangular(t_game *game);
void	ft_check_playability(t_game *game);
int		ft_is_valid_char(char tile);

//=================================================================== [ file.c ]

void	ft_display_sprites_addr(t_game *game);
void	ft_print_game_info(t_game *game);

//=================================================================== [ file.c ]

void	ft_put_sprites_by_line(t_game *game);

//=================================================================== [ file.c ]

void	ft_put_all_sprites_to_line(t_game *game, int width, int height,
			t_point sprite_pos);
void	ft_player_sprite_call(t_game *game, int width, int height,
			t_point sprite_pos);

//=================================================================== [ file.c ]

void	ft_key_sprite(t_game *game, t_point pos);
void	ft_lava_sprite(t_game *game, t_point pos);
void	ft_love_sprite(t_game *game, t_point pos);
void	ft_exit_sprite(t_game *game, t_point pos);
void	ft_ground_sprite(t_game *game, t_point pos);
void	ft_wall_sprite(t_game *game, t_point pos);
void	ft_pawn_sprite(t_game *game, t_point pos);
void	ft_grass_sprite(t_game *game, t_point pos);
void	ft_box_sprite(t_game *game, t_point pos);
void	ft_portal_z_sprite(t_game *game, t_point pos);
void	ft_portal_n_sprite(t_game *game, t_point pos);
void	ft_player_down_sprite(t_game *game, int draw_x, int draw_y);
void	ft_player_up_sprite(t_game *game, int draw_x, int draw_y);
void	ft_player_left_sprite(t_game *game, int draw_x, int draw_y);
void	ft_player_right_sprite(t_game *game, int draw_x, int draw_y);

//=================================================================== [ file.c ]

void	ft_keke_sprites(t_game *game, int width, int height,
		t_point sprite_pos);
void	ft_keke_down_sprite(t_game *game, int draw_x, int draw_y);
void	ft_keke_up_sprite(t_game *game, int draw_x, int draw_y);
void	ft_keke_left_sprite(t_game *game, int draw_x, int draw_y);
void	ft_keke_right_sprite(t_game *game, int draw_x, int draw_y);

//=================================================================== [ file.c ]

int		ft_exit_game(t_game *game);
int		ft_win_game(t_game *game);
int		ft_lose_game(t_game *game);
void	ft_free_all(t_game *game);
void	ft_free_mlx(t_game *game);
void	ft_free_sprites_list(t_sprite_node **head, void *mlx);

void	ft_free_animation(t_game *game);
void	ft_free_sprite_frame(void **frame, void *mlx);
void	ft_free_ground(t_game *game);
void	ft_free_step_and_storage(t_game *game);
void	ft_clean_fail_malloc_split_map(t_game *game, char **grid, int row);
void	ft_clean_grid_map(char **grid, int row);

//=================================================================== [ file.c ]

void	ft_direction_keke_after_launch(t_game *game);
int		ft_is_keke_obstacle(char tile);
void	ft_keke_move_up(t_game *game);
void	ft_keke_move_down(t_game *game);
void	ft_keke_move_left(t_game *game);
void	ft_keke_move_right(t_game *game);

//=================================================================== [ file.c ]

void	ft_a_star_keke_movement(t_game *game);
void	ft_move_keke(t_game *game);

//=================================================================== [ file.c ]

void	ft_move_keke_up(t_game *game, int row, int col);
void	ft_move_keke_down(t_game *game, int row, int col);
void	ft_move_keke_left(t_game *game, int row, int col);
void	ft_move_keke_right(t_game *game, int row, int col);

//=================================================================== [ file.c ]

void ft_find_pawn_positions(t_game *game);
void ft_free_pawns_array(t_game *game);

//=================================================================== [ file.c ]

void	ft_dir_player_by_pos_exit_after_launch(t_game *game);
void	ft_move_box(t_game *game, int new_y, int new_x, int dir_y, int dir_x);
void	ft_teleport_player(t_game *game, int y, int x);

//=================================================================== [ file.c ]

void	ft_play_movement_sound(t_game *game);
void	ft_player_take_coin(t_game *game);
void	ft_player_take_life(t_game *game);
void	ft_player_get_hit(t_game *game);
void	ft_baba_forbidden(t_game *game);
void	ft_pawn_movement(t_game *game);

//=================================================================== [ file.c ]

void	ft_print_info_on_window(t_game *game);
void	ft_display_digits_sprites(t_game *game, char *digits_str,
			t_point position);
void	ft_display_life_on_windows(t_game *game);

//=================================================================== [ file.c ]

void	ft_init_camera(t_game *game);
void	ft_init_hud_sprites_position(t_game *game);
void	ft_init_frames(t_game *game);
void	ft_init_fps(t_game *game);
void	ft_init_map_info(t_game *game, char *line);
void	ft_init_game_info(t_game *game);
void	ft_init_pawns_array(t_game *game);

//=================================================================== [ file.c ]

void	ft_setup_map(t_game *game);
void	ft_get_info_map(t_game *game);
void	ft_play_random_theme(void);

//=================================================================== [ file.c ]

void	ft_init_mlx(t_game *game);
void	ft_create_window(t_game *game);

//=================================================================== [ file.c ]

void	ft_init_game(t_game *game, char *map_name);
void	ft_init_player_info(t_game *game);
void	ft_init_map_info(t_game *game, char *line);
void	ft_init_keke_info(t_game *game);

//=================================================================== [ file.c ]

int		ft_input_manager(int key_code, t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

//=================================================================== [ file.c ]

void	ft_handle_tile_action(t_game *game, char next_tile);
void	ft_input_up(t_game *game);
void	ft_input_down(t_game *game);
void	ft_input_left(t_game *game);
void	ft_input_right(t_game *game);

//=================================================================== [ file.c ]

void	ft_load_sprites(t_game *game);
void	ft_add_sprite_to_list(t_sprite_node **head, void *frame);
void	ft_load_sprite_frame(void **frame, t_game *game, const char *path,
			const char *error_message);
void	ft_load_animation_sprites(t_animation *animation, t_game *game,
			const char **paths, const char **error_messages);

//=================================================================== [ file.c ]

void	ft_load_digits_sprites(t_game *game);
void	ft_load_digit_tab(t_game *game);

//=================================================================== [ file.c ]

void	ft_load_door_closed_sprites(t_game *game);
void	ft_load_door_open_sprites(t_game *game);

//=================================================================== [ file.c ]

void	ft_load_digit_zero(t_game *game);
void	ft_load_digit_two(t_game *game);
void	ft_load_digit_four(t_game *game);
void	ft_load_digit_six(t_game *game);
void	ft_load_digit_eight(t_game *game);

//=================================================================== [ file.c ]

void	ft_load_lava_sprites(t_game *game);
void	ft_load_key_sprites(t_game *game);
void	ft_load_love_sprites(t_game *game);
void	ft_load_box_sprites(t_game *game);

//=================================================================== [ file.c ]

void	ft_load_portal_z_sprites(t_game *game);
void	ft_load_portal_n_sprites(t_game *game);
void	ft_load_digit_one(t_game *game);
void	ft_load_digit_tree(t_game *game);
void	ft_load_digit_five(t_game *game);
void	ft_load_digit_seven(t_game *game);
void	ft_load_digit_nine(t_game *game);

//=================================================================== [ file.c ]

void	ft_load_player_up_sprites(t_game *game);
void	ft_load_player_down_sprites(t_game *game);
void	ft_load_player_left_sprites(t_game *game);
void	ft_load_player_right_sprites(t_game *game);
void	ft_load_player_current(t_game *game);

//=================================================================== [ file.c ]

void	ft_load_keke_up_sprites(t_game *game);
void	ft_load_keke_down_sprites(t_game *game);
void	ft_load_keke_left_sprites(t_game *game);
void	ft_load_keke_right_sprites(t_game *game);
void	ft_load_keke_current(t_game *game);

//=================================================================== [ file.c ]

void	ft_load_ground_sprites(t_game *game);
void	ft_load_grass_sprites(t_game *game);
void	ft_load_wall_sprites(t_game *game);
void	ft_load_pawn_sprites(t_game *game);

//=================================================================== [ file.c ]

void	ft_mlx_hook_loop(t_game *game);

//=================================================================== [ file.c ]

void	ft_read_map(t_game *game, char *map_name);

int		ft_get_map_height(char *map_name, t_game *game);

void	ft_check_ber_format(char *map_name, int height, t_game *game);

//=================================================================== [ file.c ]

char	**ft_allocate_new_map(int new_height, int new_width, t_game *game);
void	ft_fill_map_row(char **new_map, int row, t_game *game, int new_width);
char	**ft_create_map_with_border(t_game *game);

//=================================================================== [ file.c ]

char	*ft_custom_strdup(char *s1);
int		ft_custom_strlcpy(char *dst, char *src, int dst_size);
char	*ft_custom_strjoin(char *s1, char *s2);

//=================================================================== [ file.c ]
void	ft_check_map_finishable(t_game *game);
void	ft_flood_fill(char **tab, t_game *game, t_point start,
			t_bool *exit_found, int *coins);
char	**ft_split_map(t_game *game);
t_point	ft_find_pos_char(char **tab, t_point size, char c);

//=================================================================== [ file.c ]

float	ft_perlin_noise(float x, float y);
void	ft_calculate_relatives_positions(t_perlin_vars *vars, float x, float y);
void	ft_calculate_fades_values(t_perlin_vars *vars);
void	ft_calculate_permutation_indices(t_perlin_vars *vars, int *perm);
void	ft_calculate_gradients(t_perlin_vars *vars, int *perm);
void	ft_calculate_interpolation_x(t_perlin_vars *vars);
char	ft_determine_fill_char(float noise_value);
float	ft_fade(float relative_position_fade_factor);
int		ft_floor(float value);
float	ft_gradient(int hash, float x, float y);

//=================================================================== [ file.c ]

void	ft_print_error(char *error_msg, t_game *game);
void	ft_print_no_arg(void);
void	ft_free_and_print(char **map, t_game *game, char *str);
void	ft_print_error_empty_and_free(char *error_msg, t_game *game);

//=================================================================== [ file.c ]

void	ft_print_fill_grid(char **map);
void	ft_print_display_grid(char **res);
void	ft_display_position(t_point start, t_point end, t_point z, t_point n);
void	ft_print_map_info(t_game *game);
void	ft_print_initial_positions(t_game *game);

//=================================================================== [ file.c ]

int		ft_update(t_game *game);
void	ft_update_fps(t_game *game);
void	ft_update_map_matrice(t_game *game);
void	ft_update_player_position(t_game *game);
void	ft_update_map_positions(t_game *game);

//=================================================================== [ file.c ]

#endif // !FT_SO_LONG_FUNCTIONS_BONUS_H
