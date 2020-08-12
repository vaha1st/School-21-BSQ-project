/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 20:46:48 by etorren           #+#    #+#             */
/*   Updated: 2020/08/12 16:09:55 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

/*
** ft_puterr(*) takes a string and display it in reserved for errors
** output.
**
** rows_count(*) scans given file and counts rows.
**
** rows_len(*) scans given file and counts length of single row.
**
** check_map(*) checks map and header on incorrect data.
**
** map_create(*) reads file and creates a map filling it char by char.\
** Ads null pointer to the end of each line.
*/

void		ft_puterr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

long int	rows_count(char *av, char c)
{
	int			fd;
	long int	rows;
	ssize_t		ret;

	rows = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (open_err());
	while ((ret = read(fd, &c, 1)) > 0)
		if (c == '\n')
			rows++;
	if (ret < 0)
		return (read_err(fd));
	if (rows == 1)
		return (read_err(fd));
	close(fd);
	return (rows);
}

long int	rows_len(char *av, long int rows, char c)
{
	int			fd;
	long int	cols;
	ssize_t		ret;
	long int	i;
	int			check;

	i = 0;
	cols = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (open_err());
	while (i < rows - 1)
	{
		check = cols;
		cols = 0;
		while ((ret = read(fd, &c, 1)) > 0 && c != '\n')
			cols++;
		i++;
		if (check != cols && i > 2)
			return (bad_align_err());
	}
	close(fd);
	return (cols);
}

int			check_map(char **map, char *head, long int rows)
{
	int i;
	int j;

	i = 1;
	if (head[0] == head[1] || head[0] == head[2] || head[1] == head[2])
	{
		ft_puterr("map error: incorrect 'empty' or 'obstacle' char\n");
		return (1);
	}
	while (i < rows)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == head[0] || map[i][j] == head[1])
			{
				j++;
			}
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

char		**map_create(char *av, long int row, long int cols, char c)
{
	long int	i;
	int			j;
	int			fd;
	ssize_t		ret;
	char		**map;

	i = 0;
	map = (char **)malloc(sizeof(map) * (row + 1));
	fd = open(av, O_RDONLY);
	while (i < row + 1)
	{
		j = 0;
		map[i] = (char *)malloc(sizeof(char) * (cols + 1));
		while ((ret = read(fd, &c, 1)) > 0 && c != '\n')
		{
			map[i][j] = c;
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (map);
}
