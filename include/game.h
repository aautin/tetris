#ifndef GAME_H
# define GAME_H

#include "typedef.h"

// void	move_tetronimo(t_tetris *tetris, t_tetromino *piece, e_direction direction);
int time_loop(t_tetris *tetris);

/* @brief Switch in game mode, reseting the scene
 * @param tetris
 * @return Always returns 0
*/
int	switch_to_game(t_tetris *tetris);

#endif
