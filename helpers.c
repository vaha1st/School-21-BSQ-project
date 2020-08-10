/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:36:29 by masharla          #+#    #+#             */
/*   Updated: 2020/08/10 18:59:13 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
