#include <stdlib.h>
#include <unistd.h>

#include "libft/libft.h"
#include "mlx/mlx.h"

#include "event.h"
#include "typedef.h"

static void	init_tetris(t_tetris *tetris)
{
	tetris->mlx = mlx_init();
	if (tetris->mlx == NULL)
		return ;
	tetris->window = mlx_new_window(tetris->mlx, 11 * 32, 21 * 32, "TETRIS");
}

static void	check_tetris(t_tetris *tetris)
{
	if (tetris->mlx == NULL)
	{
		ft_putendl_fd("mlx_init()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (tetris->window == NULL)
	{
		mlx_destroy_display(tetris->mlx);
		free(tetris->mlx);
		ft_putendl_fd("mlx_new_window()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	main()
{
	t_tetris	tetris;

	init_tetris(&tetris);
	check_tetris(&tetris);

	init_menu_events(&tetris);

	mlx_loop(tetris.mlx);
	return 0;
}
