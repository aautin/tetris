#include <stddef.h>

#include "mlx/mlx.h"

#include "close.h"
#include "typedef.h"

int	is_on_start_button(int x, int y, t_tetris *tetris)
{
	int	top_edge;
	int	bot_edge;
	int	left_edge;
	int	right_edge;

	top_edge = tetris->win.height / 2 - tetris->start_img.height / 2;
	bot_edge = tetris->win.height / 2 + tetris->start_img.height / 2;
	left_edge = tetris->win.width / 2 - tetris->start_img.width / 2;
	right_edge = tetris->win.width / 2 + tetris->start_img.width / 2;

	return left_edge <= x
			&& x <= right_edge
			&& bot_edge >= y
			&& y >= top_edge;
}

int	switch_to_menu(t_tetris *tetris)
{
	mlx_clear_window(tetris->mlx, tetris->win.ptr);
	tetris->state = MENU;
	mlx_put_image_to_window(tetris->mlx, tetris->win.ptr, tetris->start_img.ptr,
							tetris->win.width / 2 - tetris->start_img.width / 2,
							tetris->win.height / 2 - tetris->start_img.height / 2);
	return 0;
}
