/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:30:05 by masharla          #+#    #+#             */
/*   Updated: 2020/08/12 21:45:40 by etorren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

/*
** std_input_read(*) reads from standard input line by line and\
** stops when ^D is occure. Result writes to the file with\
** file name given as parameter.
**
** print_map_wo_header(*) just prints map row by row without first line.
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
			break ;
		write(fd, &c, 1);
	}
	close(fd);
	return (0);
}

void	print_map_wo_header(char **map, long int rows)
{
	int i;

	i = 1;
	while (i < rows)
	{
		ft_putstr(map[i++]);
		ft_putstr("\n");
	}
}
