/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:09:55 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/21 02:00:26 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_err(int err)
{
	if (err == -1)
		ft_putstr_fd("\e[5;1;31mERROR!\e[0m\nPlease Insert a map\n", 2);
	else if (err == 1)
		ft_putstr_fd
			("\e[5;1;31mERROR!\e[0m\nThere was an issue reading the file\n", 2);
	else if (err == 2)
		ft_putstr_fd("\e[5;1;31mERROR!\e[0m\nFile extention is not .ber\n", 2);
	else if (err == 3)
		ft_putstr_fd("\e[5;1;31mERROR!\e[0m\nInvalid Map: Missing Walls\n", 2);
	else if (err == 4)
		ft_putstr_fd("\e[5;1;31mERROR!\e[0m\nInvalid Map: Invalid Path\n", 2);
	else if (err == 5)
		ft_putstr_fd
			("\e[5;1;31mERROR!\e[0m\nInvalid Map: Not rectangular\n", 2);
	else if (err == 6)
		ft_putstr_fd
			("\e[5;1;31mERROR!\e[0m\nInvalid Map: Invalid contents\n", 2);
	else if (err == 7)
		ft_putstr_fd("\e[5;1;31mERROR!\e[0m\nInvalid Map: Map too big\n", 2);
	else if (err == 8)
		ft_putstr_fd("\e[5;1;31mERROR!\e[0m\nCould not load the game\n", 2);
}
