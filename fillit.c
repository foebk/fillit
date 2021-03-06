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

int		vector(int *sh, int bg, int i, int s)
{
	if (i == -1)
		return (bg);
	if (sh[i] == 1)
		bg += 1;
	else if (sh[i] == 2)
		bg += s - 1;
	else if (sh[i] == 3)
		bg += s;
	else if (sh[i] == 4)
		bg += s + 1;
	return (bg);
}

int		*findfigure(t_coord *head, int figure)
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
	if ((dest = ft_memalloc(sizeof(char *) * (s * s + s + 1))) == 0)
		return (0);
	while (++i != s * s + s)
	{
		dest[i] = '.';
		if (((i + 1) % (s + 1) == 0) && (i != 0))
			dest[i] = '\n';
	}
	return (dest);
}

int		putfigure(char **fld, int fg, int bg, t_coord *head)
{
	int			i;
	int			*sh;
	char		fldcopy[ft_strlen(*fld)];
	int			s;

	ft_strcpy(fldcopy, *fld);
	i = -2;
	s = ft_sqrt(ft_strlen(*fld) - ft_strcount(*fld, '\n'), 0);
	sh = findfigure(head, fg);
	while (++i != 3)
	{
		bg = vector(sh, bg, i, s);
		if ((*fld)[bg] != '.')
		{
			*fld = ft_strcpy(*fld, fldcopy);
			return (0);
		}
		(*fld)[bg] = '#';
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int			fd;
	int			i;
	int			figures[27];
	char		*field;
	t_coord		*head;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	ft_bzeroint(figures, 27);
	if ((argc != 2) || (fd < 0) || ((wtfmain(fd, figures)) == 0))
		return (ending(0, NULL, NULL, fd));
	while (figures[i] != 0)
		i++;
	if (((i == 0 || i > 26 || (field = makefield(ft_sqrt(4 * i, 1))) == 0)))
		return (ending(0, NULL, NULL, fd));
	head = figure_coords();
	while ((rec(&field, figures, head, 'A')) == 0)
	{
		free(field);
		field = makefield(ft_sqrt(4 * i++, 1));
	}
	ft_putstr(field);
	free(field);
	return (ending(1, head, NULL, fd));
}
