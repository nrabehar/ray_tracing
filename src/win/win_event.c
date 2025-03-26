#include "minirt.h"

static int	win_on_close(void *params)
{
	(void)params;
	destroy_win_img();
	destroy_win();
	return (0);
}

void	handle_win_event(void)
{
	t_win	*win;

	win = get_win();
	mlx_hook(win->ptr, 17, 0, win_on_close, NULL);
	mlx_loop(win->mlx);
}
