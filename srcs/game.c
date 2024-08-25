/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:00:11 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/23 17:00:53 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_entity	pos(t_game *game, t_point curr)
{
	return (game->map->map_matrix[curr.y][curr.x]);
}

void	move_player(t_game *game)
{
	if (pos(game, game->next) == COL)
	{
		game->map->num_items--;
		game->map->map_matrix[game->next.y][game->next.x] = PLAYER;
	}
	else if (pos(game, game->next) == EXIT)
		game->map->map_matrix[game->next.y][game->next.x] = PLAYER;
	else if (pos(game, game->next) == OPEN_EXIT)
		quit(game);
	else
		game->map->map_matrix[game->next.y][game->next.x] = PLAYER;
	if (game->map->map_matrix[game->curr.y][game->curr.x] == EXIT)
		game->map->map_matrix[game->curr.y][game->curr.x] = EXIT;
	else
		game->map->map_matrix[game->curr.y][game->curr.x] = FLOOR;
	put_images(game, game->curr);
	put_images(game, game->next);
	game->curr = game->next;
}

int	check_move(t_game *game, t_point next)
{
	if (game->map->map_matrix[next.y][next.x] == WALL)
		return (0);
	else if (next.y == game->curr.y && next.x == game->curr.x)
		return (0);
	return (1);
}

int	put_game(t_game *game)
{
	if (!check_move(game, game->next))
		return (0);
	game->moves++;
	ft_printf(ULINE BLUE"Moves = %d\n"RESET, game->moves);
	return (move_player(game), 0);
}
