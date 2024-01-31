#include <stddef.h>
#include <time.h>
#include <unistd.h>

#include "libft/libft.h"
#include "mlx/mlx.h"

#include "close.h"
#include "collision.h"
#include "tetromino.h"
#include "typedef.h"

int time_loop(t_tetris *tetris)
{
	time_t	time_current;
	time_t	time_spent;

	if (tetris->state == GAME)
	{
		time_current = time(NULL);
		time_spent = time_current - tetris->time_start;
		if (time_spent >= 1)
		{
			if (!detect_collision_down(tetris))
				move_tetromino(tetris, D_DOWN);
			else
				new_tetromino(tetris);
			tetris->time_start = time(NULL);
		}
	}
	return 0;
}

int	switch_to_game(t_tetris *tetris)
{
	tetris->current_piece = NULL;
	tetris->pieces = NULL;
	mlx_clear_window(tetris->mlx, tetris->win.ptr);
	tetris->state = GAME;
	mlx_put_image_to_window(tetris->mlx, tetris->win.ptr,
							tetris->game_img.ptr, 14, 78);
	tetris->time_start = time(NULL) + 2;
	set_tetromino(tetris);
	move_tetromino(tetris, D_NONE);
	return 0;
}
