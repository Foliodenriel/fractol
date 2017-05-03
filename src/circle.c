/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 14:19:39 by abara             #+#    #+#             */
/*   Updated: 2016/09/12 14:44:59 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_help		get_help(int xc, int yc, int x, int y)
{
	t_help	help;

	help.xc = xc;
	help.yc = yc;
	help.x = x;
	help.y = y;
	return (help);
}

void		doit_forme(int *d, int *x, int *y, int r)
{
	if (*d >= 2 * (*x))
	{
		*d -= 2 * (*x) + 1;
		(*x)++;
	}
	else if (*d < 2 * (r - (*y)))
	{
		*d += 2 * (*y) - 1;
		(*y)--;
	}
	else
	{
		*d += 2 * (*y - *x - 1);
		(*y)--;
		(*x)++;
	}
}

static void	check_circle(t_winfo *winfo, int *r, int *xc, int *yc)
{
	if (*xc < WIDTH + (*r / 2))
		circle(winfo, *xc + *r + (*r / 2), *yc, *r / 2);
	if (*xc >= 0 - (*r / 2))
		circle(winfo, *xc - *r - (*r / 2), *yc, *r / 2);
	if (*yc < HEIGHT + (*r / 2))
		circle(winfo, *xc, *yc + *r + (*r / 2), *r / 2);
	if (*yc >= 0 - (*r / 2))
		circle(winfo, *xc, *yc - *r - (*r / 2), *r / 2);
	winfo->circle.color[1] -= 40;
	winfo->circle.color[0] -= 30;
	winfo->circle.color[2] += 20;
}

void		rec_circle(t_winfo *winfo, int r, int xc, int yc)
{
	int		tmp;

	tmp = winfo->circle.index;
	if (winfo->circle.index != winfo->circle.max && r > 0)
	{
		check_circle(winfo, &r, &xc, &yc);
		winfo->circle.index++;
		rec_circle(winfo, r / 2, xc + r + (r / 2), yc);
		winfo->circle.index = tmp + 1;
		rec_circle(winfo, r / 2, xc - r - (r / 2), yc);
		winfo->circle.index = tmp + 1;
		rec_circle(winfo, r / 2, xc, yc + r + (r / 2));
		winfo->circle.index = tmp + 1;
		rec_circle(winfo, r / 2, xc, yc - r - (r / 2));
		winfo->circle.index = tmp + 1;
	}
}

void		draw_circle(t_winfo *winfo)
{
	winfo->circle.index = 0;
	winfo->circle.color = set_color(255, 255, 255);
	circle(winfo, winfo->circle.xc, winfo->circle.yc, winfo->circle.r);
	rec_circle(winfo, winfo->circle.r, winfo->circle.xc, winfo->circle.yc);
}
