#include <stdlib.h>
#include <unistd.h>

#include "libft/libft.h"
#include "mlx/mlx.h"

#include "event.h"
#include "typedef.h"

static void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return ;
	game->window = mlx_new_window(game->mlx, 11 * 32, 21 * 32, "TETRIS");
}

static void	check_game(t_game *game)
{
	if (game->mlx == NULL)
	{
		ft_putendl_fd("mlx_init()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (game->window == NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_putendl_fd("mlx_new_window()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	main()
{
	t_game	game;

	init_game(&game);
	check_game(&game);

	init_menu_events(&game);

	mlx_loop(game.mlx);
	return 0;
}
