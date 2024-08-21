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

static int	init_game(char *map)
{
	t_game	game;

	game.win.mlx_ptr = mlx_init();
	game.win.width = 1280;
	game.win.height = 720;

	return (0);
}

int main(int argc, char *argv[])
{
	int	err_code;

	(void)argv;
	err_code = 0;
	if (argc == 2)
	{
		//err_code = map_check(argv[1]);
	}
	else
		ft_err(-1);
	return (0);
}
