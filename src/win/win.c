#include "minirt.h"

t_win	*get_win(void)
{
	static t_win	win;

	return (&win);
}

int	init_win(int w, int h, char *title)
{
	t_win	*win;

	win = get_win();
	win->w = w;
	win->h = h;
	win->title = title;
	win->mlx = mlx_init();
	if (!win->mlx)
		return (-1);
	win->ptr = NULL;
	win->img.ptr = NULL;
	win->img.addr = NULL;
	win->img.bpp = 0;
	win->img.l_len = 0;
	win->img.endn = 0;
	win->img.px_grid = 0;
	return (0);
}

int	open_win(void)
{
	t_win	*win;

	win = get_win();
	win->ptr = mlx_new_window(win->mlx, win->w, win->h, win->title);
	if (!win->ptr)
		return (-1);
	if (init_win_img() < 0)
		return (-1);
	return (0);
}

int	close_win(void)
{
	t_win	*win;

	win = get_win();
	if (!win->ptr || !win->mlx)
		return (-1);
	mlx_destroy_window(win->mlx, win->ptr);
	win->ptr = NULL;
	return (0);
}

void	clear_win(void)
{
	t_win	*win;

	win = get_win();
	mlx_clear_window(win->mlx, win->ptr);
}

void	destroy_win(void)
{
	t_win *win;

	win = get_win();
	if (win->ptr)
		close_win();
	if (win->img.ptr)
		destroy_win_img();
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	win->mlx = NULL;
}