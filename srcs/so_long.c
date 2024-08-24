/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:37:08 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/23 21:54:58 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_exit(t_game *game)
{
	game->map->map_matrix[game->exit.y][game->exit.x] = OPEN_EXIT;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->assets[E2].img, (SIZE * game->exit.x), (SIZE * game->exit.y));
}

void	put_images(t_game *game, t_point pos)
{
	t_assets	sprites;

	if (game->map->num_items == 0)
		put_exit(game);
	if (game->map->map_matrix[pos.x][pos.y] == WALL)
		sprites = game->assets[W1];
	if (game->map->map_matrix[pos.x][pos.y] == PLAYER)
		sprites = game->assets[P1];
	if (game->map->map_matrix[pos.x][pos.y] == PLAYER_EXIT)
		sprites = game->assets[P2];
	if (game->map->map_matrix[pos.x][pos.y] == COL)
		sprites = game->assets[C1];
	if (game->map->map_matrix[pos.x][pos.y] == EXIT)
		sprites = game->assets[E1];
	if (game->map->map_matrix[pos.x][pos.y] == OPEN_EXIT)
		sprites = game->assets[E2];
	if (game->map->map_matrix[pos.x][pos.y] == FLOOR)
		sprites = game->assets[F1];
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprites.img,
		(SIZE * pos.x), (SIZE * pos.y));
}

int	put_graphics(t_game *game)
{
	auto unsigned int i = -1;
	while (game->map->map_matrix[++i])
	{
		auto unsigned int j = -1;
		while (game->map->map_matrix[i][++j])
			put_images(game, (t_point){j, i});
	}
	return (0);
}

void	load_images(t_game *game)
{
	game->assets = malloc(MAX_SPRITES * sizeof(t_assets));
	if (!game->assets)
		exit_message(game, BLINK RED "Could not allocate images\n" RESET);
	game->assets[F1].img = mlx_xpm_to_image(game->mlx_ptr, (char **)BG_SPRITE,
			&game->assets[F1].width, &game->assets[F1].height);
	game->assets[W1].img = mlx_xpm_to_image(game->mlx_ptr, (char **)WALL_SPRITE,
			&game->assets[W1].width, &game->assets[W1].height);
	game->assets[P1].img = mlx_xpm_to_image(game->mlx_ptr, (char **)PLAYER_SPRITE,
			&game->assets[P1].width, &game->assets[P1].height);
	game->assets[P2].img = mlx_xpm_to_image(game->mlx_ptr, (char **) PE_SPRITE,
			&game->assets[P2].width, &game->assets[P2].height);
	game->assets[C1].img = mlx_xpm_to_image(game->mlx_ptr,(char **) COLLECT_SPRITE,
			&game->assets[C1].width, &game->assets[C1].height);
	game->assets[E1].img = mlx_xpm_to_image(game->mlx_ptr,(char **) EXIT_SPRITE,
			&game->assets[E1].width, &game->assets[E1].height);
	game->assets[E2].img = mlx_xpm_to_image(game->mlx_ptr,(char **)OE_SPRITE,
			&game->assets[E2].width, &game->assets[E2].height);
}

void	start_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_message(game, BLINK RED "mlx_init fail!\n" RESET);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->width,
			game->map->height, "So_long");
	if (!game->win_ptr)
		exit_message(game, BLINK RED "mlx_win fail!\n" RESET);
	load_images(game);
	put_graphics(game);
	mlx_hook(game->win_ptr, E_kEYPRESS, KEYPRESS_MASK, &key_press, game);
	mlx_hook(game->win_ptr, E_DESTROY, SUBNOTE_MASK, &quit, game);
	mlx_loop_hook(game->mlx_ptr, &put_game, game);
	mlx_loop(game->mlx_ptr);
}
