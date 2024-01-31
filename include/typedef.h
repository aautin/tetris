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

typedef struct s_tetris
{
	void	*mlx;
	t_win	win;
	t_img	start_img;
	char	state;
}	t_tetris;

#endif
