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
static void	init_imgs(t_tetris *tetris);
static void	check_imgs(t_tetris *tetris);

int	main()
{
	t_tetris	tetris;

	init_tetris(&tetris);
	check_tetris(&tetris);
	
	init_imgs(&tetris);
	check_imgs(&tetris);
	
	switch_to_menu(&tetris);

	mlx_loop_hook(tetris.mlx, &time_loop, &tetris);
	mlx_loop(tetris.mlx);
	return 0;
}

static void	init_imgs(t_tetris *tetris)
{
	tetris->block_img.ptr = mlx_xpm_file_to_image(tetris->mlx,
												"sprites/block.xpm",
												&tetris->block_img.width,
												&tetris->block_img.height);

	tetris->game_img.ptr = mlx_xpm_file_to_image(tetris->mlx,
												"sprites/game.xpm",
												&tetris->game_img.width,
												&tetris->game_img.height);
	
	tetris->start_img.ptr = mlx_xpm_file_to_image(tetris->mlx,
												"sprites/start.xpm",
												&tetris->start_img.width,
												&tetris->start_img.height);
}

static void	check_imgs(t_tetris *tetris)
{
	if (tetris->game_img.ptr == NULL || tetris->start_img.ptr == NULL || tetris->block_img.ptr == NULL)
	{
		ft_putendl_fd("An issue occured during an img conversion from xpm to image object", STDERR_FILENO);
		close_tetris(tetris);
	}
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
