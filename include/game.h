#ifndef GAME_H
# define GAME_H

#include "typedef.h"

void	init_game_overlay(t_tetris *tetris);
void	check_game_overlay(t_tetris *tetris);
void	move_tetronimo(t_tetris *tetris, t_tetromino *piece, e_direction direction);
#endif
