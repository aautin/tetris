#include <unistd.h>
#include <stdlib.h>

#include "mlx/mlx.h"
#include "libft/libft.h"

#include "close.h"
#include "collision.h"
#include "tetromino.h"
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
			if (tetris->current_piece->mat_pos[i][j] == 0)
				continue ;
			erase_sprite(tetris, tetris->current_piece->x + j * 32,
						tetris->current_piece->y + i * 32);
		}
	}
}

static void	draw_tetromino(t_tetris *tetris)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tetris->current_piece->mat_pos[i][j] == 0)
				continue ;
			mlx_put_image_to_window(tetris->mlx, tetris->win.ptr,
									tetris->block_img.ptr,
									tetris->current_piece->x	+ j * 32,
									tetris->current_piece->y + i * 32);
		}
	}
}

void	move_tetromino(t_tetris *tetris, e_direction direction)
{
	t_list	*new_node;

	if (direction != D_NONE)
	{
		if (detect_collision_down(tetris))
		{
			new_node = ft_lstnew(tetris->current_piece);
			if (new_node == NULL)
			{
				close_game(tetris);
				close_tetris(tetris);
			}
			ft_lstadd_back(&tetris->pieces, new_node);
			set_tetromino(tetris);
			move_tetromino(tetris, D_NONE);
			return ;
		}
		if (detect_collision(tetris, direction))
			return ;
	}
	remove_tetromino(tetris);
	if (direction & D_DOWN)
		tetris->current_piece->y += 32;
	if (direction & D_RIGHT)
		tetris->current_piece->x += 32;
	if (direction & D_LEFT)
		tetris->current_piece->x -= 32;
	draw_tetromino(tetris);
}

void	set_tetromino(t_tetris *tetris)
{
	tetris->current_piece = (t_tetromino *)malloc(1 * sizeof(t_tetromino));
	if (tetris->current_piece == NULL)
	{
		ft_putendl_fd("Malloc error", STDERR_FILENO);
		close_game(tetris);
		close_tetris(tetris);
	}
	tetris->current_piece->x = 16 + (4 * 32);
	tetris->current_piece->y = 64 + 16;

	tetris->current_piece->mat_pos[0][0] = 1;
	tetris->current_piece->mat_pos[0][1] = 0;
	tetris->current_piece->mat_pos[0][2] = 0;
	tetris->current_piece->mat_pos[0][3] = 0;

	tetris->current_piece->mat_pos[1][0] = 1;
	tetris->current_piece->mat_pos[1][1] = 0;
	tetris->current_piece->mat_pos[1][2] = 0;
	tetris->current_piece->mat_pos[1][3] = 0;

	tetris->current_piece->mat_pos[2][0] = 1;
	tetris->current_piece->mat_pos[2][1] = 0;
	tetris->current_piece->mat_pos[2][2] = 0;
	tetris->current_piece->mat_pos[2][3] = 0;

	tetris->current_piece->mat_pos[3][0] = 1;
	tetris->current_piece->mat_pos[3][1] = 0;
	tetris->current_piece->mat_pos[3][2] = 0;
	tetris->current_piece->mat_pos[3][3] = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (i == 0 && j == 0)
//				tetris->current_piece->mat_pos[i][j] = 1;
//			else
//				tetris->current_piece->mat_pos[i][j] = 0;
//		}
//	}
}
