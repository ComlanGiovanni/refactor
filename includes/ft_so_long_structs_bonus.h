/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_structs_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:28:13 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/07 14:58:42 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_STRUCTS_BONUS_H
# define FT_SO_LONG_STRUCTS_BONUS_H

struct						s_point
{
	int						x;
	int						y;
};

struct						s_fps
{
	struct timespec			last_time;
	struct timespec			current_time;
	int						frame_count;
	double					fps;
	double					elapsed;
};

struct						s_animation
{
	int						frames;
	void					*current;
	void					*frame_0;
	void					*frame_1;
	void					*frame_2;
};

struct						s_lava
{
	t_animation				animation;
	char					move;
};

struct						s_key
{
	t_animation				animation;
};

struct						s_grass
{
	t_animation				animation;
};

struct						s_wall
{
	t_animation				animation;
};

struct						s_anim_door
{
	int						frames;
	void					*current;
	void					*frame_0;
	void					*frame_1;
	void					*frame_2;
};

struct						s_door
{
	//int				frames;
	t_anim_door				closed;
	t_anim_door				open;
};

struct						s_love
{
	t_animation				animation;
	void					*nope;
	void					*icon;
};

struct						s_anim_player
{
	void					*current;
	void					*frame_0;
	void					*frame_1;
	void					*frame_2;
	void					*frame_move;
};

// typedef struct s_point_visual
// {
// 	float x;
//     float y;
// } t_point_visual;

struct						s_movement
{
	//t_point_visual	visual;
	t_point					current_position;
	t_point					target_position;
	t_bool					moved;
	char					direction;
	//float			speed;
};

struct						s_player
{
	t_anim_player			up_anim;
	t_anim_player			down_anim;
	t_anim_player			left_anim;
	t_anim_player			right_anim;
	//t_point			position;
	t_movement				movement;
	// t_point			target_position;
	// float			speed;
	//t_movement	movement
	//t_bool			moved;
	int						frames;
	long long int			life;
	long long int			storage;
	long long int			step;
	//char			direction;
	// double			x_speed;
	// double			y_speed;
};

struct						s_info
{
	long long int			nbr_key;
	long long int			nbr_exit;
	long long int			nbr_player;
	long long int			nbr_lava;
	long long int			nbr_love;
	long long int			nbr_wall;
	long long int			nbr_void;
	long long int			nbr_box;
	long long int			nbr_border;
	long long int			nbr_portal_1;
	long long int			nbr_portal_2;
};

struct						s_map
{
	t_point					size;
	t_point					start;
	t_point					end;
	t_point					portal_1_pos;
	t_point					portal_2_pos;
	t_info					info;
	char					*map_str;
	char					**matrice;
	char					**grid;
	void					*ground;
	//void			*grass;
	//void			*borders;
	long long int			len;
	// long long int	nbr_key;
	// long long int	nbr_exit;
	// long long int	nbr_player;
	// long long int	nbr_lava;
	// long long int	nbr_love;
	// long long int	nbr_wall;
	// long long int	nbr_void;
	long long int			border_width;
};

struct						s_window
{
	int						bpp;
	int						size_line;
	int						endian;
	void					*img;
	char					*img_data;
	int						width;
	int						height;
};

struct						s_digits
{
	void					*tab[10];
	t_animation				zero;
	t_animation				one;
	t_animation				two;
	t_animation				tree;
	t_animation				four;
	t_animation				five;
	t_animation				six;
	t_animation				seven;
	t_animation				eight;
	t_animation				nine;
};

struct						s_hud
{
	char					*str_step;
	char					*str_storage;
	char					*str_fps;
	char					*str_key_remain;
	//int				frame;
	t_digits				digits;
	t_point					fps;
	t_point					step;
	t_point					direction;
	t_point					keys;
	t_point					storage;
};

struct						s_camera
{
	t_point current; // faire une struct camera
	t_point					target;
	double					shake_intensity;
	double					shake_speed;
	double					lerp_speed;
	double					angle;
	//float			zoom_factor;
};

struct						s_sprite_node
{
	void					*frame;
	struct s_sprite_node	*next;
};

struct						s_box
{
	t_animation				animation;
};

struct						s_portal
{
	t_animation				z;
	t_animation				n;
};

struct						s_anim_keke
{
	void					*current;
	void					*frame_0;
	void					*frame_1;
	void					*frame_2;
	void					*frame_move_0;
	void					*frame_move_1;
};

struct						s_keke
{
	t_anim_keke				up_anim;
	t_anim_keke				down_anim;
	t_anim_keke				left_anim;
	t_anim_keke				right_anim;
	t_bool					moved;
	int						frames;
	char					direction;
	long long int			step;
};


struct						s_game
{
	t_player				player;
	t_love					love;
	t_map					map;
	t_lava					lava;
	t_key					key;
	t_wall					wall;
	t_grass					grass;
	t_door					door;
	t_box					box;
	t_portal				portal;
	t_camera				camera;
	t_sprite_node			*node;
	t_point					screen;
	t_bool					paused;
	t_keke					keke;
	// t_point			camera;// faire une struct camera
	// t_point			camera_target;
	t_fps					fps;
	t_window				window;
	t_hud					hud;
	void					*mlx;
	void					*win;
	t_bool					finished;
	//void			*img;
	//char			*img_data;
	// char			*str_step;
	// char			*str_storage;
	// char			*str_fps;
	// float 			distance_camera;
	// float			zoom_factor;
	// double			last_time;
	long long int width;      //useleep try to make a map very big;
	long long int height;     //useleep
	long long int empty_line; //mettre dans map information
};

#endif // !FT_SO_LONG_STRUCTS_BONUS_H
