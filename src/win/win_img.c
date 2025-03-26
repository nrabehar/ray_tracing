#include "minirt.h"

t_img	*get_win_img(void)
{
	return (&get_win()->img);
}

int	init_win_img(void)
{
	t_win	*win;
	t_img	*img;

	win = get_win();
	img = get_win_img();
	img->w = win->w;
	img->h = win->h;
	img->ptr = mlx_new_image(win->mlx, img->w, img->h);
	if (!img->ptr)
		return (-1);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->l_len, &img->endn);
	if (!img->addr)
		return (-1);
	img->px_grid = 1;
	return (0);
}

void	render_win_img(void)
{
	t_win	*win;
	t_img	*img;

	win = get_win();
	img = get_win_img();
	mlx_put_image_to_window(win->mlx, win->ptr, img->ptr, 0, 0);
}

void	destroy_win_img(void)
{
	t_img	*img;

	img = get_win_img();
	if (img->ptr)
		mlx_destroy_image(get_win()->mlx, img->ptr);
	img->ptr = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->l_len = 0;
	img->endn = 0;
}
