//https://fr.wikipedia.org/wiki/Multiple_buffering

// void ft_double_buffering(t_game *game)
// {
// 	ft_printf("Des bugs");
//     game->window.img = mlx_new_image(game->mlx, game->window.width, game->window.height);
// 	game->img_data = mlx_get_data_addr(game->window.img, &game->window.bpp, &game->window.size_line, &game->window.endian);
// 	//mlx_destroy_image(game->mlx, game->window.img);

// }

// void ft_debug_image(t_game *game)
// {
//     printf("Image Data: %p\n", game->img_data);
//     printf("BPP: %d\n", game->window.bpp);
//     printf("Size Line: %d\n", game->window.size_line);
//     printf("Endian: %d\n", game->window.endian);
// }

// void ft_draw_frame(t_game *game)
// {
// 	//ft_double_buffering(game);
// 	//ft_put_sprites_by_line(game);

// 	//mlx_put_image_to_window(game->mlx, game->win, game->window.img, 0, 0);
// 	//ft_printf("Des bugsssss");

// 	//mlx_destroy_image(game->mlx, game->window.img);
// 	//mlx_clear_window(game->mlx, game->win);
// }

	//ft_update_player(t_game *game, float delta_time)
	// static struct timeval last_time;
    // struct timeval current_time;
    // gettimeofday(&current_time, NULL);

    // float delta_time = (current_time.tv_sec - last_time.tv_sec) + (current_time.tv_usec - last_time.tv_usec) / 1000000.0;
    // last_time = current_time;
    // if (game->player.movement.moved)
    // {
    //     float target_x = game->player.movement.target_position.x * IMG_SIZE;
    //     float target_y = game->player.movement.target_position.y * IMG_SIZE;

    //     // Vitesse de transition
    //     float t = game->player.movement.speed * game->fps.elapsed / IMG_SIZE;
    //     if (t > 1.0)
    //         t = 1.0;
// system("pkill vlc");
// sudo apt-get install vlc
// system("cvlc sounds/hammer.wav &");
        // Interpolation linéaire
    //     game->player.movement.visual.x = ft_lerp(game->player.movement.visual.x, target_x, t);
    //     game->player.movement.visual.y = ft_lerp(game->player.movement.visual.y, target_y, t);

	// 	if (game->player.movement.visual.x < 0)
    //         game->player.movement.visual.x = 0;
    //     if (game->player.movement.visual.y < 0)
    //         game->player.movement.visual.y = 0;
    //     if (game->player.movement.visual.x > (game->width - 1) * IMG_SIZE)
    //         game->player.movement.visual.x = (game->width - 1) * IMG_SIZE;
    //     if (game->player.movement.visual.y > (game->height - 1) * IMG_SIZE)
    //         game->player.movement.visual.y = (game->height - 1) * IMG_SIZE;

    //     // Vérifie si le joueur a atteint sa destination
    //     if (fabs(game->player.movement.visual.x - target_x) < 0.1 && fabs(game->player.movement.visual.y - target_y) < 0.1)
    //     {
    //         game->player.movement.visual.x = target_x;
    //         game->player.movement.visual.y = target_y;
    //         game->player.movement.current_position.x = game->player.movement.target_position.x;
    //         game->player.movement.current_position.y = game->player.movement.target_position.y;
    //         game->player.movement.moved = 0;
    //     }
    // }
	//ft_update_player(t_game *game, float delta_time)

		// int  *pixel;
	// for (int i = 0; i < game->width * game->height; i++)
	// {
	// 	pixel = (int *)(game->window.img + i * (game->window.bpp / 8));
	// 	*pixel = 0x000000; // couleur noire
	// }


//game->width * IMG_SIZE faire un variable
//game->width * IMG_SIZE faire un variable

// #include <math.h>

// double lerp(double start, double end, double t)
// {
// 	return start + t * (end - start);
// }

// double smoothdamp(double current, double target, double *currentVelocity, double smoothTime, double maxSpeed, double deltaTime)
// {
// 	double num = 2.0 / smoothTime;
// 	double num2 = num * deltaTime;
// 	double num3 = 1.0 / (1.0 + num2 + 0.48 * num2 * num2 + 0.235 * num2 * num2 * num2);
// 	double num4 = current - target;
// 	double num5 = target;
// 	double num6 = maxSpeed * smoothTime;
// 	num4 = fmax(fmin(num4, num6), -num6);
// 	double num7 = (*currentVelocity + num * num4) * deltaTime;
// 	*currentVelocity = (*currentVelocity - num * num7) * num3;
// 	double num8 = target + (num4 + num7) * num3;
// 	if (num5 - current > 0.0 == num8 > num5)
// 	{
// 		num8 = num5;
// 		*currentVelocity = (num8 - num5) / deltaTime;
// 	}
// 	return num8;
// }

// double move_toward(double current, double target, double maxDelta)
// {
// 	if (fabs(target - current) <= maxDelta)
// 	{
// 		return target;
// 	}
// 	return current + (target - current) / fabs(target - current) * maxDelta;
// }

	// double shake_intensity = 5; // Adjust the intensity of the camera shake
	// double shake_speed = 3.1; // Adjust the speed of the camera shake

	// if (game->player.movement.moved) {
	// 	double shake_offset_x = sin(game->fps.elapsed * shake_speed) * shake_intensity;
	// 	double shake_offset_y = cos(game->fps.elapsed * shake_speed) * shake_intensity;
	// 	game->camera.x += shake_offset_x;
	// 	game->camera.y += shake_offset_y;
	// }


	// 		double shake_intensity = 5; // Adjust the intensity of the camera shake
	// double shake_speed = 3.1; // Adjust the speed of the camera shake

	// 	double shake_offset_x = sin(game->fps.elapsed * shake_speed) * shake_intensity;
	// 	double shake_duration = 0.5; // Duration of the camera shake in seconds
	// 	double shake_offset_y = 0.0;
	// 	if (game->player.movement.moved) {
	// 		double shake_time = fmod(game->fps.elapsed, shake_duration);
	// 		shake_offset_y = sin(shake_time * shake_speed) * shake_intensity;
	// 	}
	// 	game->camera.x += shake_offset_x;
	// 	game->camera.y += shake_offset_y;

// 	void	ft_init_player_info(t_game *game)
// {
// 	game->player.life = TRUE;
// 	game->player.storage = FALSE;
// 	game->player.frames = PLAYER_FRAMES;
// 	game->player.step = FALSE;
// 	game->player.storage = FALSE;
// 	game->player.movement.moved = FALSE;
// 	game->player.movement.current_position.x = FALSE;
// 	game->player.movement.current_position.y = FALSE;
// 	// game->player.movement.target_position.x = FALSE;
// 	// game->player.movement.target_position.y = FALSE;
// 	// game->player.movement.speed = 900.0;
// 	// game->player.movement.visual.x = game->player.movement.current_position.x * IMG_SIZE;
// 	// game->player.movement.visual.y = game->player.movement.current_position.y * IMG_SIZE;
// 	ft_direction_by_pos_after_launch(game);
// }

	// game->window.img = mlx_new_image(game->mlx, game->window.width, game->window.height);
	// if (game->window.img == NULL)
	// 	ft_print_error("back buffer failed to create", game);
	//game->window.img_data = mlx_get_data_addr(game->win, &game->window.bpp, &game->window.size_line, &game->window.endian);
	//  if (!game->window.img_data)
    //     ft_print_error("Error getting data address of back buffer", game);

	// 	printf("\n\nImage Data: %p\n", game->window.img);
    // printf("BPP: %d\n", game->window.bpp);
    // printf("Size Line: %d\n", game->window.size_line);
    // printf("Endian: %d\n", game->window.endian);


	// mlx_expose_hook();
	// (1L << 0)


	// char	**ft_create_map_with_border(t_game *game)
// {
// 	int		row;
// 	int		column;
// 	char	**new_map;
// 	int		new_width;
// 	int		new_height;

// 	new_height = game->height + 2 * game->map.border_width;
// 	new_width = game->width + 2 * game->map.border_width;
// 	new_map = (char **)malloc((new_height + 1) * sizeof(char *));
// 	if (!new_map)
// 		ft_print_error("create map with border fail", game);
// 	row = 0;
// 	while (row < new_height)
// 	{
// 		new_map[row] = (char *)malloc((new_width + 1) * sizeof(char));
// 		if (!new_map[row])
// 			ft_clean_fail_malloc_split_map(game, new_map, row);
// 		column = 0;
// 		while (column < new_width)
// 		{
// 			if (row < game->map.border_width || row >= new_height - game->map.border_width || column < game->map.border_width || column >= new_width - game->map.border_width)
// 				new_map[row][column] = BORDER_CHAR;
// 			else
// 				new_map[row][column] = game->map.matrice[row - game->map.border_width][column - game->map.border_width];
// 			column++;
// 		}
// 		new_map[row][new_width] = '\0';
// 		row++;
// 	}
// 	new_map[row] = NULL;
// 	if (game->map.matrice)
// 		ft_clean_grid_map(game->map.matrice, game->height);
// 	game->height = new_height;
// 	game->width = new_width;
// 	return (new_map);
// }


// void ft_init_map_with_borders(t_game *game)
// {
//     int new_width = game->width + 2 * 2;
//     int new_height = game->height + 2 * 2;
//     char *new_map = malloc(new_width * new_height
//		* sizeof(char));//sercure malloc

//     for (int y = 0; y < new_height; y++)
//     {
//         for (int x = 0; x < new_width; x++)
//         {
//             if (x < 1 || x >= game->width + 1
// || y < 1 || y >= game->height + 1)
//             {
//                 new_map[y * new_width + x] = BORDER_CHAR;
// or any other character for the border
//             }
//             else
//             {
//                 new_map[y * new_width + x] =
// game->map.map_str[(y - 1) * game->width + (x - IMG_SIZE)];
//             }
//         }
//     }
// void ft_init_map_with_borders(t_game *game)
// {
// ft_clean_grid_map(game->map.matrice, game->height);
// 	ft_print_display_grid(new_map);
// }
//     free(game->map.map_str);
//     game->map.map_str = new_map;
//     game->width = new_width;
//     game->height = new_height;
// }


// void	ft_render(t_game *game)
// {
// 	game->camera.x = game->player.position.x
//* IMG_SIZE - (game->width * IMG_SIZE / 2);
// 	game->camera.y = game->player.position.y
//* IMG_SIZE - (game->height * IMG_SIZE / 2);

// 	mlx_clear_window(game->mlx, game->win);
// 	ft_put_sprites_by_line(game);
// 	ft_print_info_on_window(game);
// }
// void	ft_draw_sprite(t_game *game, void *sprite_img, int x, int y)
// {
// int				sprite_width;
// 	int				sprite_height;
// 	int				i;
// 	int				j;
// 	char			*dst;
// 	char			*src;
// 	unsigned int	color;
// 	char			*sprite_data;
// 	int				sprite_bpp;
// 	int				sprite_size_line;
// 	int				sprite_endian;

// 	// Récupérer les données de l'image du sprite
// 	sprite_data = mlx_get_data_addr(sprite_img, &sprite_bpp, &sprite_size_line, &sprite_endian);
// 	sprite_width = 64;
// 	sprite_height = 64;

// 	// Parcourir chaque pixel du sprite
// 	for (i = 0; i < sprite_height; i++)
// 	{
// 		for (j = 0; j < sprite_width; j++)
// 		{
// 			// Calculer la position du pixel source et destination
// 			src = sprite_data + (i * sprite_size_line + j * (sprite_bpp / 8));
// 			dst = game->window.img_data + ((y + i) * game->window.size_line + (x + j) * (game->window.bpp / 8));

// 			// Récupérer la couleur du pixel source
// 			color = *(unsigned int *)src;

// 			// Gestion de la transparence
// 			// if (color != 0xFF000000) // 0xFF000000 pour la transparence (si applicable)
// 			*(unsigned int *)dst = color;
// 		}
// 	}
// }
// game->window.img = mlx_new_image(game->mlx, game->window.width, game->window.height);
	// if (game->window.img == NULL)
	// 	ft_print_error("game->window.img_data fail", game);
	// game->window.img_data = mlx_get_data_addr(game->window.img, &game->window.bpp, &game->window.size_line, &game->window.endian);
	// if (game->window.img_data == NULL)
	// 	ft_print_error("game->window.img_data fail", game);
	// int	i;
	// int j;
	// int	color = 0xffffff;

	// for (i = 0; i < game->window.height; i++)
	// {
	// 	for (j = 0; j < game->window.width; j++)
	// 	{
	// 		*(unsigned int*)(game->window.img_data + (i * game->window.size_line) + (j * (game->window.bpp / 8))) = color;
	// 	}
	// }
	// ft_draw_sprite(game, game->grass.animation.current, 500, 500);
	// ft_draw_sprite(game, game->love.animation.current, 500, 500);
	// ft_printf("-----------------------------------------------");
	// ft_printf("\n\nImage Data: %p\n", game->window.img_data);
	// ft_printf("BPP: %d\n", game->window.bpp);
	// ft_printf("Size Line: %d\n", game->window.size_line);
	// ft_printf("Endian: %d\n", game->window.endian);
	// ft_printf("-----------------------------------------------\n");
	// ft_printf("Screen Width -> [%d]\n", game->window.width);
	// ft_printf("Screen Height -> [%d]\n\n", game->window.height);
	//mlx_put_image_to_window(game->mlx, game->win, game->window.img, 0, 0);

// void ft_alpha_blend(t_game *game, t_point pos, void *sprite, int width, int height) {
//     int x, y;
//     int color;
//     int dst_offset;
//     int src_offset;
//     char *src_data;
//     int a, r, g, b;
//     int bg_r, bg_g, bg_b;

//     src_data = mlx_get_data_addr(sprite, &game->bpp, &game->size_line, &game->endian);

//     for (y = 0; y < height; y++) {
//         for (x = 0; x < width; x++) {
//             src_offset = (y * game->size_line) + (x * (game->bpp / 8));
//             dst_offset = ((pos.y + y) * game->size_line) + ((pos.x + x) * (game->bpp / 8));

//             color = *(int *)(src_data + src_offset);
//             a = (color >> 24) & 0xFF;
//             r = (color >> 16) & 0xFF;
//             g = (color >> 8) & 0xFF;
//             b = color & 0xFF;

//             bg_r = game->img_data[dst_offset + 2] & 0xFF;
//             bg_g = game->img_data[dst_offset + 1] & 0xFF;
//             bg_b = game->img_data[dst_offset] & 0xFF;

//             game->img_data[dst_offset + 2] = (r * a + bg_r * (255 - a)) / 255;
//             game->img_data[dst_offset + 1] = (g * a + bg_g * (255 - a)) / 255;
//             game->img_data[dst_offset] = (b * a + bg_b * (255 - a)) / 255;
//         }
//     }
// }

//ft_capture_screen(game, "screenshot.bmp");

// void ft_capture_screen(t_game *game, const char *filename) {
//     int fd;
//     int filesize = 54 + 3 * game->win_width * game->win_height;
//     unsigned char bmpfileheader[14] = {
//         'B', 'M', filesize, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0
//     };
//     unsigned char bmpinfoheader[40] = {
//         40, 0, 0, 0, game->win_width, 0, 0, 0, game->win_height, 0, 0, 0, 1, 0, 24, 0
//     };
//     unsigned char bmppad[3] = {0, 0, 0};
//     int i, j;
//     int *img_data_int = (int *)game->img_data;

//     fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
//     if (fd < 0) {
//         ft_print_error("Error opening file for screenshot", game);
//     }

//     write(fd, bmpfileheader, 14);
//     write(fd, bmpinfoheader, 40);

//     for (i = 0; i < game->win_height; i++) {
//         for (j = 0; j < game->win_width; j++) {
//             int pixel = img_data_int[(game->win_height - i - 1) * game->win_width + j];
//             unsigned char color[3] = {pixel & 0xFF, (pixel >> 8) & 0xFF, (pixel >> 16) & 0xFF};
//             write(fd, color, 3);
//         }
//         write(fd, bmppad, (4 - (game->win_width * 3) % 4) % 4);
//     }

//     close(fd);
// }

// void	ft_generic_animation(t_animation *animation, int *frame)
// {
// 	if (*frame == animation->frames)
// 		animation->current = animation->frame_1;
// 	else if (*frame >= animation->frames * 2)
// 	{
// 		animation->current = animation->frame_2;
// 		*frame = 0;
// 	}
// }

// void	ft_digits_animation(t_game *game)
// {
// 	static int	frame_zero;
// 	static int	frame_one;
// 	static int	frame_two;
// 	static int	frame_tree;
// 	static int	frame_four;
// 	static int	frame_five;
// 	static int	frame_six;
// 	static int	frame_seven;
// 	static int	frame_eight;
// 	static int	frame_nine;

// 	ft_generic_animation(&game->hud.digits.zero, &frame_zero);
// 	ft_generic_animation(&game->hud.digits.one, &frame_one);
// 	ft_generic_animation(&game->hud.digits.two, &frame_two);
// 	ft_generic_animation(&game->hud.digits.tree, &frame_tree);
// 	ft_generic_animation(&game->hud.digits.four, &frame_four);
// 	ft_generic_animation(&game->hud.digits.five, &frame_five);
// 	ft_generic_animation(&game->hud.digits.six, &frame_six);
// 	ft_generic_animation(&game->hud.digits.seven, &frame_seven);
// 	ft_generic_animation(&game->hud.digits.eight, &frame_eight);
// 	ft_generic_animation(&game->hud.digits.nine, &frame_nine);
// }


// mets le path dans const char	*paths[]  et la maccor error message de ft_pritnerror dns const cahr * errors_messages et appel la fonction ft_ load_animation sprites avec game->, game, paths, et error_messa


// void	ft_put_sprites_by_line(t_game *game)
// {
// 	int		width;
// 	int		height;
// 	int		win_width;
// 	int		win_height;
// 	t_point	sprite_pos;

// 	win_width = ((game->width * IMG_SIZE) / 2);
// 	win_height = ((game->height * IMG_SIZE) / 2);

// 	// Only render visible sprites
// 	int start_x = (game->camera.current.x / IMG_SIZE) - 1;
// 	int end_x = ((game->camera.current.x + win_width) / IMG_SIZE) + 1;
// 	int start_y = (game->camera.current.y / IMG_SIZE) - 1;
// 	int end_y = ((game->camera.current.y + win_height) / IMG_SIZE) + 1;

// 	start_x = start_x < 0 ? 0 : start_x;
// 	end_x = end_x > game->width ? game->width : end_x;
// 	start_y = start_y < 0 ? 0 : start_y;
// 	end_y = end_y > game->height ? game->height : end_y;

// 	for (height = start_y; height < end_y; height++)
// 	{
// 		for (width = start_x; width < end_x; width++)
// 		{
// 			sprite_pos.x = ((width * IMG_SIZE) - game->camera.current.x);
// 			sprite_pos.y = ((height * IMG_SIZE) - game->camera.current.y);
// 			ft_put_all_sprites_to_line(game, width, height, sprite_pos);
// 		}
// 	}
// }
