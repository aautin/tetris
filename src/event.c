#define XK_MISCELLANY

#include <stdlib.h>
#include <X11/keysymdef.h>
#include <X11/X.h>

#include "mlx/mlx.h"
#include "libft/libft.h"

#include "close.h"
#include "game.h"
#include "menu.h"
#include "tetromino.h"
#include "typedef.h"

int	key_pressed(int keycode, t_tetris *tetris)
{
	if (tetris->state == MENU)
	{
		if (keycode == XK_Escape)
			close_tetris(tetris);
		else if (keycode == XK_Return)
			switch_to_game(tetris);
	}
	else if (tetris->state == GAME)
	{
		if (keycode == XK_Escape)
		{
			close_game(tetris);
			switch_to_menu(tetris);
		}
		else if (keycode == XK_Right)
			move_tetromino(tetris, D_RIGHT);
		else if (keycode == XK_Down)
			move_tetromino(tetris, D_DOWN);
		else if (keycode == XK_Left)
			move_tetromino(tetris, D_LEFT);
	}
	return 0;
}

int	button_pressed(int keycode, int x, int y, t_tetris *tetris)
{
	if (keycode == 1 && tetris->state == MENU && is_on_start_button(x, y, tetris))
		switch_to_game(tetris);
	return 0;
}

void	init_closing_events(t_tetris *tetris)
{
	mlx_hook(tetris->win.ptr, DestroyNotify, NoEventMask, &close_tetris, tetris);
	mlx_hook(tetris->win.ptr, ButtonPress, ButtonPressMask, &button_pressed, tetris);
	mlx_hook(tetris->win.ptr, KeyPress, KeyPressMask, &key_pressed, tetris);
}
