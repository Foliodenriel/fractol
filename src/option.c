/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 16:21:34 by abara             #+#    #+#             */
/*   Updated: 2016/09/12 14:46:32 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_option	*add_option(t_option *option, int *xy)
{
	t_option	*tmp;
	t_option	*elem;

	elem = malloc(sizeof(t_option));
	tmp = option;
	elem->next = NULL;
	elem->x1 = xy[0];
	elem->x2 = xy[1];
	elem->y1 = xy[2];
	elem->y2 = xy[3];
	elem->select = 0;
	if (option)
	{
		while (option->next)
			option = option->next;
		option->next = elem;
	}
	else
	{
		return (elem);
	}
	return (tmp);
}

static int		*set_xy(int x1, int x2, int y1, int y2)
{
	int		*xy;

	xy = (int*)malloc(sizeof(int) * 4);
	xy[0] = x1;
	xy[1] = x2;
	xy[2] = y1;
	xy[3] = y2;
	return (xy);
}

t_option		*set_option(int nb)
{
	t_option	*option;
	int			*xy;
	int			i;

	i = 0;
	option = NULL;
	xy = set_xy(5, 45, HEIGHT - 45, HEIGHT - 5);
	while (i < nb)
	{
		option = add_option(option, xy);
		xy[0] = xy[0] + 45;
		xy[1] = xy[1] + 45;
		i++;
	}
	option->select = 1;
	return (option);
}
