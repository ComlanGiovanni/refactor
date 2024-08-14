/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:29:36 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 05:19:23 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// typedef struct s_img {
//     void    *img;
//     char    *data;
//     int     bpp;
//     int     size_line;
//     int     endian;
//     int     width;
//     int     height;
// } t_img;

// int get_pixel_color(t_img *img, int x, int y)
// {
//     char *data = img->data;
//     int bpp = img->bpp / 8;
//     int color;

//     data += (y * img->size_line + x * bpp);
//     color = *(int *)data;
//     return color;
// }

// void init_image_struct(t_img *img)
// {
// 	img->bpp = 0x0;//for conditional jump
// 	//..
// }

// void	ft_display_transparent_image(void *mlx, void *win, char *file_path,
// 		int x, int y)
// {
// 	t_img	img;
// 	int		i;
// 	int		j;
// 	int		color;
// 	char	*src;
// 	int		bpp;

// 	img.img = mlx_xpm_file_to_image(mlx, file_path, &img.width, &img.height);
// 	if (!img.img)
// 		return ;
// 	img.data = mlx_get_data_addr(img.img, &img.bpp, &img.size_line,
// 			&img.endian);
// 	bpp = img.bpp / 8;
// 	i = 0;
// 	while (i < img.height)
// 	{
// 		j = 0;
// 		while (j < img.width)
// 		{
// 			src = img.data + (i * img.size_line + j * bpp);
// 			color = *(int *)src;
// 			if ((color & 0xFF000000) != 0xFF000000)
// 				mlx_pixel_put(mlx, win, x + j, y + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }


//ANIMATED LIFE ICON LOAD AND PALY ANIMATION
//ANIMATED LIFE ICON LOAD AND PALY ANIMATION
//ANIMATED LIFE ICON LOAD AND PALY ANIMATION
//ANIMATED LIFE ICON LOAD AND PALY ANIMATION
//ANIMATED LIFE ICON LOAD AND PALY ANIMATION
void ft_display_transparent_image(void *mlx, void *win, void *img, int x, int y)
{
    char    *img_data;
    int     img_bpp;
    int     img_size_line;
    int     img_endian;
    int     img_width;
    int     img_height;
    int     i;
    int     j;
    int     color;
    char    *src;
    int     bpp;

    // Get image data
    img_data = mlx_get_data_addr(img, &img_bpp, &img_size_line, &img_endian);
 	img_width = 32; // depand don't hard code get it with get mlx_...
    img_height = 32; // MAKE YOU HUD THE SAME SIZE LOL WITH CONVERT
    bpp = img_bpp / 8;
    i = 0;
    while (i < img_height)
    {
        j = 0;
        while (j < img_width)
        {
            // Calculate the address of the current pixel
            src = img_data + (i * img_size_line + j * bpp);
            color = *(int *)src;

            // Check if pixel is not fully transparent (assuming transparency is 0xFF000000)
            if ((color & 0xFF000000) != 0xFF000000)
            {
                mlx_pixel_put(mlx, win, x + j, y + i, color);
            }
            j++;
        }
        i++;
    }
}


void	ft_display_uppercase(t_game *game, char c, t_point *pos,
		void **letter_images)
{
	int	char_index;

	char_index = c - 'A';
	ft_display_transparent_image(game->mlx, game->win, letter_images[char_index], pos->x, pos->y);
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	letter_images[char_index], pos->x, pos->y);
	pos->x += 32;
}

void	ft_display_lowercase(t_game *game, char c, t_point *pos,
		void **letter_images)
{
	int	char_index;

	char_index = c - 'a';
	ft_display_transparent_image(game->mlx, game->win, letter_images[char_index], pos->x, pos->y);
	//mlx_put_image_to_window(game->mlx, game->win,
	//	letter_images[char_index], pos->x, pos->y);
	pos->x += 32;
}

void	init_even_letter_images(t_game *game, void **letter_images)
{
	letter_images[0] = game->hud.alphabet.a.current;
	letter_images[2] = game->hud.alphabet.c.current;
	letter_images[4] = game->hud.alphabet.e.current;
	letter_images[6] = game->hud.alphabet.g.current;
	letter_images[8] = game->hud.alphabet.i.current;
	letter_images[10] = game->hud.alphabet.k.current;
	letter_images[12] = game->hud.alphabet.m.current;
	letter_images[14] = game->hud.alphabet.o.current;
	letter_images[16] = game->hud.alphabet.q.current;
	letter_images[18] = game->hud.alphabet.s.current;
	letter_images[20] = game->hud.alphabet.u.current;
	letter_images[22] = game->hud.alphabet.w.current;
	letter_images[24] = game->hud.alphabet.y.current;
}

void	init_odd_letter_images(t_game *game, void **letter_images)
{
	letter_images[1] = game->hud.alphabet.b.current;
	letter_images[3] = game->hud.alphabet.d.current;
	letter_images[5] = game->hud.alphabet.f.current;
	letter_images[7] = game->hud.alphabet.h.current;
	letter_images[9] = game->hud.alphabet.j.current;
	letter_images[11] = game->hud.alphabet.l.current;
	letter_images[13] = game->hud.alphabet.n.current;
	letter_images[15] = game->hud.alphabet.p.current;
	letter_images[17] = game->hud.alphabet.r.current;
	letter_images[19] = game->hud.alphabet.t.current;
	letter_images[21] = game->hud.alphabet.v.current;
	letter_images[23] = game->hud.alphabet.x.current;
	letter_images[25] = game->hud.alphabet.z.current;
}

void	ft_display_string_sprites(t_game *game, char *alphabet_str,
		t_point position)
{
	void	*letter_images[26];
	int		index;

	init_even_letter_images(game, letter_images);
	init_odd_letter_images(game, letter_images);
	index = 0;
	while (alphabet_str[index] != '\0')
	{
		if (alphabet_str[index] >= 'A' && alphabet_str[index] <= 'Z')
			ft_display_uppercase(game, alphabet_str[index], &position,
				letter_images);
		else if (alphabet_str[index] >= 'a' && alphabet_str[index] <= 'z')
			ft_display_lowercase(game, alphabet_str[index], &position,
				letter_images);
		index++;
	}
}

void ft_display_direction_string(t_game *game)
{
	char *direction;
	t_point		direction_pos;

	direction_pos.x = 5;
	direction_pos.y = game->window.height - 50;
	direction = NULL;
	if (game->player.movement.direction == 'u')
		direction = "Up";
	else if (game->player.movement.direction == 'd')
		direction = "Down";
	else if (game->player.movement.direction == 'l')
		direction = "Left";
	else if (game->player.movement.direction == 'r')
		direction = "Right";
	ft_display_string_sprites(game, direction, direction_pos);
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
	//game->hud.str_storage = ft_itoa(game->player.storage);

	mlx_string_put(game->mlx, game->win, game->hud.fps.x + 80, game->hud.fps.y, RED, "//");
 *
 * @param game
 */
void	ft_print_info_on_window(t_game *game)
{
	game->hud.str_step = ft_itoa(game->player.step);
	game->hud.str_fps = ft_itoa(game->fps.fps);
	game->hud.str_key_remain = ft_itoa(game->map.info.nbr_key
			- game->player.storage);
	ft_display_life_on_windows(game);
	ft_display_string_sprites(game, "STEP", game->hud.step);//make a macro
	ft_display_digits_sprites(game, game->hud.str_step, (t_point){game->hud.step.x + 130 ,game->hud.step.y});//mdr j'ai la flemme de mettre dans une struct
	ft_display_string_sprites(game, "FPS", game->hud.fps);//make a macro
	ft_display_digits_sprites(game, game->hud.str_fps, (t_point){game->hud.fps.x + 100 ,game->hud.fps.y});
	ft_display_string_sprites(game, "KEYS", game->hud.keys);//make a macro
	ft_display_digits_sprites(game, game->hud.str_key_remain, (t_point){game->hud.keys.x + 130 ,game->hud.keys.y});
	ft_display_direction_string(game);
	//ft_event_hud();
	// if (game->player.storage == game->map.info.nbr_key)
	// {
	// 	ft_display_string_sprites(game, "DOOR", (t_point){5, game->window.height - 300});//macro and struct
	// 	ft_display_string_sprites(game, "OPEN", (t_point){5, game->window.height - 290});//macro and struct
	// }
	// if (game->player.life == 1) // the fuck is this ?
	// 	ft_display_string_sprites(game, "NOOB", (t_point){5, game->window.height - 230});
	//ft_event_hud();
	ft_free_step_and_storage(game);
}


void	ft_display_digits_sprites(t_game *game, char *digits_str,
		t_point position)
{
	void	*digit_images[10];
	int		index;

	digit_images[0] = game->hud.digits.zero.current;
	digit_images[1] = game->hud.digits.one.current;
	digit_images[2] = game->hud.digits.two.current;
	digit_images[3] = game->hud.digits.three.current;
	digit_images[4] = game->hud.digits.four.current;
	digit_images[5] = game->hud.digits.five.current;
	digit_images[6] = game->hud.digits.six.current;
	digit_images[7] = game->hud.digits.seven.current;
	digit_images[8] = game->hud.digits.eight.current;
	digit_images[9] = game->hud.digits.nine.current;
	index = 0;
	while (digits_str[index] != '\0')
	{
		if ((digits_str[index] - '0') >= 0 && (digits_str[index] - '0') <= 9)
		{
			ft_display_transparent_image(game->mlx, game->win, digit_images[(digits_str[index] - '0')], position.x, position.y);
			//mlx_put_image_to_window(game->mlx, game->win, digit_images[(digits_str[index] - '0')],
					//position.x, position.y);
			position.x += 24;
		}
		index++;
	}
}

/**
 * @brief
 *
 * 	this fct simply display the number of life of the player
 * 		whe loop by the life.player.map, and print the small love.icon
 * 				10x10 at the x y and we also reset
 * 			the x position to 0 to print at the next line y
 *
 * is not great display because for 100 life we dont manage to print all
 * 		for DLC we can stack every heath
 *
 * 	//t_point for less line put in struct
 * //regarde pour la tranparance lalpha
 * @param game
 */
void	ft_display_life_on_windows(t_game *game)
{
	int	idx;
	int	x;
	int	y;
	int	icons_per_row;
	int	icon_spacing;
	idx = 0;
	x = 5;
	y = 5;
	icons_per_row = 3;
	icon_spacing = 5;
	while (idx < game->player.life && idx < 500)
	{
		ft_display_transparent_image(game->mlx, game->win, game->love.icon, x, y);
		//mlx_put_image_to_window(game->mlx, game->win, game->love.icon, x, y);//try transparence
		idx++;
		if ((idx % icons_per_row) == 0)
		{
			x = 5;
			y += 32 + icon_spacing;
		}
		else
			x += 32 + icon_spacing;
	}
	if (game->player.life <= 0)
		ft_lose_game(game);
}
