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
	cordsystem	*head;

	if (argc != 2)
		return (0);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	ft_bzeroint(figures, 27);
	if ((((wtfmain(fd, figures)) == 0) || (argc != 2)))
	{
		ft_putendl("Error");
		return (0);
	}
	if ((head = figure_coords()) == 0)
		return (0);
	return (0);
}
