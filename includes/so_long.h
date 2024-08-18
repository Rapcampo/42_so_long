
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:08:20 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/17 16:17:23 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx/mlx.h" 
# include <X11/X.h>
# include <X11/keysym.h>

// Keysyms for keypresses

# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

// defines for assets
# define MAX_SPRITES 5
# define ENTITIES "01CEP"
# define BG_SPRITE "../assets/sprites/background.xpm"
# define WALL_SPRITE "../assets/sprites/wall.xpm"
# define PLAYER_SPRITE "../assets/sprites/player.xpm"
# define COLLECT_SPRITE "../assets/sprites/collectable.xpm"
# define EXIT_SPRITE "../assets/sprites/exit.xpm"

// struct for mlx

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	int		line_lenght;
	int		bpp;
	int		endian;
	char	*addr;
}	t_window;

// struct for coordinates

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// struct for assets

typedef struct s_assets
{
	void	*sprites;
	int		width;
	int		height;
}	t_assets;


// struct for map

typedef struct s_map
{
	char	**map;
	int		cols;
	int		rows;
	int		num_items;
	int		num_exit;
	int		num_player;
}	t_map;

// strct for gamestate

typedef struct s_game
{
	t_window	win;
	t_point		curr;
	t_point		next;
	t_map		*map;
	t_assets	*assets;
	int			moves;
	int			collect;
}	t_game;

// enum for map entities

typedef enum e_entity
{
	FLOOR = '0',
	WALL = '1',
	POTION = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}	t_entity; 

// enum for event hook mask
// defined in x11/x.h 
// close mask is for substructureNotifyMask for creation or destruction of win

typedef enum e_mask
{
	NOEVENT_MASK	= 0L,
	KEYPRESS_MASK	= (1L << 0),
	SUBNOTE_MASK	= (1L << 17)
}	t_mask;

typedef enum e_event
{
	E_kEYPRESS	= 2,
	E_DESTROY	= 17
}	t_event;

#endif
