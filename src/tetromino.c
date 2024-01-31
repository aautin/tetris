#include "mlx/mlx.h"

#include "typedef.h"

char	detect_collision_right(t_tetris *tetris)
{
	int	max_x;

	max_x = -1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tetris->current_piece.mat_pos[i][j] == 0)
				continue ;
			if (max_x == -1 || max_x < j)
				max_x = j;
		}
	}
	return  tetris->current_piece.x + (max_x + 1) * 32 >= tetris->win.width - 16;
}

char	detect_collision_left(t_tetris *tetris)
{
	int	max_x;

	max_x = 4;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tetris->current_piece.mat_pos[i][j] == 0)
				continue ;
			if (max_x == 4 || max_x > j)
				max_x = j;
		}
	}
	return  tetris->current_piece.x + max_x * 32 <= 16;
}

char	detect_collision_down(t_tetris *tetris)
{
	int	max_y;

	max_y = -1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tetris->current_piece.mat_pos[i][j] == 0)
				continue ;
			if (max_y == -1 || max_y < i)
				max_y = i;
		}
	}
	return  tetris->current_piece.y + (max_y + 1) * 32 >= tetris->win.height - 16;
}

char detect_collision(t_tetris *tetris, e_direction direction)
{
	if (direction & D_RIGHT)
		return detect_collision_right(tetris);
	if (direction & D_DOWN)
		return detect_collision_down(tetris);
	if (direction & D_LEFT)
		return detect_collision_left(tetris);
	return 1;
}

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
	if (direction != D_NONE)
	{
		if (detect_collision_down(tetris))
			return ;
		if (detect_collision(tetris, direction))
			return ;
	}
	remove_tetromino(tetris);
	if (direction & D_DOWN)
		tetris->current_piece.y += 32;
	if (direction & D_RIGHT)
		tetris->current_piece.x += 32;
	if (direction & D_LEFT)
		tetris->current_piece.x -= 32;
	draw_tetromino(tetris);
}

void	set_tetromino(t_tetris *tetris)
{
	tetris->current_piece.x = 16 + (4 * 32);
	tetris->current_piece.y = 64 + 16;

	tetris->current_piece.mat_pos[0][0] = 1;
	tetris->current_piece.mat_pos[0][1] = 0;
	tetris->current_piece.mat_pos[0][2] = 0;
	tetris->current_piece.mat_pos[0][3] = 0;

	tetris->current_piece.mat_pos[1][0] = 1;
	tetris->current_piece.mat_pos[1][1] = 0;
	tetris->current_piece.mat_pos[1][2] = 0;
	tetris->current_piece.mat_pos[1][3] = 0;

	tetris->current_piece.mat_pos[2][0] = 1;
	tetris->current_piece.mat_pos[2][1] = 0;
	tetris->current_piece.mat_pos[2][2] = 0;
	tetris->current_piece.mat_pos[2][3] = 0;

	tetris->current_piece.mat_pos[3][0] = 1;
	tetris->current_piece.mat_pos[3][1] = 0;
	tetris->current_piece.mat_pos[3][2] = 0;
	tetris->current_piece.mat_pos[3][3] = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (i == 0 && j == 0)
//				tetris->current_piece.mat_pos[i][j] = 1;
//			else
//				tetris->current_piece.mat_pos[i][j] = 0;
//		}
//	}
}
