#include <stdlib.h>

#define NUM_TETROMINOES 5

void	set_random_tetromino(char mat_pos[4][4])
{
	int	random;
	const char tetrominoes[NUM_TETROMINOES][4][4] = {
		{	{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{	{1, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{	{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{	{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{	{1, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		}
	};
	random = rand() % NUM_TETROMINOES;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			mat_pos[i][j] = tetrominoes[random][i][j];
	}
}
