#ifndef SCENE_H
# define SCENE_H

# include "../../color/inc/color.h"
# include "../../win/inc/win.h"

typedef struct s_scene
{
	t_win	*win;
}			t_scene;

t_scene		*get_scene(void);
int			init_scene(int w, int h, char *title);
void		init_render(void);
void		render_scene(void);
void		destroy_scene(void);

#endif