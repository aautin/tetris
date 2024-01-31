#ifndef TETROMINO_H
# define TETROMINO_H

# include "typedef.h" 

void	new_tetromino(t_tetris *tetris);
void	move_tetromino(t_tetris *tetris, e_direction direction);
void	set_tetromino(t_tetris *tetris);

#endif
