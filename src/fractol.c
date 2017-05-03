/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 17:09:15 by abara             #+#    #+#             */
/*   Updated: 2016/09/12 14:48:30 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	show_error(void)
{
	ft_putendl("usage : ./fractol mandlebrot");
	ft_putendl("        ./fractol julia");
	ft_putendl("        ./fractol circle");
	ft_putendl("        ./fractol juliab");
	ft_putendl("        ./fractol juliac");
	ft_putendl("        ./fractol burningship");
	ft_putendl("        ./fractol juliad");
	exit(1);
}

int		get_select(char *name)
{
	if (ft_strcmp("mandlebrot", name) == 0)
		return (0);
	else if (ft_strcmp("julia", name) == 0)
		return (1);
	else if (ft_strcmp("circle", name) == 0)
		return (2);
	else if (ft_strcmp("juliab", name) == 0)
		return (3);
	else if (ft_strcmp("juliac", name) == 0)
		return (4);
	else if (ft_strcmp("burningship", name) == 0)
		return (5);
	else if (ft_strcmp("juliad", name) == 0)
		return (6);
	else
		return (-1);
}

void	show_keys(void)
{
	ft_putendl("1: Switch to Mandlebrot");
	ft_putendl("2: Switch to julia");
	ft_putendl("3: Switch to circle");
	ft_putendl("4: Switch to juliab");
	ft_putendl("5: Switch to juliac");
	ft_putendl("6: Switch to burningship");
	ft_putendl("7: Switch to juliad");
	ft_putendl("------------------------");
	ft_putendl("MOUSE SCROLL: Zoom/unzoom");
	ft_putendl("NUMPAD +: Zoom");
	ft_putendl("NUMPAD -: Unzoom");
	ft_putendl("KEY P: Pause/Play");
	ft_putendl("KEY Q: Add iteration");
	ft_putendl("KEY W: Substract iteration");
	ft_putendl("KEY C: Enable/Disable weird colors");
}

int		main(int argc, char **argv)
{
	t_winfo	winfo;

	if (argc <= 1 || argc > 2 || (winfo.select = get_select(argv[1])) == -1)
	{
		show_error();
	}
	show_keys();
	set_winfo(&winfo);
	set_fractal(&winfo);
	winfo.option = set_option(7);
	render(&winfo);
	mlx_hook(winfo.win, 6, 1, mouse_action, &winfo);
	mlx_mouse_hook(winfo.win, mouse_button, &winfo);
	mlx_hook(winfo.win, 2, 1, key_press, &winfo);
	mlx_loop(winfo.mlx);
	return (0);
}
