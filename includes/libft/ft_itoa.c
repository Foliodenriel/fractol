/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:07:55 by abara             #+#    #+#             */
/*   Updated: 2016/07/07 15:17:53 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(long long n)
{
	if (n < 0)
		return (ft_size(-n) + 1);
	if (n < 10)
		return (1);
	return (ft_size(n / 10) + 1);
}

static char		*ft_tabin(char *tab, long long n, long long power, int i)
{
	while (n >= 0 && power != 0)
	{
		tab[i] = (n / power) + 48;
		n %= power;
		power /= 10;
		i++;
	}
	return (tab);
}

char			*ft_itoa(long long n)
{
	char				*tab;
	unsigned long long	power;
	long long			i;
	long long			index;
	long long			k;

	k = (long long)n;
	index = ft_size(k);
	i = 0;
	power = 1;
	tab = malloc(sizeof(*tab) * index + 1);
	if (tab == NULL)
		return (NULL);
	if (k < 0)
	{
		tab[i] = '-';
		k = -k;
		i++;
	}
	while (power <= k)
		power *= 10;
	k > 0 ? power /= 10 : 0;
	tab = ft_tabin(tab, k, power, i);
	tab[index] = '\0';
	return (tab);
}
