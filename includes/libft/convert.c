/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:23:50 by abara             #+#    #+#             */
/*   Updated: 2016/09/12 14:23:51 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*reverse_str(char *str)
{
	char	*dst;
	int		size;
	int		index;

	index = 0;
	size = ft_strlen(str);
	dst = ft_strnew(size);
	while (size != 0)
	{
		dst[index] = str[size - 1];
		index++;
		size--;
	}
	return (dst);
}

char	get_char_nb(unsigned long nb, int base, int maj)
{
	char	*str;
	int		index;

	index = 0;
	if (maj == 0)
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	while (index != nb && index < base)
		index++;
	return (str[index]);
}

char	*convert_to_base(unsigned long nb, int base, int maj)
{
	unsigned long		res;
	char				*number;
	int					i;

	i = 0;
	res = nb;
	number = ft_strnew(1000);
	while (nb > (base - 1))
	{
		nb /= base;
		number[i] = get_char_nb(res % base, base, maj);
		res = nb;
		i++;
	}
	number[i] = get_char_nb(nb, base, maj);
	number = reverse_str(number);
	return (number);
}
