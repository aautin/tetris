#ifndef TYPEDEF_H
# define TYPEDEF_H

# define MENU 0
# define GAME 1

typedef struct s_win
{
	void	*ptr;
	int		width;
	int		height;
}	t_win;


typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
}	t_img;

typedef struct s_tetromino
{
	int		x;
	int		y;
	char	mat_pos[4][4];
}	t_tetromino;

typedef struct s_tetris
{
	void	*mlx;
	t_win	win;
	t_img	start_img;
	char	state;
	t_img		game_img;
	t_tetromino	current_piece;
	t_img		block;
}	t_tetris;

typedef enum s_direction
{
	NONE = 0,
	D_LEFT = (1 << 0),
	D_DOWN = (1 << 1),
	D_RIGHT = (1 << 2),
	D_UP = (1 << 3)
}	e_direction;

#endif
