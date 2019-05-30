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

static int	whatthefigure4(char **buf, int i, int flag)
{
	if (flag == 4)
	{
		if (((*buf)[i] == (*buf)[i + 5]) && ((*buf)[i] == (*buf)[i + 6]))
			return (3);
		if (((*buf)[i] == (*buf)[i + 5]) && ((*buf)[i] == (*buf)[i + 9]))
			return (13);
		if (((*buf)[i] == (*buf)[i + 5]) && ((*buf)[i] == (*buf)[i + 10]))
			return (2);
	}
	return (0);
}

static int	whatthefigure3(char **buf, int i, int flag)
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

static int	whatthefigure2(char **buf, int i, int flag)
{
	if (flag == 1)
	{
		if (i + 11 < 21 && ((*buf)[i] == (*buf)[i + 6]) &&
			((*buf)[i] == (*buf)[i + 11]))
			return (9);
		if (i + 10 < 21 && ((*buf)[i] == (*buf)[i + 5]) &&
		((*buf)[i] == (*buf)[i + 10]))
			return (5);
		if (i + 6 < 21 && ((*buf)[i] == (*buf)[i + 5]) &&
			((*buf)[i] == (*buf)[i + 6]))
			return (19);
		if (i + 7 < 21 && ((*buf)[i] == (*buf)[i + 6]) &&
			((*buf)[i] == (*buf)[i + 7]))
			return (14);
		if (i + 5 < 21 && ((*buf)[i] == (*buf)[i + 4]) &&
			((*buf)[i] == (*buf)[i + 5]))
			return (16);
	}
	if (flag == 4)
		return (whatthefigure4(buf, i, 4));
	return (0);
}

int			whatthefigure(char **buf)
{
	int i;

	i = 0;
	i = ft_strnchr(*buf, '#');
	if ((*buf)[i] == (*buf)[i + 1])
	{
		if (((*buf)[i] == (*buf)[i + 2]) && ((*buf)[i] == (*buf)[i + 3]))
			return (18);
		else if (((*buf)[i] == (*buf)[i + 2]) && ((*buf)[i] == (*buf)[i + 5]))
			return (12);
		else if (((*buf)[i] == (*buf)[i + 2]) && ((*buf)[i] == (*buf)[i + 6]))
			return (4);
		else if (((*buf)[i] == (*buf)[i + 2]) && ((*buf)[i] == (*buf)[i + 7]))
			return (6);
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
