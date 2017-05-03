/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 17:45:54 by abara             #+#    #+#             */
/*   Updated: 2016/09/13 14:04:58 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 600

# include <math.h>
# include "libft/libft.h"
# include "mlx.h"

typedef struct		s_fractal
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			middle;
	double			zoomx;
	double			zoomy;
	double			add;
	int				max;
}					t_fractal;

typedef struct		s_help
{
	int				xc;
	int				yc;
	int				x;
	int				y;
}					t_help;

typedef struct		s_circle
{
	t_help			help;
	int				x;
	int				y;
	int				zoom;
	int				index;
	int				max;
	int				r;
	int				xc;
	int				yc;
	int				*color;
}					t_circle;

typedef struct		s_option
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				color;
	int				select;
	struct s_option	*next;
}					t_option;

typedef struct		s_winfo
{
	t_fractal		fractal;
	t_option		*option;
	t_circle		circle;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				color;
	int				select;
	int				lock;
	int				bpp;
	int				line;
	int				endian;
	int				a;
	int				b;
	int				x;
	int				y;
}					t_winfo;

void				set_winfo(t_winfo *winfo);
void				set_fractal(t_winfo *winfo);
int					key_press(int key, void *param);
void				clear(t_winfo *winfo);
void				put_pixel(t_winfo *winfo, int x, int y, int *color);
void				fill_rect(t_winfo *winfo, t_option *opt, int *color);
void				circle(t_winfo *winfo, int xc, int yc, int r);
void				module_rect(t_winfo *winfo, int xc, int yc, int size);
int					*set_color(int a, int b, int c);
void				draw_mandlebrot(t_winfo *winfo);
void				draw_julia(t_winfo *winfo);
void				draw_circle(t_winfo *winfo);
void				draw_juliab(t_winfo *winfo);
void				draw_juliac(t_winfo *winfo);
void				draw_juliad(t_winfo *winfo);
void				draw_burningship(t_winfo *winfo);
void				get_zoom(t_winfo *winfo);
double				d_abs(double n);
double				power(double n);
t_option			*set_option(int nb);
void				render(t_winfo *winfo);
int					mouse_action(int x, int y, void *param);
int					mouse_button(int key, int x, int y, void *param);
void				reset(t_winfo *winfo);
t_help				get_help(int xc, int yc, int x, int y);
void				doit_forme(int *d, int *x, int *y, int r);
void				transform_circle(t_winfo *winfo);

#endif
