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
	if (sh[i] == 1)
		bg += 1;
	else if (sh[i] == 2)
		bg += s - 1;
	else if (sh[i] == 3)
		bg += s;
	else if (sh[i] == 4)
		bg += s + 1;
	else
		return (0);
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

int putfigure(char **fld, int fg, int bg, char c) /* field - поле,fg - id фигуры, begin - начало, c - буква фигуры) | не забыть зафришить head */
{
	int i;
	int *sh;
	int s;
	static t_coord	*head = NULL;

	i = 0;
	s = ft_sqrt(ft_strcount(*fld, '.'), 0);
	if (head == NULL)
		head = figure_coords();
	if ((*fld)[bg] != '.')
		return (0);
	(*fld)[bg] = c;
	sh = findfigure(head, fg);
	while (i != 3)
	{
		bg = vector(sh, bg, i, s);
		if ((*fld)[bg] != '.')
			return (0);
		(*fld)[bg] = c;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	int			i;
	int			figures[27];
	char		*field;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	ft_bzeroint(figures, 27);
	if ((argc != 2) || (fd < 3) || ((wtfmain(fd, figures)) == 0))
		return (0);
	while (figures[++i] != 0);
	if ((field = makefield(ft_sqrt(4 * i, 1))) == 0)
		return (0);
	printf("%s\n", field);
	putfigure(&field, 1, 0, 'X');
	printf("%s\n", field);
	// free(field);
	return (0);
}
