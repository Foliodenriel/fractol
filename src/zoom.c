/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:27:02 by abara             #+#    #+#             */
/*   Updated: 2016/09/13 14:19:39 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	transform_circle(t_winfo *winfo)
{
	double	x;
	double	y;

	x = (winfo->x - (WIDTH / 2));
	winfo->circle.xc -= x;
	y = (winfo->y - (HEIGHT / 2));
	winfo->circle.yc -= y;
	winfo->circle.r += (winfo->circle.r / 10) / 2;
}

void	set_xy(t_winfo *winfo, int *x, int *y)
{
	*x = (WIDTH / 2);
	*y = (HEIGHT / 2);
	if (*x < winfo->x)
		*x = winfo->x - *x;
	else
		*x = *x - winfo->x;
	if (*y < winfo->y)
		*y = winfo->y - *y;
	else
		*y = *y - winfo->y;
}

double	get_zoom_helpa(t_winfo *winfo, double b, int x)
{
	double	a;

	a = (WIDTH / 2);
	a = x / a;
	a = a * b;
	a = a / (winfo->fractal.zoomx / 100);
	if (winfo->x >= (WIDTH / 2))
	{
		winfo->fractal.x1 += a;
		winfo->fractal.x2 += a;
	}
	else
	{
		winfo->fractal.x1 -= a;
		winfo->fractal.x2 -= a;
	}
	return (a);
}

double	get_zoom_helpb(t_winfo *winfo, double b, int y)
{
	double	a;

	a = (HEIGHT / 2);
	a = y / a;
	a = a * b;
	a = a / (winfo->fractal.zoomy / 100);
	if (winfo->y < (HEIGHT / 2))
	{
		winfo->fractal.y1 -= a;
		winfo->fractal.y2 -= a;
	}
	else
	{
		winfo->fractal.y1 += a;
		winfo->fractal.y2 += a;
	}
	return (a);
}

void	get_zoom(t_winfo *winfo)
{
	double	a;
	double	b;
	int		x;
	int		y;

	winfo->fractal.add = winfo->fractal.add +
	(winfo->fractal.middle + winfo->fractal.add) / 10;
	set_xy(winfo, &x, &y);
	b = winfo->fractal.x1 - winfo->fractal.x2;
	if (b < 0)
		b = -b;
	b /= 2;
	a = get_zoom_helpa(winfo, b, x);
	b = winfo->fractal.y1 - winfo->fractal.y2;
	if (b < 0)
		b = -b;
	b /= 2;
	a = get_zoom_helpb(winfo, b, y);
}
