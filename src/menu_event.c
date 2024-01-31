#define XK_MISCELLANY

#include <stdlib.h>
#include <X11/keysymdef.h>
#include <X11/X.h>


#include "mlx/mlx.h"

#include "typedef.h"

int	close_program(t_tetris *tetris)
{
	mlx_destroy_window(tetris->mlx, tetris->window);
	mlx_destroy_display(tetris->mlx);
	free(tetris->mlx);
	exit(EXIT_SUCCESS);
}

int	key_pressed(int keycode, t_tetris *tetris)
{
	if (keycode == XK_Escape)
		close_program(tetris);
	return 0;
}

void	init_menu_events(t_tetris *tetris)
{
	mlx_hook(tetris->window, DestroyNotify, NoEventMask, &close_program, tetris);
	mlx_hook(tetris->window, KeyPress, KeyPressMask, &key_pressed, tetris);
}
