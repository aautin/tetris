#define XK_MISCELLANY

#include <stdlib.h>
#include <X11/keysymdef.h>
#include <X11/X.h>

#include "mlx/mlx.h"

#include "close.h"
#include "typedef.h"

int	key_pressed(int keycode, t_tetris *tetris)
{
	if (keycode == XK_Escape)
		close_tetris(tetris);
	return 0;
}

void	init_closing_events(t_tetris *tetris)
{
	mlx_hook(tetris->win.ptr, DestroyNotify, NoEventMask, &close_tetris, tetris);
	mlx_hook(tetris->win.ptr, KeyPress, KeyPressMask, &key_pressed, tetris);
}
