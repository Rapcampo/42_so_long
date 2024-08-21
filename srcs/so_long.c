/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:51:52 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/20 19:02:44 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	load_win(t_game *game)
{
	if (!game->win.mlx_ptr = mlx_init())
	{
		free_map(game->map->map);
		return (0);
	}
	if (!load_sprites(game))
	{
		mlx_destroy_display(game->win.mlx_ptr);
		free(game->win.mlx_ptr);
		free_map(game->map->map);
		return (0);
	}
	game->win.win_ptr = mlx_new_window(game->win.mlx_ptr, 1280, 720, "so_long");
	if (!game->win.win_ptr)
	{
		mlx_destroy_display(game->win.mlx_ptr);
		free(game->win.mlx_ptr);
		free_map(game->map->map);
		return (0);
	}
	return (1);
}

static int	game_init(char *map)
{
	t_game	game;
	int		error;

	 //error = map_check(&game, map);
	 error = 0;
	if (error)
		return (error);
	if (!load_win(&game))
		return (error = 8);
	game.moves = 0;
	game.collect = 0;
	player_location(&game);
	print_map(&map);
	mlx_hook(game.win.win_ptr, E_DESTROY, SUBNOTE_MASK, &quit_game, &game);
	mlx_hook(game.win.win_ptr, E_kEYPRESS, KEYPRESS_MASK, &key_handling, &game);
	mlx_do_key_autorepeaton(game->win.mlx_ptr);
	mlx_loop(game->win.mlx_ptr);
	return (0);
}

int main(int argc, char *argv[])
{
	int	err_code;

	err_code = 0;
	if (argc == 2)
	{
		err_code = map_extension(argv[1]);
		if (err_code = 0)
			err_code = game_init(argv[1]);
		if (err_code != 0)
			ft_err(err_code);
	}
	else
		ft_err(-1);
	return (0);
}
