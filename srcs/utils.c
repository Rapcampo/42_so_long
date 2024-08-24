/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:39:01 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/21 23:53:54 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	floodfill(t_game *game, char **matrix, t_point curr)
{
	if (curr.y < 0 || curr.x < 0 ||
			curr.y >= game->map->rows || curr.x >= game->map->cols)
		return ;
	if (matrix[curr.y][curr.x] == '1')
		return ;
	else if (matrix[curr.y][curr.x] == 'C')
		game->path_collect++;
	else if (matrix[curr.y][curr.x] == 'E')
		game->path = 1;
	matrix[curr.y][curr.x] = '1';
	floodfill(game, matrix, (t_point){curr.x + 1, curr.y});
	floodfill(game, matrix, (t_point){curr.x - 1, curr.y});
	floodfill(game, matrix, (t_point){curr.x, curr.y + 1});
	floodfill(game, matrix, (t_point){curr.x, curr.y - 1});
}

void	destroy_matrix(char **map_matrix)
{
	auto int i = -1;
	while (map_matrix[++i])
		free(map_matrix[i]);
	free(map_matrix[i]);
	free(map_matrix);
}

void	map_assets(t_game *game)
{
	auto int i = -1;
	auto int j = -1;
	while (game->map->map_matrix[++i])
	{
		j = -1;
		while (game->map->map_matrix[i][++j])
		{
			if (game->map->map_matrix[i][j] == 'P')
				game->curr = (t_point){j, i};
			else if (game->map->map_matrix[i][j] == 'E')
				game->exit = (t_point){j, i};
		}
	}
}
