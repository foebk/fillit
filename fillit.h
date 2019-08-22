/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:02:33 by ction             #+#    #+#             */
/*   Updated: 2019/05/08 21:02:35 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

int					wtfmain(int fd, int *figures);
int					whatthefigure(char **buf);

typedef struct		s_listt
{
	int				id;
	int				coords[3];
	struct s_listt	*next;
}					t_coord;

t_coord				*figure_coords();
char				*findandreplace(char *src, char a, char b);
int					rec(char **fld, int *fg, t_coord *head, char a);
int					putfigure(char **fld, int fg, int bg, t_coord *head);
int					ending(int flag, t_coord *head, char *bufhead, int fd);

#endif
