/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 16:45:14 by abara             #+#    #+#             */
/*   Updated: 2016/09/12 14:49:07 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	draw_burningship_helpa(t_winfo *winfo, int x, int y)
{
	winfo->fractal.cr = x / winfo->fractal.zoomx + winfo->fractal.x1;
	winfo->fractal.ci = y / winfo->fractal.zoomy + winfo->fractal.y1;
	winfo->fractal.zr = 0;
	winfo->fractal.zi = 0;
}

static void	draw_burningship_helpb(t_winfo *winfo)
{
	double	tmp;

	tmp = winfo->fractal.zr;
	winfo->fractal.zr = d_abs((winfo->fractal.zr *
	winfo->fractal.zr - winfo->fractal.zi *
	winfo->fractal.zi + winfo->fractal.cr));
	winfo->fractal.zi = d_abs(2 * tmp * winfo->fractal.zi +
	winfo->fractal.ci);
}

void		color_burningship(t_winfo *winfo, int i, int x, int y)
{
	if (i != winfo->fractal.max && winfo->color == 0)
		put_pixel(winfo, x, y, set_color(0, i * (255 -
		winfo->fractal.max) / winfo->fractal.max, i * 255
		/ winfo->fractal.max));
	else if (i != winfo->fractal.max && winfo->color == 1)
		put_pixel(winfo, x, y, set_color(0, i * (255 -
		winfo->fractal.max) / winfo->fractal.max, (1500
		/ winfo->fractal.max) * i));
}

void		draw_burningship(t_winfo *winfo)
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
			draw_burningship_helpa(winfo, x, y);
			i = 0;
			while ((winfo->fractal.zr * winfo->fractal.zr + winfo->fractal.zi
			* winfo->fractal.zi) < 4 && i < winfo->fractal.max)
			{
				draw_burningship_helpb(winfo);
				i++;
			}
			color_burningship(winfo, i, x, y);
			x++;
		}
		y++;
	}
}
