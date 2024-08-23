/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:48:55 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/23 16:59:24 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_map(t_map *map)
{
	if (!map)
		return ;
	if (!map->map_matrix)
		destroy_matrix(map->map_matrix);
	free(map);
}

void	destroy_images(t_game *game)
{
	auto int i = -1;
	while (++i < NUM_ASSETS)
		mlx_destroy_image(game->mlx_ptr, game->assets[i].img);
	free(game->assets);
}

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		destroy_map(game->map);
	if (game->assets)
		destroy_images(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}
