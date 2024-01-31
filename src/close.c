#include <stdlib.h>

#include "mlx/mlx.h"
#include "libft/libft.h"

#include "typedef.h"

void close_game(t_tetris *tetris)
{
	free(tetris->current_piece);
	ft_lstclear(&tetris->pieces, &free);
}

int	close_tetris(t_tetris *tetris)
{
	mlx_destroy_image(tetris->mlx, tetris->start_img.ptr);
	mlx_destroy_image(tetris->mlx, tetris->game_img.ptr);
	mlx_destroy_image(tetris->mlx, tetris->block_img.ptr);
	mlx_destroy_window(tetris->mlx, tetris->win.ptr);
	mlx_destroy_display(tetris->mlx);
	free(tetris->mlx);
	exit(EXIT_SUCCESS);
}
