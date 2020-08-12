/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:30:05 by masharla          #+#    #+#             */
/*   Updated: 2020/08/12 13:01:50 by etorren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

/*
** std_input_read(*) reads from standard input line by line and
** stops when ^D is occure. Result writes to the file with
** file name given as parameter.
*/

int		std_input_read(char *file_name)
{
	int		fd;
	ssize_t	ret;
	char	c;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd < 0)
		return (-1);
	while ((ret = read(0, &c, 1)) >= 0)
	{
		if (ret < 0)
		{
			if (fd >= 0)
				close(fd);
			return (-1);
		}
		if (ret == 0)
		{
			write(fd, "\n", 1);
			break ;
		}
		write(fd, &c, 1);
	}
	if (fd >= 0)
		close(fd);
	return (0);
}
