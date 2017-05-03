/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 16:54:56 by abara             #+#    #+#             */
/*   Updated: 2016/09/13 14:20:43 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_action(int x, int y, void *param)
{
	t_winfo *winfo;

	winfo = param;
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		winfo->x = x;
		winfo->y = y;
	}
	else
	{
		winfo->x = WIDTH / 2;
		winfo->y = HEIGHT / 2;
	}
	if (winfo->lock == 0)
	{
		winfo->a = winfo->x;
		winfo->b = winfo->y;
	}
	winfo->fractal.zoomx = WIDTH / (winfo->fractal.x2 - winfo->fractal.x1)
	+ winfo->fractal.add;
	winfo->fractal.zoomy = HEIGHT / (winfo->fractal.y2 - winfo->fractal.y1)
	+ winfo->fractal.add;
	clear(winfo);
	render(winfo);
	return (0);
}

int		mouse_button(int key, int x, int y, void *param)
{
	t_winfo	*winfo;

	x = y;
	winfo = param;
	if (key == 4)
	{
		transform_circle(winfo);
		get_zoom(winfo);
	}
	else if (key == 6 && (winfo->fractal.zoomx - 10 >= 150 &&
	winfo->fractal.zoomy - 10 >= 150))
	{
		winfo->circle.r -= (winfo->circle.r / 10) / 2;
		winfo->fractal.add = winfo->fractal.add - (winfo->fractal.middle
		+ winfo->fractal.add) / 10;
	}
	winfo->fractal.zoomx = WIDTH / (winfo->fractal.x2 - winfo->fractal.x1)
	+ winfo->fractal.add;
	winfo->fractal.zoomy = HEIGHT / (winfo->fractal.y2 - winfo->fractal.y1)
	+ winfo->fractal.add;
	winfo->fractal.middle = (winfo->fractal.zoomx + winfo->fractal.zoomy) / 2;
	clear(winfo);
	render(winfo);
	return (0);
}
