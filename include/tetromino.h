#ifndef TETROMINO_H
# define TETROMINO_H

# include "typedef.h" 

void	move_tetromino(t_tetris *tetris, e_direction direction);
void	set_tetromino(t_tetris *tetris);
char detect_collision(t_tetris *tetris, e_direction direction);
char	detect_collision_right(t_tetris *tetris);
char	detect_collision_left(t_tetris *tetris);
char	detect_collision_down(t_tetris *tetris);
#endif
