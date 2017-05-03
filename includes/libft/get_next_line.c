/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:27:07 by abara             #+#    #+#             */
/*   Updated: 2016/02/22 15:30:41 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		line_size(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0' && str[index] != '\n')
	{
		index++;
	}
	return (index);
}

char	*get_file(int const fd, int *check, char **str)
{
	char	*buf;
	int		index;

	index = 0;
	buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (!str[fd])
	{
		str[fd] = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		ft_bzero(str[fd], BUFF_SIZE + 1);
	}
	while ((*check = read(fd, buf, BUFF_SIZE)) > 0)
	{
		str[fd] = ft_strjoin(str[fd], buf);
		ft_bzero(buf, BUFF_SIZE + 1);
		while (str[fd][index] != '\0')
		{
			if (str[fd][index] == '\n')
				return (str[fd]);
			index++;
		}
	}
	return (str[fd]);
}

char	*get_dst(int const fd, int *i, char **str)
{
	char	*dst;
	int		test;

	test = 0;
	dst = (char *)malloc(sizeof(char) * line_size(str[fd]) + 1);
	while (str[fd][*i] != '\0' && str[fd][*i] != '\n')
		(*i)++;
	dst = ft_strsub(str[fd], 0, *i);
	if (*i == 0 && str[fd][0] == '\n')
		test = 1;
	if (str[fd][*i] != '\0')
		ft_strcpy(str[fd], &str[fd][*i + 1]);
	else
		ft_bzero(str[fd], *i);
	if (test == 0 && *i == 0)
		*i = 0;
	else if (test == 1)
		(*i)++;
	return (dst);
}

int		get_next_line(int const fd, char **line)
{
	static char		*str[100];
	int				check;
	int				i;
	char			*dst;

	check = 0;
	i = 0;
	if (fd < 0 || !line)
		return (-1);
	str[fd] = get_file(fd, &check, &str[fd]);
	if (check == -1)
		return (-1);
	dst = get_dst(fd, &i, &str[fd]);
	if (i > 0)
	{
		*line = dst;
		return (1);
	}
	return (0);
}
