/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alexey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:30:45 by ction             #+#    #+#             */
/*   Updated: 2019/05/29 19:30:46 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			i;
	int			figures[27];
	t_coord		*head;

	if (argc != 2)
		return (0);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	ft_bzeroint(figures, 27);
	if ((wtfmain(fd, figures)) == 0)
		return (0);
	while (figures[++i] != 0);
	printf("%d\n", ft_sqrt(i * 4, 1));
	if ((head = figure_coords()) == 0)
		return (0);
	return (0);
}
