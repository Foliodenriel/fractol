/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 12:11:58 by abara             #+#    #+#             */
/*   Updated: 2016/09/13 14:10:44 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	d_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	power(double n)
{
	return (n * n);
}

void	reset(t_winfo *winfo)
{
	winfo->fractal.x1 = -2.1;
	winfo->fractal.x2 = 0.6;
	winfo->fractal.y1 = -1.2;
	winfo->fractal.y2 = 1.2;
	winfo->fractal.max = 50;
	winfo->fractal.add = 0;
	winfo->circle.r = 100;
	winfo->circle.xc = WIDTH / 2;
	winfo->circle.yc = HEIGHT / 2;
}
