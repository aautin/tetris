#include "typedef.h"

char	detect_collision_right(t_tetris *tetris)
{
	int	max_x;

	max_x = -1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tetris->current_piece->mat_pos[i][j] == 0)
				continue ;
			if (max_x == -1 || max_x < j)
				max_x = j;
		}
	}
	return  tetris->current_piece->x + (max_x + 1) * 32 >= tetris->win.width - 16;
}

char	detect_collision_left(t_tetris *tetris)
{
	int	max_x;

	max_x = 4;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tetris->current_piece->mat_pos[i][j] == 0)
				continue ;
			if (max_x == 4 || max_x > j)
				max_x = j;
		}
	}
	return  tetris->current_piece->x + max_x * 32 <= 16;
}

char	detect_collision_down(t_tetris *tetris)
{
	int	max_y;

	max_y = -1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tetris->current_piece->mat_pos[i][j] == 0)
				continue ;
			if (max_y == -1 || max_y < i)
				max_y = i;
		}
	}
	return  tetris->current_piece->y + (max_y + 1) * 32 >= tetris->win.height - 16;
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

static char	detect_tetromino_left(t_tetris *tetris)
{
	t_list		*node;
	t_tetromino	*tetromino;

	node = tetris->pieces;
	while (node)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				tetromino = (t_tetromino *)(node->content);
				if (tetromino->mat_pos[i][j] == 1)
				{
					for (int k = 0; k < 4; k++)
					{
						for (int l = 0; l < 4; l++)
						{
							if (tetris->current_piece->mat_pos[k][l] == 1)
							{
								if (tetromino->y + i * 32 == tetris->current_piece->y + k * 32)
								{
									if (tetromino->x + j * 32 == tetris->current_piece->x + l * 32 - 32)
										return 1;
								}  
							}
						}
					}
				}
			}
		}
		node = node->next;
	}
	return 0;
}

static char	detect_tetromino_right(t_tetris *tetris)
{
	t_list		*node;
	t_tetromino	*tetromino;

	node = tetris->pieces;
	while (node)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				tetromino = (t_tetromino *)(node->content);
				if (tetromino->mat_pos[i][j] == 1)
				{
					for (int k = 0; k < 4; k++)
					{
						for (int l = 0; l < 4; l++)
						{
							if (tetris->current_piece->mat_pos[k][l] == 1)
							{
								if (tetromino->y + i * 32 == tetris->current_piece->y + k * 32)
								{
									if (tetromino->x + j * 32 == tetris->current_piece->x + l * 32 + 32)
										return 1;
								}  
							}
						}
					}
				}
			}
		}
		node = node->next;
	}
	return 0;
}

char	detect_tetromino_down(t_tetris *tetris)
{
	t_list		*node;
	t_tetromino	*tetromino;

	node = tetris->pieces;
	while (node)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				tetromino = (t_tetromino *)(node->content);
				if (tetromino->mat_pos[i][j] == 1)
				{
					for (int k = 0; k < 4; k++)
					{
						for (int l = 0; l < 4; l++)
						{
							if (tetris->current_piece->mat_pos[k][l] == 1)
							{
								if (tetromino->x + j * 32 == tetris->current_piece->x + l * 32)
								{
									if (tetromino->y + i * 32 == tetris->current_piece->y + k * 32 + 32)
										return 1;
								}  
							}
						}
					}
				}
			}
		}
		node = node->next;
	}
	return 0;
}

char	detect_tetromino(t_tetris *tetris, e_direction direction)
{
	if (direction & D_RIGHT)
		return detect_tetromino_right(tetris);
	if (direction & D_DOWN)
		return detect_tetromino_down(tetris);
	if (direction & D_LEFT)
		return detect_tetromino_left(tetris);
	return 1;
}
