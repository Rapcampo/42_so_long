/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:22:06 by rapcampo          #+#    #+#             */
/*   Updated: 2024/08/21 21:33:23 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include <fcntl.h>
//# include <X11/X.h>
//# include <X11/keysym.h>

// defines for assets

# define MAX_SPRITES 6
# define BG_SPRITE "./sprites/floor.xpm"
# define WALL_SPRITE "./sprites/wall.xpm"
# define PLAYER_SPRITE "./sprites/player.xpm"
# define PE_SPRITE "./sprites/player_exit.xpm"
# define COLLECT_SPRITE "./sprites/collectable.xpm"
# define EXIT_SPRITE "./sprites/exit.xpm"
# define OE_SPRITE "./prites/open_exit.xpm"
# define SIZE 32 

// defines for print colours

# define RESET "\e[0m"
# define ULINE "\e[4m"
# define BLINK "\e[5m"
# define BLACK "\e[1;30m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE  "\e[1;34m"
# define PURPLE "\e[1;35m"
# define CYAN "\e[1;36m"
# define WHITE "\e[1;37m"



typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}		t_point;

// struct for assets

typedef struct s_assets
{
	void	*img;
	int		width;
	int		height;
}			t_assets;


// struct for map

typedef struct s_map
{
	char				**map_matrix;
	unsigned int		cols;
	unsigned int		rows;
	unsigned int		num_items;
	unsigned int		num_exit;
	unsigned int		num_player;
	int					height;
	int					width;
}						t_map;

// strct for gamestate

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_point			curr;
	t_point			next;
	t_point			exit;
	t_map			*map;
	t_assets		*assets;
	unsigned int	moves;
	unsigned int	collect;
	unsigned int	path;
	unsigned int	path_collect;
}	t_game;

// enum for map entities

typedef enum e_entity
{
	FLOOR = '0',
	WALL = '1',
	COL = 'C',
	EXIT = 'E',
	PLAYER = 'P',
	PLAYER_EXIT = 'X',
	OPEN_EXIT = 'O'
}	t_entity;

//enum for keysyms

typedef enum s_keys
{
	ESC = 65307,
	A = 97,
	S = 115,
	D = 100,
	W = 119,
	Q = 113,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361
}	t_key;

typedef enum e_index
{
	F1,
	W1,
	P1,
	P2,
	C1,
	E1,
	E2,
}			t_index;

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

//error checking and map parsing

void	put_images(t_game *game, t_point pos);
void	floodfill(t_game *game, char **matrix, t_point curr);
void	map_assets(t_game *game);
void	valid_map(t_game *game);

//free and memory management

void	destroy_matrix(char **map_matrix);
void	destroy_map(t_map *map);
void	destroy_images(t_game *game);
void	destroy_game(t_game *game);

//game functions

void		exit_message(t_game *game, char *message);
void		init_game(char *map_name);
int			quit(t_game *game);
t_entity	pos(t_game *game, t_point pos);
int			check_move(t_game *game, t_point next);
void		move_player(t_game *game);
void		start_game(t_game *game);
int			put_game(t_game *game);
int			key_press(int keycode, t_game *game);

#endif
