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

int		*ffig(t_coord *head, int figure)
{
	t_coord *tmp;

	tmp = head;
	while ((tmp->id != figure) && (tmp != NULL))
		tmp = tmp->next;
	if (tmp == NULL)
		return (0);
	return (tmp->coords);
}

char	*makefield(int s)
{
	int		i;
	char	*dest;

	i = -1;
	dest = ft_memalloc(sizeof(char *) * (s * s + s + 1));
	while (++i != s * s + s)
	{
		dest[i] = '.';
		if (((i + 1) % (s + 1) == 0) && (i != 0))
			dest[i] = '\n';
	}
	return (dest);
}

int putfigure(char **field, int fg, t_coord *head, int begin, char c)
{
	int i;

	if ((*field)[begin] != '.')
		return (0);
	while (i != 3)
		if ((*field)[begin + ffig(figurecoords(), fg)[i]] != '.')
			return (0);
		(*field)[begin + ffig(figurecoords(), fg)[0]] = c;
	begin += ffig(figurecoords(), fg)[0];

}

int	main(int argc, char **argv)
{
	int			fd;
	int			i;
	int			figures[27];
	t_coord		*head;
	char		*field;

	if (argc != 2)
		return (0);
	printf("%d\n", (findfigure(figure_coords(), 1))[0]);
	// fd = open(argv[1], O_RDONLY);
	// ft_bzeroint(figures, 27);
	// if ((wtfmain(fd, figures)) == 0)
	// 	return (0);
	// while (figures[++i] != 0);
	// field = makefield(ft_sqrt(4 * i, 1));
	// if ((head = figure_coords()) == 0)
	// 	return (0);
	return (0);
}
