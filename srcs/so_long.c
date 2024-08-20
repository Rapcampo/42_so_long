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
#include "../minilibx/mlx.h"

int main(int argc, char *argv[])
{
	t_window mlx;
	mlx.width = ft_atoi(argv[0]);
	mlx.height = ft_atoi(argv[1]);
	if (argc == 4)
	{
		mlx.mlx_ptr = mlx_init();
		if (!mlx.mlx_ptr)
			return (-1);
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.width, mlx.height, argv[2]);
		if (!mlx.win_ptr)
			return (-1);
		mlx_loop(mlx.mlx_ptr);
	}
	if (mlx.win_ptr)
		mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	if (mlx.mlx_ptr)
		free(mlx.mlx_ptr);
	return (0);
}
