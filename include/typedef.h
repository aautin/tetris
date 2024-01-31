#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
}	t_img;

typedef struct s_tetris
{
	void	*mlx;
	void	*window;
}	t_tetris;

#endif
