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

static int	map_rectangular(t_map *map)
{
	auto int i = 0;
	auto size_t columns = ft_strlen(map->map_matrix[i]);
	while (map->map_matrix[i])
	{
		if (ft_strlen(map->map_matrix[i]) != columns)
			return (0);
		i++;
	}
	return (map->cols = columns, 1);
}

static int	map_components(t_game *game)
{
	auto int i = -1;
	while (game->map->map_matrix[++i])
	{
		auto int j = -1;
		while (game->map->map_matrix[i][++j])
		{
			if (game->map->map_matrix[i][j] == 'C')
				game->map->num_items++;
			else if (game->map->map_matrix[i][j] == 'P')
				game->map->num_player++;
			else if (game->map->map_matrix[i][j] == 'E')
				game->map->num_exit++;
			else if (game->map->map_matrix[i][j] != '0' &&
				game->map->map_matrix[i][j] != '1')
				exit_message(game, "\e[5;1;31Invalid characters.\n\e[0m");
		}
	}
	map_assets(game);
	if (game->map->num_items >= 1 && game->map->num_exit == 1
		&& game->map->num_player == 1)
		return (1);
	return (0);
}

int	map_walls(t_map *map)
{
	auto unsigned int i = -1;
	while (map->map_matrix[++i])
	{
		auto unsigned int j = -1;
		if (i == 0 || i == map->rows)
		{
			while (map->map_matrix[i][++j])
			{
				if (map->map_matrix[i][j] != '1')
					return (0);
			}
		}
		else
		{
			if (map->map_matrix[i][0] != '1' ||
			map->map_matrix[i][map->cols -1] != '1')
				return (0);
		}
	}
	return (1);
}

int	map_path(t_game *game)
{
	char	**map_matrix;

	auto int i = -1;
	map_matrix = malloc(sizeof(char *) * (game->map->rows + 1));
	if (!map_matrix)
		exit_message(game, BLINK RED "Malloc Error.\n" RESET);
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
		exit_message(game, BLINK RED "Map empty.\n" RESET);
	if (!map_rectangular(game->map))
		exit_message(game, BLINK RED "Map format is not rectangular.\n" RESET);
	if (!map_components(game))
		exit_message(game, BLINK RED "Map assets are not valid.\n" RESET);
	if (!map_walls(game->map))
		exit_message(game, BLINK RED "Map is missing walls.\n" RESET);
	if (!map_path(game))
		exit_message(game, BLINK RED "Map path is not valid.\n" RESET);
	game->map->width = game->map->cols * SIZE;
	game->map->height = game->map->rows * SIZE;
}
