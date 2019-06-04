/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 22:01:26 by ction             #+#    #+#             */
/*   Updated: 2019/05/29 22:01:27 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	symbol_checker(char **buf, int ret)
{
	int sharps;
	int dots;
	int nl;
	int i;

	i = 0;
	sharps = 0;
	nl = 0;
	dots = 0;
	while ((*buf)[i] != '\0')
	{
		if ((ret == 20) && (i == 20))
			break ;
		((*buf)[i] == '#') ? sharps++ : 0;
		((*buf)[i] == '.') ? dots++ : 0;
		((*buf)[i] == '\n') ? nl++ : 0;
		i++;
	}
	if ((sharps != 4) || (dots != 12))
		return (0);
	if ((ret == 21) && (nl != 5))
		return (0);
	else if ((ret == 20) && (nl != 4))
		return (0);
	return (1);
}

static int	validation(char **buf, int ret)
{
	int i;

	i = 0;
	if (symbol_checker(buf, ret) == 0)
		return (0);
	while (i != 21)
	{
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
	return (1);
}

int			wtfmain(int fd, int *figures)
{
	int		i;
	int		ret;
	char	*buf;
	char	*bufhead;

	i = 0;
	if ((buf = ft_memalloc(sizeof(char) * 22)) == 0)
		return (0);
	bufhead = buf;
	while (((ret = read(fd, buf, 21)) == 21))
	{
		if (validation(&buf, ret) == 0)
		{
			ft_strdel(&bufhead);
			return (0);
		}
		if (whatthefigure(&buf) == 0)
			return (0);
		figures[i++] = whatthefigure(&buf);
	}
	if (((validation(&buf, ret) == 0)) || ft_strlen(buf) == 0)
		return (0);
	figures[i] = whatthefigure(&buf);
	free(buf);
	return (ret != 20) ? 0 : 1;
}
