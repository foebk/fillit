/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:45:40 by ction             #+#    #+#             */
/*   Updated: 2019/06/05 17:46:49 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcount(char *src, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
	{
		if (src[i] == c)
			count++;
		i++;
	}
	return (count);
}
