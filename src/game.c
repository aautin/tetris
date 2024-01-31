#include <stddef.h>
#include <unistd.h>

#include "libft/libft.h"
#include "mlx/mlx.h"

#include "close.h"
#include "typedef.h"

#define GAME_OVERLAY "sprites/game.xpm"

// void	move_tetronimo(t_tetris *tetris, t_tetromino *piece, e_direction direction)
// {
// 	for (int i = 0; i < 4; i++)
// 	{
// 		for (int j = 0; j < 4; j++)
// 		{
// 			if (piece->mat_pos[i][j] != 0)
// 			{
// 				for (int k = 0; k < 32; k++)
// 				{
// 					for (int l = 0; l < 32; l++)
// 					{
// 						mlx_pixel_put(tetris->mlx, tetris->win.ptr, piece->x + j * 32 + l, piece->y + i * 32 + k, 0x00000000);
// 					}
// 				}
// 			}
// 		}
// 	}
// 	if (direction & D_DOWN)
// 		piece->y += 32;
// 	if (direction & D_RIGHT)
// 		piece->x += 32;
// 	if (direction & D_LEFT)
// 		piece->x -= 32;
// 	for (int i = 0; i < 4; i++)
// 	{
// 		for (int j = 0; j < 4; j++)
// 		{
// 			if (piece->mat_pos[i][j] != 0)
// 				mlx_put_image_to_window(tetris->mlx, tetris->win.ptr, tetris->block.ptr, piece->x + j * 32, piece->y + i * 32);
// 		}
// 	}
// }

int	switch_to_game(t_tetris *tetris)
{
	mlx_clear_window(tetris->mlx, tetris->win.ptr);
	tetris->state = GAME;
	mlx_put_image_to_window(tetris->mlx, tetris->win.ptr,
							tetris->game_img.ptr, 16, 80);
	return 0;
}
