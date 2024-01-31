#define XK_MISCELLANY

#include <stdlib.h>
#include <X11/keysymdef.h>
#include <X11/X.h>

#include "mlx/mlx.h"
#include "libft/libft.h"

#include "close.h"
#include "game.h"
#include "menu.h"
#include "typedef.h"

int	key_pressed(int keycode, t_tetris *tetris)
{
	if (keycode == XK_Escape)
		close_tetris(tetris);
	else if (keycode == XK_Return && tetris->state == MENU)
		switch_to_game(tetris);
	else
		ft_putnbr_fd(keycode, 0);
	return 0;
}

int	button_pressed(int keycode, int x, int y, t_tetris *tetris)
{
	if (keycode == 1 && tetris->state == MENU && is_on_start_button(x, y, tetris))
		switch_to_game(tetris);
	else
		ft_putnbr_fd(keycode, 0);
	return 0;
}

void	init_closing_events(t_tetris *tetris)
{
	mlx_hook(tetris->win.ptr, DestroyNotify, NoEventMask, &close_tetris, tetris);
	mlx_hook(tetris->win.ptr, ButtonPress, ButtonPressMask, &button_pressed, tetris);
	mlx_hook(tetris->win.ptr, KeyPress, KeyPressMask, &key_pressed, tetris);
}
