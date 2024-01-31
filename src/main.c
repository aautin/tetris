#include <stdlib.h>
#include <unistd.h>

#include "libft/libft.h"
#include "mlx/mlx.h"

#include "event.h"
#include "menu.h"
#include "close.h"
#include "game.h"
#include "typedef.h"

static void	init_tetris(t_tetris *tetris);
static void	check_tetris(t_tetris *tetris);

int	main()
{
	t_tetris	tetris;

	init_tetris(&tetris);
	check_tetris(&tetris);

	init_closing_events(&tetris);
	launch_menu(&tetris);

//	init_game_overlay(&tetris);
//	check_game_overlay(&tetris);
//
//	mlx_put_image_to_window(tetris.mlx, tetris.win.ptr, tetris.game_img.ptr, 16, 80);
//
//	tetris.block.ptr = mlx_xpm_file_to_image(tetris.mlx, "sprites/block.xpm", &tetris.block.width, &tetris.block.height);
//
//	t_tetromino piece = {16, 80, 
//						{{1, 1, 0, 0},
//						{1, 1, 0, 0},
//						{0, 0, 0, 0},
//						{0, 0, 0, 0}}};
//	tetris.current_piece = piece;
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (piece.mat_pos[i][j] != 0)
//				mlx_put_image_to_window(tetris.mlx, tetris.win.ptr, tetris.block.ptr, piece.x + j * 32, piece.y + i * 32);
//		}
//	}

	mlx_loop(tetris.mlx);
	return 0;
}

static void	init_tetris(t_tetris *tetris)
{
	tetris->mlx = mlx_init();
	if (tetris->mlx == NULL)
		return ;
	tetris->win.width = 11 * 32;
	tetris->win.height = 21 * 32;
	tetris->win.ptr = mlx_new_window(tetris->mlx, tetris->win.width,
									tetris->win.height, "TETRIS");
	init_closing_events(tetris);
}

static void	check_tetris(t_tetris *tetris)
{
	if (tetris->mlx == NULL)
	{
		ft_putendl_fd("mlx_init()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (tetris->win.ptr == NULL)
	{
		mlx_destroy_display(tetris->mlx);
		free(tetris->mlx);
		ft_putendl_fd("mlx_new_window()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
