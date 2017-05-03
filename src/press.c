/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 17:35:51 by abara             #+#    #+#             */
/*   Updated: 2016/09/13 14:20:22 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	clear(t_winfo *winfo)
{
	winfo->img = mlx_new_image(winfo->mlx, WIDTH, HEIGHT);
	winfo->data = mlx_get_data_addr(winfo->img, &winfo->bpp,
	&winfo->line, &winfo->endian);
}

void	key_action(t_winfo *winfo, int key)
{
	if (key == 126)
	{
		winfo->fractal.y1 -= 0.1 * (100 / winfo->fractal.zoomy);
		winfo->fractal.y2 -= 0.1 * (100 / winfo->fractal.zoomy);
		winfo->circle.yc += 10;
	}
	else if (key == 125)
	{
		winfo->fractal.y1 += 0.1 * (100 / winfo->fractal.zoomy);
		winfo->fractal.y2 += 0.1 * (100 / winfo->fractal.zoomy);
		winfo->circle.yc -= 10;
	}
	else if (key == 124)
	{
		winfo->fractal.x1 += 0.1 * (100 / winfo->fractal.zoomx);
		winfo->fractal.x2 += 0.1 * (100 / winfo->fractal.zoomx);
		winfo->circle.xc -= 10;
	}
	else if (key == 123)
	{
		winfo->fractal.x1 -= 0.1 * (100 / winfo->fractal.zoomx);
		winfo->fractal.x2 -= 0.1 * (100 / winfo->fractal.zoomx);
		winfo->circle.xc += 10;
	}
}

void	key_otheraction(t_winfo *winfo, int key)
{
	if (key == 13 && winfo->fractal.max > 10 && winfo->select != 2)
	{
		winfo->fractal.max -= 10;
		winfo->circle.max -= winfo->circle.max > 0 ? 1 : 0;
	}
	else if (key == 13 && winfo->circle.max > 0)
		winfo->circle.max -= 1;
	else if (key == 15)
		reset(winfo);
	else if (key == 18)
		winfo->select = 0;
	else if (key == 19)
		winfo->select = 1;
	else if (key == 20)
		winfo->select = 2;
	else if (key == 21)
		winfo->select = 3;
	else if (key == 23)
		winfo->select = 4;
	else if (key == 22)
		winfo->select = 5;
	else if (key == 26)
		winfo->select = 6;
	else if (key == 35)
		winfo->lock = winfo->lock > 0 ? 0 : 1;
}

void	key_special(t_winfo *winfo, int key)
{
	if (key == 69 && winfo->select == 2)
		transform_circle(winfo);
	else if (key == 69)
		get_zoom(winfo);
	else if (key == 78 && winfo->select == 2)
		winfo->circle.r -= (winfo->circle.r / 10) / 2;
	else if (key == 78 && (winfo->fractal.zoomx - 10 >= 150
	&& winfo->fractal.zoomy - 10 >= 150))
		winfo->fractal.add = winfo->fractal.add -
		(winfo->fractal.middle + winfo->fractal.add) / 10;
	else if (key == 12)
	{
		winfo->fractal.max += 10;
		winfo->circle.max += 1;
	}
}

int		key_press(int key, void *param)
{
	t_winfo *winfo;

	winfo = param;
	if (key == 53)
		exit(1);
	else if (key == 126 || key == 125 || key == 124 || key == 123)
		key_action(winfo, key);
	else if (key == 69 || key == 78 || key == 12)
		key_special(winfo, key);
	else if (key == 13 || key == 15 || key == 14 || key == 18 || key == 19
	|| key == 20 || key == 21 || key == 23 || key == 22 || key == 26
	|| key == 35)
		key_otheraction(winfo, key);
	else if (key == 8)
		winfo->color = winfo->color > 0 ? 0 : 1;
	winfo->fractal.zoomx = WIDTH / (winfo->fractal.x2 - winfo->fractal.x1)
	+ winfo->fractal.add;
	winfo->fractal.zoomy = HEIGHT / (winfo->fractal.y2 - winfo->fractal.y1)
	+ winfo->fractal.add;
	winfo->fractal.middle = (winfo->fractal.zoomx + winfo->fractal.zoomy) / 2;
	clear(winfo);
	render(winfo);
	return (0);
}
