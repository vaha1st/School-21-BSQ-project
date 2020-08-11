/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:36:29 by masharla          #+#    #+#             */
/*   Updated: 2020/08/11 17:10:03 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** ft_putstr(*) puts a string on standart output.
**
** ft_strlen(*) counts length of a string.
**
** convert(*) converts given char 'c' with handy 'obcstacle' or 'empty'\
** character if it mathes or doing nothing if it's not. Returns 'c'.
**
** min(*) finds a less character by ascii of three given.
*/

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*str++)
	{
		count++;
	}
	return (count);
}

char	convert(char c, char empty, char obst)
{
	if (c == empty)
		return ('1');
	else if (c == obst)
		return ('0');
	else
		return (c);
}

char	min(char m1, char m2, char m3)
{
	char tmp;

	tmp = m1;
	(tmp > m2 ? tmp = m2 : 1);
	(tmp > m3 ? tmp = m3 : 1);
	return (tmp);
}
