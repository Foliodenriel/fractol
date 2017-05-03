/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winfo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 14:17:45 by abara             #+#    #+#             */
/*   Updated: 2016/09/12 14:47:09 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_winfo(t_winfo *winfo)
{
	winfo->mlx = mlx_init();
	winfo->win = mlx_new_window(winfo->mlx, WIDTH, HEIGHT, "fract'ol");
	winfo->img = mlx_new_image(winfo->mlx, WIDTH, HEIGHT);
	winfo->data = mlx_get_data_addr(winfo->img, &winfo->bpp, &winfo->line,
	&winfo->endian);
	winfo->lock = 0;
	winfo->color = 0;
}

void	set_fractal(t_winfo *winfo)
{
	winfo->fractal.x1 = -2.1;
	winfo->fractal.x2 = 0.6;
	winfo->fractal.y1 = -1.2;
	winfo->fractal.y2 = 1.2;
	winfo->fractal.max = 50;
	winfo->fractal.add = 0;
	winfo->fractal.zoomx = WIDTH / (winfo->fractal.x2 - winfo->fractal.x1);
	winfo->fractal.zoomy = HEIGHT / (winfo->fractal.y2 - winfo->fractal.y1);
	winfo->fractal.middle = (winfo->fractal.zoomx + winfo->fractal.zoomy) / 2;
	winfo->circle.color = set_color(255, 255, 255);
	winfo->circle.xc = WIDTH / 2;
	winfo->circle.yc = HEIGHT / 2;
	winfo->circle.max = 10;
	winfo->circle.r = 100;
}
