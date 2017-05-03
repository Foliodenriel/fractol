/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:20:37 by abara             #+#    #+#             */
/*   Updated: 2016/09/12 14:50:20 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	draw_mandlebrot_helpa(t_winfo *winfo, int x, int y)
{
	double	a;

	winfo->fractal.cr = x / winfo->fractal.zoomx + winfo->fractal.x1;
	winfo->fractal.ci = y / winfo->fractal.zoomy + winfo->fractal.y1;
	winfo->fractal.zr = (WIDTH / 2);
	winfo->fractal.zr = winfo->a / winfo->fractal.zr;
	a = d_abs(winfo->fractal.x1 - winfo->fractal.x2) / 2;
	winfo->fractal.zr *= a;
	winfo->fractal.zi = (HEIGHT / 2);
	winfo->fractal.zi = winfo->b / winfo->fractal.zi;
	a = d_abs(winfo->fractal.y1 - winfo->fractal.y2) / 2;
	winfo->fractal.zi *= a;
}

static void	draw_mandlebrot_helpb(t_winfo *winfo)
{
	double	tmp;

	tmp = winfo->fractal.zr;
	winfo->fractal.zr = (winfo->fractal.zr * winfo->fractal.zr -
	winfo->fractal.zi * winfo->fractal.zi + winfo->fractal.cr);
	winfo->fractal.zi = 2 * tmp *
	winfo->fractal.zi + winfo->fractal.ci;
}

void		color_mandlebrot(t_winfo *winfo, int i, int x, int y)
{
	if (i != winfo->fractal.max && winfo->color == 0)
		put_pixel(winfo, x, y, set_color(i * 255 /
		winfo->fractal.max, 0, 0));
	else if (i != winfo->fractal.max && winfo->color == 1)
		put_pixel(winfo, x, y, set_color((1500 / winfo->fractal.max)
		* i, (1500 / winfo->fractal.max) * i, (1500 / winfo->fractal.max) * i));
}

void		draw_mandlebrot(t_winfo *winfo)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_mandlebrot_helpa(winfo, x, y);
			i = 0;
			while ((winfo->fractal.zr * winfo->fractal.zr + winfo->fractal.zi
			* winfo->fractal.zi) < 4 && i < winfo->fractal.max)
			{
				draw_mandlebrot_helpb(winfo);
				i++;
			}
			color_mandlebrot(winfo, i, x, y);
			x++;
		}
		y++;
	}
}
