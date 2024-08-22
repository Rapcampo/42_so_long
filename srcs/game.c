#include "../includes/so_long.h"

t_entity    pos(t_game *game, t_point curr)
{
    return (game->map->map_matrix[curr.y][curr.x]);
}

void    move_player(t_game *game)
{
    if (pos(game, game->next) == COL)
    {
        game->map->num_items--;
        game->map->map_matrix[game->next.y][game->next.x] = FLOOR;
    }
    else if (pos(game, game->next) == EXIT)
        game
}

int check_move(t_game *game, t_point next)
{
    if (game->map->map_matrix[next.y][next.x] == WALL)
        return (0);
    else if (next.y == game->curr.y && next.x == game->curr.x)
        return (0);
    return (1);
}

int put_game(t_game *game)
{
    if (!check_move(game, game->next))
        return (0);
    game->moves++;
    ft_printf("\e[4;1;32mMovements\e[0m = \e[1;35m%d\e[0m\n", game->moves);
    move_player(game);
    return (0);
}