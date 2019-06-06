/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alexey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:28:12 by ction             #+#    #+#             */
/*   Updated: 2019/06/06 15:28:13 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	*findandreplace(char *src, char a, char b)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
	{
		if (src[i] == a)
			src[i] = b;
		i++;
	}
	return (src);
}

int		rec(char **fld, int *fg, t_coord *head, char a)
{
	int	res;
	int	bg;

	bg = 0;
	res = 0;
	if (*fg == 0)
		return (1);
	while (res != 1)
	{
		if ((unsigned int)bg >= ft_strlen(*fld) - ft_strcount(*fld, '\n'))
			return (0);
		res = putfigure(fld, *fg, bg, head);
		*fld = findandreplace(*fld, '#', a);
		bg++;
	}
	a++;
	if ((rec(fld, (fg + 1), head, a)) == 0)
		return (0);
	return (1);
}

int		ending(int flag, t_coord *head, char *bufhead)
{
	t_coord *tmp;
	t_coord *tmp2;

	if (head != NULL)
	{
		tmp = head;
		while (tmp->id != 19)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}
		free(tmp);
	}
	if (bufhead != NULL)
		ft_strdel(&bufhead);
	if (flag == 0)
		ft_putendl("Error");
	return (0);
}
