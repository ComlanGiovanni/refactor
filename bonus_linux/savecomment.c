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
