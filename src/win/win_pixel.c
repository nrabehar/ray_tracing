#include "minirt.h"

static void	put_px(int x, int y, int clr)
{
	t_img	*img;
	t_win	*win;
	char	*dst;
	int		offset;

	win = get_win();
	if (x < 0 || x >= win->w || y < 0 || y >= win->h)
		return ;
	img = get_win_img();
	offset = (y * img->l_len + x * (img->bpp / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = clr;
}

void	set_px_quality(t_px_quality quality)
{
	t_img	*img;

	img = get_win_img();
	if (quality == LOW)
		img->px_grid = 4;
	else
		img->px_grid = 1;
}

void	win_img_fill_grid(int start_x, int start_y, int color)
{
	t_img	*img;
	int		x;
	int		y;

	img = get_win_img();
	if (img->px_grid == 1)
	{
		put_px(start_x, start_y, color);
		return ;
	}
	y = -1;
	while (++y < img->px_grid)
	{
		x = -1;
		while (++x < img->px_grid)
			put_px(start_x + x, start_y + y, color);
	}
}
