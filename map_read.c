/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:15:50 by etorren           #+#    #+#             */
/*   Updated: 2020/08/11 17:53:20 by etorren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	ft_putstr2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int		rows_size(char **av, char c)
{
	int			fd;
	long int	rows;
	ssize_t		ret;

	rows = 0;
	fd = open(av[1], O_RDONLY);
	while ((ret = read(fd, &c, 1)) > 0)
	{
		write(1, &c, 1);
		if (c == '\n')
			rows++;
	}
	if (ret < 0)
	{
		ft_putstr2("Cannot read file.\n");
		return (-1);
	}
	close(fd);
	printf("rows counts = %ld\n", rows);
	return (rows);
}

int		cols_len(char **av, int rows, char c)
{
	int			fd;
	long int	cols;
	ssize_t		ret;
	long int	i;
	int			check;

	i = 0;
	cols = 0;
	fd = open(av[1], O_RDONLY);
	while (i < rows - 1)
	{
		check = cols;
		cols = 0;
		while ((ret = read(fd, &c, 1)) > 0 && c != '\n')
			cols++;
		i++;
		printf("cols counts = %ld :  i = %ld  : check counts = %d\n", cols, i, check);
		if (check != cols && i > 2)
		{
			ft_putstr2("## Map error: bad aligned ##\n");
			return (-1);
		}
	}
	close(fd);
	return (cols);
}

char	**map_create(char **av, int row, int cols, char c)
{
	int		i;
	int		j;
	int		fd;
	ssize_t	ret;
	char	**map;

	(void) cols;
	i = 0;
	map = (char **)malloc(sizeof(map) * (row + 1));
	while (i < row + 1)
	{
		map[i] = (char *)malloc(sizeof(char) * (cols + 1));
		i++;
	}
	i = 0;
	fd = open(av[1], O_RDONLY);
	while (i < row + 1)
	{
		j = 0;
		while ((ret = read(fd, &c, 1)) > 0 && c != '\n')
		{
			map[i][j] = c;
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
//	map[i][0] = '\0';

	i = 0;
	while (i < row)
	{
		printf("%s\n", map[i]);
		i++;
	}
	close(fd);
	printf("end\n");
	return (map);
}

int		main(int ac, char **av)
{
	long int	rows;
	long int	cols;
	char		c;

	rows = 0;
	cols = 0;
	c = 0;
	if (ac < 2)
		ft_putstr2("File name missing.\n");
	else if (ac > 2)
		ft_putstr2("Too many arguments.\n");
	else
	{
		rows = rows_size(av, c);
		if (rows == -1)
			return (1);
		cols = cols_len(av, rows, c);
		if (cols == -1)
			return (1);
	}
	printf("end map create\n");
	find_biggest(map_create(av, rows, cols, c));
	return (0);
}
