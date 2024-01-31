#ifndef EVENT_H
# define EVENT_H

#include "typedef.h"

/* @brief Event that is called when a key is pressed.
 * @param keycode the value that stores the keycode
*/
void		key_pressed(int keycode, t_tetris *tetris);

/* @brief Despite its name, it will ask mlx to hook all the events we asked.
 * @param tetris
*/
void		init_closing_events(t_tetris *tetris);

#endif
