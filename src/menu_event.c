#define XK_MISCELLANY

#include <stdlib.h>
#include <X11/keysymdef.h>
#include <X11/X.h>


#include "mlx/mlx.h"

#include "typedef.h"

int	close_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_program(game);
	return 0;
}

void	init_menu_events(t_game *game)
{
	mlx_hook(game->window, DestroyNotify, NoEventMask, &close_program, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, &key_pressed, game);
}
