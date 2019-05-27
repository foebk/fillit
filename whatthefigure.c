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

int validation(int fd)
{
	int ret;
	char buf[21];
	int i;

	i = 0;
	ret = read(fd, buf, 20);
	buf[20] = '\0';
	while (i != 20)
	{
		if (!((buf[i] == '.') || (buf[i] == '#')) && ((i + 1) % 5 != 0))
			return (0);
		if ((buf[i] != '\n') && ((i + 1) % 5 == 0) && (i != 0))
			return (0);
		i++;
	}
	return (1);
}

int main()
{
    int fd;

    fd = open("valid_figures", O_RDONLY);
	validation(fd);
}
