/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:57:16 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/21 23:38:22 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	get_num_lines(t_game *game, char *map_name)
{
	auto int	lines = 0;
	auto int	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_message(game, "\e[5;1;31mCould not read map file.\n\e[0m");
	while (1)
	{
		auto char *temp = get_next_line(fd);
		if (!temp)
			break ;
		lines++;
		free(temp);
	}
	return (close(fd), lines);
}


static t_map	*new_map(unsigned int colums, unsigned int rows)
{
	auto t_map	*map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->map_matrix = ft_calloc((rows + 1), (sizeof(char *)));
	if (!map->map_matrix)
	{
		destroy_matrix(map->map_matrix);
		return (NULL);
	}
	return (map->cols = colums, map->rows = rows, map);
}

static	t_map	*read_map(t_game *game, char *map_name)
{
	auto int	i = -1;
	game->map = new_map(0, get_num_lines(game, map_name));
	if (!game->map)
		exit_message(game, "\e[5;1;31mMap could not be alloc'ed.\n\e[0m");
	auto int fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_message(game, "\e[5;1;31mCould not read map file.\n\e[0m");
	while (++i < game->map->rows)
	{
		auto char *temp = get_next_line(fd);
		if (temp)
			exit_message(game, "\e[5;1;31mCould not get lines from map.\n\e[0m");
		game->map->map_matrix[i] = ft_strtrim(temp, "\n");
		if (!game->map->map_matrix[i])
			exit_message(game, "\e[5;1;31mError in alloc map bytes.\n\e[0m");
		free(temp);
	}
	return (game->map->map_matrix[i] = NULL, close(fd), game->map);
}

void	init_game(char *map_name)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	read_map(&game, map_name);
	valid_map(&game);
	start_game(&game);
}
