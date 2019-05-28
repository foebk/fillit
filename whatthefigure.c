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

// int whatthefigure(char **buf)
// {
// 	printf("%d\n", ft_strnchr(*buf, ));
// }

int validation(int fd, char **buf, int ret)
{
	int i;

	i = 0;
	while (i != 21)
	{
		if (!((**buf == '.') || (**buf == '#')) && ((i + 1) % 5 != 0) && (i != 20))
			return (0);
		else if ((**buf == '\n') && (i == 19) && (ret == 20) && i++)
		{
			continue;
		}
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

int main()
{

    int		fd;
	int		ret;
	char	*buf;

	buf = malloc(sizeof(char) * 21);
	fd = open("valid_figures", O_RDONLY);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (validation(fd, &buf, ret) == 0)
			return (0);
		printf("%s", buf);
		// whatthefigure(&buf);
	}
	free(buf);
}
