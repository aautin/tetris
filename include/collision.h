#ifndef COLLISION_H
# define COLLISION_H

# include "typedef.h" 

char 	detect_collision(t_tetris *tetris, e_direction direction);
char	detect_collision_right(t_tetris *tetris);
char	detect_collision_left(t_tetris *tetris);
char	detect_collision_down(t_tetris *tetris);

#endif