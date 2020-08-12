/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_service.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 11:35:48 by masharla          #+#    #+#             */
/*   Updated: 2020/08/12 13:01:13 by etorren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

/*
**
*/

int		open_err(void)
{
	ft_puterr("map error: can not open file.\n");
	return (-1);
}

int		bad_align_err(void)
{
	ft_puterr("map error: bad aligned.\n");
	return (-1);
}

int		read_err(int fd)
{
	if (fd >= 0)
		close(fd);
	ft_puterr("map error: cannot read map.\n");
	return (-1);
}
