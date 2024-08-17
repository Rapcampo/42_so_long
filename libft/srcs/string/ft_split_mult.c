/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:04:41 by rapcampo          #+#    #+#             */
/*   Updated: 2024/04/06 21:25:10 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char c, char *sep)
{
	auto int i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_usep(char *str, char *sep)
{
	auto int i = 1;
	while (ft_is_sep(str[i], sep) == 0 && str[i])
		i++;
	return (i);
}

static int	ft_count_malloc(char *str, char *sep)
{
	auto int numsep = 0;
	auto int check = 1;
	auto int i = 0;
	while (str[i])
	{
		if (check == 0 && ft_is_sep(str[i], sep))
			check = 1;
		if (check == 1 && ft_is_sep(str[i], sep) == 0)
			check = 2;
		if (check == 2 && (ft_is_sep(str[i], sep) || str[i + 1] == '\0'))
		{
			check = 0;
			numsep++;
		}
		else
			i++;
	}
	return (numsep);
}

static void	*ft_free(char **split, int k)
{
	auto int i = 0;
	while (i < k)
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
	return (NULL);
}

char	**ft_split_mult(char *str, char *charset)
{
	int	j;

	auto int numsep = ft_count_malloc(str, charset);
	auto char **split = malloc(sizeof(char *) * (numsep + 1));
	auto int i = 0;
	auto int k = -1;
	while (++k < numsep)
	{
		j = -1;
		while (ft_is_sep(str[i], charset) == 1 && str[i])
			i++;
		split[k] = malloc(sizeof(char) * (ft_usep(str + i, charset) + 1));
		if (!split[k])
			return (ft_free(split, k));
		while (str[i] && ft_is_sep(str[i], charset) == 0 && ++j > -10)
			split[k][j] = str[i++];
		split[k][j + 1] = '\0';
		i++;
	}
	split[k] = 0;
	return (split);
}
