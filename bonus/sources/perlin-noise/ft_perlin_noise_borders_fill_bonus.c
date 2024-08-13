/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin_noise_borders_fill_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:32:24 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/13 00:39:36 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

typedef struct s_fill_char_state
{
	const char		*selected_fill_chars;
	int				selected_fill_chars_size;
}					t_fill_char_state;

const char	*get_fill_chars_1(void)
{
	static const char	fill_chars[] = {WATER_CHAR, GRASS_CHAR, FLOWER_CHAR,
		TREE_CHAR, TREES_CHAR, REED_CHAR, ALGAE_CHAR, FUNGI_CHAR,
		FUNGUS_CHAR, HUSKS_CHAR};

	return (fill_chars);
}

const char	*get_fill_chars_2(void)
{
	static const char	fill_chars[] = {WATER_CHAR, GRASS_CHAR,
		FLOWER_CHAR, TREE_CHAR};

	return (fill_chars);
}

const char	*get_fill_chars_3(void)
{
	static const char	fill_chars[] = {WATER_CHAR, GRASS_CHAR,
		FUNGI_CHAR, REED_CHAR, FUNGUS_CHAR, HUSKS_CHAR};

	return (fill_chars);
}

const char	*get_fill_chars_4(void)
{
	static const char	fill_chars[] = {WATER_CHAR, GRASS_CHAR};

	return (fill_chars);
}

const char	*get_fill_chars_5(void)
{
	static const char	fill_chars[] = {WATER_CHAR};

	return (fill_chars);
}

const char	*get_fill_chars_6(void)
{
	static const char	fill_chars[] = {GRASS_CHAR};

	return (fill_chars);
}

const char	*get_fill_chars_7(void)
{
	static const char	fill_chars[] = {FUNGUS_CHAR, FUNGI_CHAR};

	return (fill_chars);
}

const char	*get_fill_chars_8(void)
{
	static const char	fill_chars[] = {FLOWER_CHAR};

	return (fill_chars);
}

typedef const char	*(*t_fill_char_function)();

void	initialize_fill_chars(t_fill_char_state *state)
{
	static t_fill_char_function	fill_char_functions[] = {
		get_fill_chars_1, get_fill_chars_2, get_fill_chars_3,
		get_fill_chars_4, get_fill_chars_5, get_fill_chars_6,
		get_fill_chars_7, get_fill_chars_8
	};
	int							num_sets;
	int							set_index;
	static int					fill_char_set_sizes[] = {10, 4, 6,
		2, 1, 1, 2, 1};

	num_sets = sizeof(fill_char_functions) / sizeof(fill_char_functions[0]);
	set_index = rand() % num_sets;
	state->selected_fill_chars = fill_char_functions[set_index]();
	state->selected_fill_chars_size = fill_char_set_sizes[set_index];
}

char	ft_determine_fill_char(float noise_value)
{
	t_fill_char_state	state;
	const char			*selected_fill_chars;
	int					index;
	float				range_size;

	initialize_fill_chars(&state);
	selected_fill_chars = state.selected_fill_chars;
	range_size = 2.0 / state.selected_fill_chars_size;
	if (noise_value < -1.0)
		noise_value = -1.0;
	if (noise_value > 1.0)
		noise_value = 1.0;
	index = (int)((noise_value + 1.0) / range_size);
	if (index < 0)
		index = 0;
	if (index >= state.selected_fill_chars_size)
		index = state.selected_fill_chars_size - 1;
	return (selected_fill_chars[index]);
}

// // Taille de la plage pour chaque caractère
// // Limite la valeur de bruit à -1.0
// // Limite la valeur de bruit à 1.0
// // Calcule l'index du caractère à utiliser
// // Limite l'index minimum
// // Limite l'index maximum
// // Retourne le caractère correspondant
// char	ft_determine_fill_char(float noise_value)
// {
// 	int					num_chars;
// 	int					index;
// 	float				range_size;
// 	// static const char	fill_chars_0[] = {WATER_CHAR, GRASS_CHAR, FLOWER_CHAR,
// 	// 	TREE_CHAR, TREES_CHAR, REED_CHAR, ALGAE_CHAR, FUNGI_CHAR, FUNGUS_CHAR, HUSKS_CHAR};
// 	// static const char	fill_chars_1[] = {WATER_CHAR, GRASS_CHAR, FLOWER_CHAR,
// 	// 	TREE_CHAR};
// 	// static const char	fill_chars_2[] = {WATER_CHAR, GRASS_CHAR, FUNGI_CHAR,
// 	// 	REED_CHAR, FUNGUS_CHAR, HUSKS_CHAR};
// 	// static const char	fill_chars_3[] = {WATER_CHAR, GRASS_CHAR};
// 	// static const char	fill_chars_4[] = {WATER_CHAR};
// 	// static const char	fill_chars_5[] = {GRASS_CHAR};
// 	static const char	fill_chars_6[] = {FUNGUS_CHAR};
// 	static const char	fill_chars_7[] = {FLOWER_CHAR};
// 	num_chars = sizeof(fill_chars) / sizeof(fill_chars[0]);
// 	range_size = 2.0 / num_chars;
// 	if (noise_value < -1.0)
// 		noise_value = -1.0;
// 	if (noise_value > 1.0)
// 		noise_value = 1.0;
// 	index = (int)((noise_value + 1.0) / range_size);
// 	if (index < 0)
// 		index = 0;
// 	if (index >= num_chars)
// 		index = num_chars - 1;
// 	return (fill_chars[index]);
// }
