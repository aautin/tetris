#include "mlx/mlx.h"

#include "typedef.h"

int	launch_menu(t_tetris *tetris)
{
	tetris->start_img.ptr = mlx_xpm_file_to_image(tetris->mlx,
												"sprites/start_button.xpm",
												&tetris->start_img.width,
												&tetris->start_img.height);
	mlx_put_image_to_window(tetris->mlx, tetris->win.ptr,
							tetris->start_img.ptr,
							(tetris->win.width / 2) - tetris->start_img.width / 2,
							(tetris->win.height / 2) - tetris->start_img.height / 2);

	return 0;
}
