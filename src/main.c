#include "minirt.h"

int	main(void)
{
	init_scene(400, 400, "miniRT");
	init_render();
	render_scene();
	return (0);
}