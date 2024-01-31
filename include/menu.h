#ifndef MENU_H
# define MENU_H

#include "typedef.h"

/* @brief Switch in menu mode, reseting the scene
 * @param tetris
 * @return Always returns 0
*/
int		switch_to_menu(t_tetris *tetris);

/* @brief Check if the mouse is within the start button box
 * @param x position x of the mouse
 * @param y position y of the mouse
 * @param tetris
 * @return 1 if the mouse is within the range, 0 otherwise
*/
int		is_on_start_button(int x, int y, t_tetris *tetris);

#endif