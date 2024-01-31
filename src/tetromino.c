#include "mlx/mlx.h"

#include "typedef.h"

void	move_tetromino(t_tetris *tetris, e_direction direction)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tetris->current_piece.mat_pos[i][j] != 0)
			{
				for (int k = 0; k < 32; k++)
				{
					for (int l = 0; l < 32; l++)
					{
						mlx_pixel_put(tetris->mlx, tetris->win.ptr,
									tetris->current_piece.x + j * 32 + l,
									tetris->current_piece.y + i * 32 + k, 0x00000000);
					}
				}
			}
		}
	}
	if (direction & D_DOWN)
		tetris->current_piece.y += 32;
	if (direction & D_RIGHT)
		tetris->current_piece.x += 32;
	if (direction & D_LEFT)
		tetris->current_piece.x -= 32;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tetris->current_piece.mat_pos[i][j] != 0)
				mlx_put_image_to_window(tetris->mlx, tetris->win.ptr,
										tetris->block_img.ptr,
										tetris->current_piece.x + j * 32,
										tetris->current_piece.y + i * 32);
		}
	}
}

#include <stdio.h>

void	set_tetromino(t_tetris *tetris)
{
	tetris->current_piece.x = 16 + (4 * 32);
	tetris->current_piece.y = 64 + 16;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 && j == 0)
				tetris->current_piece.mat_pos[i][j] = 1;
			else
				tetris->current_piece.mat_pos[i][j] = 0;
		}
	}
	
}
