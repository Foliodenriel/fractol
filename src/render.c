/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 12:04:45 by abara             #+#    #+#             */
/*   Updated: 2016/09/12 14:46:50 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		render_option(t_winfo *winfo)
{
	t_option	*tmp;
	int			*color1;
	int			*color2;

	tmp = winfo->option;
	color1 = set_color(255, 153, 102);
	color2 = set_color(102, 204, 255);
	while (winfo->option)
	{
		if (winfo->option->select == 0)
		{
			fill_rect(winfo, winfo->option, color1);
		}
		else
		{
			fill_rect(winfo, winfo->option, color2);
		}
		winfo->option = winfo->option->next;
	}
	winfo->option = tmp;
}

static t_option	*set_select(t_option *option, int select)
{
	t_option	*tmp;
	int			i;

	i = 0;
	tmp = option;
	while (option)
	{
		option->select = 0;
		option = option->next;
	}
	option = tmp;
	while (i != select)
	{
		option = option->next;
		i++;
	}
	option->select = 1;
	return (tmp);
}

void			render(t_winfo *winfo)
{
	winfo->option = set_select(winfo->option, winfo->select);
	if (winfo->select == 0)
		draw_mandlebrot(winfo);
	else if (winfo->select == 1)
		draw_julia(winfo);
	else if (winfo->select == 2)
		draw_circle(winfo);
	else if (winfo->select == 3)
		draw_juliab(winfo);
	else if (winfo->select == 4)
		draw_juliac(winfo);
	else if (winfo->select == 5)
		draw_burningship(winfo);
	else if (winfo->select == 6)
		draw_juliad(winfo);
	render_option(winfo);
	mlx_put_image_to_window(winfo->mlx, winfo->win, winfo->img, 0, 0);
	mlx_string_put(winfo->mlx, winfo->win, 5, 5, 0xffffff,
	ft_itoa(winfo->fractal.max));
	if (winfo->lock == 0)
		mlx_string_put(winfo->mlx, winfo->win, 5, 25, 0xffffff, "moving");
	else
		mlx_string_put(winfo->mlx, winfo->win, 5, 25, 0xffffff, "pause");
}
