#include <stdlib.h>

#include "mlx/mlx.h"

#include "typedef.h"

int	close_tetris(t_tetris *tetris)
{
	mlx_destroy_image(tetris->mlx, tetris->start_img.ptr);
	mlx_destroy_window(tetris->mlx, tetris->win.ptr);
	mlx_destroy_display(tetris->mlx);
	free(tetris->mlx);
	exit(EXIT_SUCCESS);
}
