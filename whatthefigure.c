/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatthefigure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:49:54 by ction             #+#    #+#             */
/*   Updated: 2019/05/27 17:49:57 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

int	whatthefigure3(char **buf, int i, int flag)
{
	if (flag == 5)
	{
		if (((*buf)[i] == (*buf)[i + 6]) && ((*buf)[i] == (*buf)[i + 7]))
			return (8);
		if (((*buf)[i] == (*buf)[i + 6]) && ((*buf)[i] == (*buf)[i + 10]))
			return (1);
		if (((*buf)[i] == (*buf)[i + 6]) && ((*buf)[i] == (*buf)[i + 11]))
			return (15);
		if (((*buf)[i] == (*buf)[i + 9]) && ((*buf)[i] == (*buf)[i + 10]))
			return (7);
		if (((*buf)[i] == (*buf)[i + 10]) && ((*buf)[i] == (*buf)[i + 11]))
			return (11);
		if (((*buf)[i] == (*buf)[i + 10]) && ((*buf)[i] == (*buf)[i + 15]))
			return (17);
	}
	if (flag == 3)
		if (((*buf)[i] == (*buf)[i + 4]) && ((*buf)[i] == (*buf)[i + 5]))
			return (10);
	return (0);
}

int	whatthefigure2(char **buf, int i, int flag)
{
	if (flag == 1)
	{
		if (((*buf)[i] == (*buf)[i + 5]) && ((*buf)[i] == (*buf)[i + 10]))
			return (5);
		if (((*buf)[i] == (*buf)[i + 5]) && ((*buf)[i] == (*buf)[i + 6]))
			return (19);
		if (((*buf)[i] == (*buf)[i + 6]) && ((*buf)[i] == (*buf)[i + 11]))
			return (9);
		if (((*buf)[i] == (*buf)[i + 6]) && ((*buf)[i] == (*buf)[i + 7]))
			return (14);
		if (((*buf)[i] == (*buf)[i + 4]) && ((*buf)[i] == (*buf)[i + 5]))
			return (16);
	}
	if (flag == 4)
	{
		if (((*buf)[i] == (*buf)[i + 5]) && ((*buf)[i] == (*buf)[i + 6]))
			return (3);
		if (((*buf)[i] == (*buf)[i + 5]) && ((*buf)[i] == (*buf)[i + 10]))
			return (2);
		if (((*buf)[i] == (*buf)[i + 5]) && ((*buf)[i] == (*buf)[i + 9]))
			return (13);
	}
	return (0);
}

int whatthefigure(char **buf)
{
	int i;

	i = 0;
	i = ft_strnchr(*buf, '#');
	if ((*buf)[i] == (*buf)[i + 1])
	{
		if (((*buf)[i] == (*buf)[i + 2]) && ((*buf)[i] == (*buf)[i + 6]))
			return (4);
		if (((*buf)[i] == (*buf)[i + 2]) && ((*buf)[i] == (*buf)[i + 7]))
			return (6);
		if (((*buf)[i] == (*buf)[i + 2]) && ((*buf)[i] == (*buf)[i + 5]))
			return (12);
		if (((*buf)[i] == (*buf)[i + 2]) && ((*buf)[i] == (*buf)[i + 3]))
			return (18);
		return (whatthefigure2(buf, i, 1));
	}
	if ((*buf)[i] == (*buf)[i + 3])
		return (whatthefigure3(buf, i, 3));
	else if ((*buf)[i] == (*buf)[i + 4])
		return (whatthefigure2(buf, i, 4));
	else if ((*buf)[i] == (*buf)[i + 5])
		return (whatthefigure3(buf, i, 5));
	return (0);
}

int validation(int fd, char **buf, int ret)
{
	int i;
	int sharps;

	i = 0;
	sharps = 0;
	while (i != 21)
	{
		if (**buf == '#')
			sharps++;
		if (!((**buf == '.') || (**buf == '#')) && ((i + 1) % 5 != 0)
			&& (i != 20))
			return (0);
		else if ((**buf == '\n') && (i == 19) && (ret == 20) && i++)
			continue;
		else if ((**buf != '\n') && (((i + 1) % 5 == 0) || i == 20) && (i != 0))
			return (0);
		*buf = *buf + 1;
		i++;
	}
	if (ret == 21)
		*buf = *buf - 21;
	else if (ret == 20)
		*buf = *buf - 20;
	return ((sharps == 4) ? 1 : 0);
}

int main()
{

	int		fd;
	int		ret;
	char	*buf;
	char	*bufhead;

	buf = ft_memalloc(sizeof(char) * 22);
	bufhead = buf;
	fd = open("valid_figures", O_RDONLY);
	while ((ret = read(fd, buf, 21)) > 19)
	{
		if (validation(fd, &buf, ret) == 0)
		{
			ft_strdel(&bufhead);
			return (0);
		}
		if (whatthefigure(&buf) != 0)
			printf("%d --- check\n", whatthefigure(&buf));
	}
	free(buf);
	if (ret < 20)
			return (0);
}
