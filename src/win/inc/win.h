#ifndef WIN_H
# define WIN_H

# include <stdlib.h>

// Arrow keys
# define K_UP 0xff52
# define K_DOWN 0xff54
# define K_LEFT 0xff51
# define K_RIGHT 0xff53

// WASD keys
# define K_W 0x0077
# define K_A 0x0061
# define K_S 0x0073
# define K_D 0x0064

# define K_Q 0x0071
# define K_E 0x0065
# define K_L 0x006c

// PAD keys
# define K_PAD_2 0xff99
# define K_PAD_4 0xff96
# define K_PAD_6 0xff98
# define K_PAD_8 0xff97
# define K_PAD_7 0xff95
# define K_PAD_9 0xff9a
# define K_PAD_PLS 0xffab
# define K_PAD_MIN 0xffad

// HOT KEYS
# define K_ESC 0xff1b
# define K_CTRL 0xffe3
# define K_SHIFT 0xffe1
# define K_ALT 0xffe9
# define K_TAB 0xff09
# define K_SPACE 0x0020

// Mouse keys
# define M_LEFT 1
# define M_RIGHT 3

typedef enum e_px_quality
{
	LOW,
	HIGH
}			t_px_quality;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endn;
	int		px_grid;
	int		w;
	int		h;
}			t_img;

typedef struct s_win
{
	void	*mlx;
	void	*ptr;
	int		w;
	int		h;
	char	*title;
	t_img	img;
}			t_win;

t_win		*get_win(void);
t_img		*get_win_img(void);

int			init_win(int w, int h, char *title);
int			init_win_img(void);

int			open_win(void);
int			close_win(void);

void		set_px_quality(t_px_quality quality);
void		win_img_fill_grid(int start_x, int start_y, int color);

void		render_win_img(void);
void		destroy_win_img(void);
void		destroy_win(void);

// Events
void		handle_win_event(void);

#endif