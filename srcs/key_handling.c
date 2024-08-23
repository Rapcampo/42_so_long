/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:35:39 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/23 18:59:52 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_message(t_game *game, char *message)
{
	if (game)
		destroy_game(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_putstr_fd(message, 2);
	exit(1);
}

int	quit(t_game *game)
{
	if (game->map->map_matrix[game->next.y][game->next.x] == E2)
		ft_putstr_fd(BLINK GREEN "🎉🎉 YOU WIN!!! 🎉🎉\n" RESET, 1);
	else
		ft_putstr_fd(BLINK RED "Game Interrpted 🛑\n" RESET, 1);
	destroy_game(game);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
		quit(game);
	if (keycode == UP || keycode == W)
		game->next = (t_point){game->curr.x, game->curr.y - 1};
	if (keycode == DOWN || keycode == S)
		game->next = (t_point){game->curr.x, game->curr.y + 1};
	if (keycode == LEFT || keycode == A)
		game->next = (t_point){game->curr.x - 1, game->curr.y};
	if (keycode == RIGHT || keycode == D)
		game->next = (t_point){game->curr.x + 1, game->curr.y};
	return (keycode);
}
