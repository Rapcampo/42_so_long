/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:56:56 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/22 00:37:50 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


static int	map_walls(t_map *map)
{
	
}

static int	map_path(t_game *game)
{
	auto int i = -1;
	auto char **map_matrix = malloc(sizeof(char *) * (game->map->rows + 1));
	if (!map_matrix)
		exit_message(game, "\e[5;1;31Malloc Error.\n\e[0m");
	while (game->map->map_matrix[++i])
		map_matrix[i] = ft_strdup(game->map->map_matrix[i]);
	map_matrix[i] = NULL;
	floodfill(game, map_matrix, game->curr);
	destroy_matrix(map_matrix);
	return (game->path == 1 && game->path_collect == game->map->num_items);
}

void	valid_map(t_game *game)
{
	if (!game->map->map_matrix[0])
		exit_message(game, "\e[5;1;31mMap empty.\n\e[0m");
	if (!map_rectangular(game->map))
		exit_message(game, "\e[5;1;31mMap format is not rectangular.\n\e[0m");
	if (!map_components(game))
		exit_message(game, "\e[5;1;31mMap assets are not valid.\n\e[0m");
	if (!map_walls(game->map))
		exit_message(game, "\e[5;1;31mMap is missing walls.\n\e[0m");
	if (!map_path(game))
		exit_message(game, "\e[5;1;31mMap path is not valid.\n\e[0m");
	game->map->width = game->map->cols * SIZE;
	game->map->height = game->map->rows * SIZE;
}
