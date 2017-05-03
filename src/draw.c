/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 14:38:43 by abara             #+#    #+#             */
/*   Updated: 2016/09/12 14:45:08 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		*set_color(int a, int b, int c)
{
	int		*color;

	color = (int*)malloc(sizeof(int) * 4);
	color[0] = a;
	color[1] = b;
	color[2] = c;
	color[3] = 0;
	return (color);
}

void	put_pixel(t_winfo *winfo, int x, int y, int *color)
{
	int		pixel;

	pixel = (y * winfo->line) + (x * (winfo->line / WIDTH));
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		if (winfo->data[pixel] != color[0])
			winfo->data[pixel] = color[0];
		if (winfo->data[pixel + 1] != color[1])
			winfo->data[pixel + 1] = color[1];
		if (winfo->data[pixel + 2] != color[2])
			winfo->data[pixel + 2] = color[2];
		if (winfo->data[pixel + 3] != color[3])
			winfo->data[pixel + 3] = color[3];
	}
}

void	fill_rect(t_winfo *winfo, t_option *opt, int *color)
{
	int		x;
	int		y;

	y = opt->y1;
	while (y <= opt->y2)
	{
		x = opt->x1;
		while (x <= opt->x2)
		{
			put_pixel(winfo, x, y, color);
			x++;
		}
		y++;
	}
}

void	circle_help(t_winfo *winfo)
{
	put_pixel(winfo, winfo->circle.help.xc + winfo->circle.help.x,
	winfo->circle.help.yc + winfo->circle.help.y, winfo->circle.color);
	put_pixel(winfo, winfo->circle.help.xc + winfo->circle.help.y,
	winfo->circle.help.yc + winfo->circle.help.x, winfo->circle.color);
	put_pixel(winfo, winfo->circle.help.xc - winfo->circle.help.x,
	winfo->circle.help.yc + winfo->circle.help.y, winfo->circle.color);
	put_pixel(winfo, winfo->circle.help.xc - winfo->circle.help.y,
	winfo->circle.help.yc + winfo->circle.help.x, winfo->circle.color);
	put_pixel(winfo, winfo->circle.help.xc + winfo->circle.help.x,
	winfo->circle.help.yc - winfo->circle.help.y, winfo->circle.color);
	put_pixel(winfo, winfo->circle.help.xc + winfo->circle.help.y,
	winfo->circle.help.yc - winfo->circle.help.x, winfo->circle.color);
	put_pixel(winfo, winfo->circle.help.xc - winfo->circle.help.x,
	winfo->circle.help.yc - winfo->circle.help.y, winfo->circle.color);
	put_pixel(winfo, winfo->circle.help.xc - winfo->circle.help.y,
	winfo->circle.help.yc - winfo->circle.help.x, winfo->circle.color);
}

void	circle(t_winfo *winfo, int xc, int yc, int r)
{
	int		x;
	int		y;
	int		d;

	x = 0;
	y = r;
	d = r - 1;
	while (y >= x)
	{
		winfo->circle.help = get_help(xc, yc, x, y);
		circle_help(winfo);
		doit_forme(&d, &x, &y, r);
	}
}
