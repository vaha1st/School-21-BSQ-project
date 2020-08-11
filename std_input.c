/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:30:05 by masharla          #+#    #+#             */
/*   Updated: 2020/08/11 21:53:18 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

int		std_input_read(char *file_name)
{
	int		fd;
	ssize_t	ret;
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd < 0)
	{
		ft_puterr("map error\n");
		return (-1);
	}
	while ((ret = read(0, &c, 1)) >= 0)
	{
		if (ret < 0)
		{
			ft_puterr("map error\n");
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
