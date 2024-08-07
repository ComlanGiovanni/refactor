/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lava_event_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:40:59 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/08 01:06:29 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

typedef struct s_node {
    t_point pos;
    int g; // Cost from start to this node
    int f; // Total cost (g + h)
    struct s_node *parent;
} t_node;

int heuristic(t_point a, t_point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Function to compare nodes
int compare_nodes(const void *a, const void *b) {
    t_node *node_a = *(t_node **)a;
    t_node *node_b = *(t_node **)b;
    return node_a->f - node_b->f;
}

// Function to check if two points are equal
int is_same_point(t_point a, t_point b) {
    return a.x == b.x && a.y == b.y;
}

// Function to check if the position is walkable
int is_walkable(char **grid, int x, int y) {
    return grid[y][x] != '1';
}

int ft_is_obstacle(t_game *game, int x, int y) {
    char tile = game->map.map_str[y * game->width + x];
    return (tile == WALL_CHAR);
}

void	ft_random_keke_move(t_game *game)
{
	t_point start = ft_find_pos_char(game->map.grid, game->map.size, KEKE_CHAR);
    t_point goal = game->player.movement.current_position;

    // Listes pour A*
    t_node *open_list[game->map.len];
    t_node *closed_list[game->map.len];
    int open_count = 0;
    int closed_count = 0;

    // Ajouter le point de départ à la liste ouverte
    t_node *start_node = malloc(sizeof(t_node));
    start_node->pos = start;
    start_node->g = 0;
    start_node->f = heuristic(start, goal);
    start_node->parent = NULL;
    open_list[open_count++] = start_node;

    // Directions possibles: haut, bas, gauche, droite
    t_point directions[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    char dir_char[4] = {'u', 'd', 'l', 'r'};

    while (open_count > 0) {
        // Trier la liste ouverte par coût total (f)
        qsort(open_list, open_count, sizeof(t_node *), compare_nodes);

        // Prendre le nœud avec le coût le plus bas
        t_node *current = open_list[0];

        // Si nous avons atteint l'objectif
        if (is_same_point(current->pos, goal)) {
            // Reconstruire le chemin et définir la direction pour Keke
            while (current->parent && !is_same_point(current->parent->pos, start)) {
                current = current->parent;
            }
            for (int i = 0; i < 4; i++) {
                if (is_same_point((t_point){start.x + directions[i].x, start.y + directions[i].y}, current->pos)) {
                    game->keke.direction = dir_char[i];
                    break;
                }
            }
            break;
        }

        // Déplacer le nœud courant de la liste ouverte à la liste fermée
        open_count--;
        for (int i = 0; i < open_count; i++) {
            open_list[i] = open_list[i + 1];
        }
        closed_list[closed_count++] = current;

        // Explorer les voisins
        for (int i = 0; i < 4; i++) {
            int neighbor_x = current->pos.x + directions[i].x;
            int neighbor_y = current->pos.y + directions[i].y;

            // Vérifier si le voisin est dans les limites de la carte et est franchissable
            if (neighbor_x < 0 || neighbor_y < 0 || neighbor_x >= game->width || neighbor_y >= game->height ||
                !is_walkable(game->map.grid, neighbor_x, neighbor_y)) {
                continue;
            }

            t_point neighbor_pos = {neighbor_x, neighbor_y};

            // Vérifier si le voisin est déjà dans la liste fermée
            int in_closed = 0;
            for (int j = 0; j < closed_count; j++) {
                if (is_same_point(closed_list[j]->pos, neighbor_pos)) {
                    in_closed = 1;
                    break;
                }
            }
            if (in_closed) continue;

            // Créer un nouveau nœud pour ce voisin
            t_node *neighbor_node = malloc(sizeof(t_node));
            neighbor_node->pos = neighbor_pos;
            neighbor_node->g = current->g + 1;
            neighbor_node->f = neighbor_node->g + heuristic(neighbor_pos, goal);
            neighbor_node->parent = current;

            // Vérifier si ce voisin est déjà dans la liste ouverte
            int in_open = 0;
            for (int j = 0; j < open_count; j++) {
                if (is_same_point(open_list[j]->pos, neighbor_pos) && open_list[j]->g <= neighbor_node->g) {
                    in_open = 1;
                    free(neighbor_node);
                    break;
                }
            }
            if (!in_open) {
                open_list[open_count++] = neighbor_node;
            }
        }
    }

    // Libérer la mémoire allouée
    for (int i = 0; i < open_count; i++) free(open_list[i]);
    for (int i = 0; i < closed_count; i++) free(closed_list[i]);
	// Move keke in the chosen direction
	ft_move_keke(game);
}

void	ft_move_keke(t_game *game)
{
	if (game->keke.direction == 'u')
		ft_keke_move_up(game);
	if (game->keke.direction == 'd')
		ft_keke_move_down(game);
	if (game->keke.direction == 'l')
		ft_keke_move_left(game);
	if (game->keke.direction == 'r')
		ft_keke_move_right(game);
}


