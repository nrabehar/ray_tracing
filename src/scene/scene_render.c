#include "minirt.h"

void	init_render(void)
{
	open_win();
}

void	render_scene(void)
{
	t_win	*win;
	int		pxy[2];
	t_color	c;

	win = get_scene()->win;
	clear_win();
	pxy[1] = 0;
	c = color(0.2, 0.1, 0.2);
	while (pxy[1] < win->h)
	{
		pxy[0] = 0;
		while (pxy[0] < win->w)
		{
			win_img_fill_grid(pxy[0], pxy[1], cl_to_int(c));
			pxy[0] += get_win_img()->px_grid;
		}
		pxy[1] += get_win_img()->px_grid;
	}
	render_win_img();
	handle_win_event();
}
