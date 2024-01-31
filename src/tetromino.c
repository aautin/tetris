#include "mlx/mlx.h"

#include "typedef.h"

static void	erase_sprite(t_tetris *tetris, int x, int y)
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			mlx_pixel_put(tetris->mlx, tetris->win.ptr,
						x + i,
						y + j, 0x00000000);
		}
	}
}

static void	remove_tetromino(t_tetris *tetris)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tetris->current_piece.mat_pos[i][j] == 0)
				continue ;
			erase_sprite(tetris, tetris->current_piece.x + j * 32,
						tetris->current_piece.y + i * 32);
		}
	}
}

static void	draw_tetromino(t_tetris *tetris)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tetris->current_piece.mat_pos[i][j] == 0)
				continue ;
			mlx_put_image_to_window(tetris->mlx, tetris->win.ptr,
									tetris->block_img.ptr,
									tetris->current_piece.x	+ j * 32,
									tetris->current_piece.y + i * 32);
		}
	}
}

void	move_tetromino(t_tetris *tetris, e_direction direction)
{
	remove_tetromino(tetris);
	if (direction & D_DOWN)
		tetris->current_piece.y += 32;
	if (direction & D_RIGHT)
		tetris->current_piece.x += 32;
	if (direction & D_LEFT)
		tetris->current_piece.x -= 32;
	draw_tetromino(tetris);
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
