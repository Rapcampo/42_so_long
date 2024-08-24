/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:26:43 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/21 22:34:10 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	valid_map_name(char *map_name)
{
	auto int i = ft_strlen(map_name);
	if (!(ft_strnstr((map_name + (i - 4)), ".ber", 4)))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	auto char *map_name = argv[1];
	if (argc != 2)
	{
		ft_putstr_fd("\e[5;1;31mERROR!\n\e[0mPlease, insert a map\n", 2);
		exit(1);
	}
	else if (!valid_map_name(map_name))
	{
		ft_putstr_fd("\e[5;1;31mERROR!\n\e[0mMAP is not .ber file\n", 2);
		exit(1);
	}
	return (init_game(map_name), 0);
}
