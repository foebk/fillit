/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pajitnov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:13:57 by ction             #+#    #+#             */
/*   Updated: 2019/06/03 15:13:58 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static t_coord	*pushcords(int id_num, int a, int b, int c)
{
	t_coord *tmp;

	if (!(tmp = (t_coord *)malloc(sizeof(t_coord))))
		return (0);
	tmp->id = id_num;
	tmp->coords[0] = a;
	tmp->coords[1] = b;
	tmp->coords[2] = c;
	return (tmp);
}

static t_coord	*figure_coords2(void)
{
	t_coord	*head;
	t_coord	*tmp;

	head = pushcords(11, 4, 8, 9);
	tmp = pushcords(12, 1, 2, 4);
	head->next = tmp;
	tmp = pushcords(13, 3, 4, 7);
	head->next->next = tmp;
	tmp = pushcords(14, 1, 5, 6);
	head->next->next->next = tmp;
	tmp = pushcords(15, 4, 5, 9);
	head->next->next->next->next = tmp;
	tmp = pushcords(16, 1, 3, 4);
	head->next->next->next->next->next = tmp;
	tmp = pushcords(17, 4, 8, 12);
	head->next->next->next->next->next->next = tmp;
	tmp = pushcords(18, 1, 2, 3);
	head->next->next->next->next->next->next->next = tmp;
	tmp = pushcords(19, 1, 4, 5);
	head->next->next->next->next->next->next->next->next = tmp;
	return (head);
}

t_coord			*figure_coords(void)
{
	t_coord	*head;
	t_coord	*tmp;

	head = pushcords(1, 4, 5, 8);
	tmp = pushcords(2, 3, 4, 8);
	head->next = tmp;
	tmp = pushcords(3, 3, 4, 5);
	head->next->next = tmp;
	tmp = pushcords(4, 1, 2, 5);
	head->next->next->next = tmp;
	tmp = pushcords(5, 1, 4, 8);
	head->next->next->next->next = tmp;
	tmp = pushcords(6, 1, 2, 6);
	head->next->next->next->next->next = tmp;
	tmp = pushcords(7, 4, 7, 8);
	head->next->next->next->next->next->next = tmp;
	tmp = pushcords(8, 4, 5, 6);
	head->next->next->next->next->next->next->next = tmp;
	tmp = pushcords(9, 1, 5, 9);
	head->next->next->next->next->next->next->next->next = tmp;
	tmp = pushcords(10, 2, 3, 4);
	head->next->next->next->next->next->next->next->next->next = tmp;
	tmp = head->next->next->next->next->next->next->next->next->next;
	tmp->next = figure_coords2();
	return (head);
}
