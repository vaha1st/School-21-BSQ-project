/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:13:30 by masharla          #+#    #+#             */
/*   Updated: 2020/08/12 13:39:54 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

/*
** The program find the biggest square on a map, avoiding obstacles.
** Features: Reads n amount of files. Supports manual input.
**
** read_file(*) takes given as parameter file and apply logic\
** that find biggest square to this file.
*/

void	read_file(char *av, char c)
{
	long int	rows;
	long int	cols;
	char		**map;

	rows = 0;
	cols = 0;
	rows = rows_count(av, c);
	if (rows == -1)
		return ;
	cols = rows_len(av, rows, c);
	if (cols == -1)
		return ;
	map = map_create(av, rows, cols, c);
	if (check_map(map, retrieve_params(map), rows) == 1)
		return ;
	if (check_map(map, retrieve_params(map), rows) == -1)
	{
		ft_puterr("map error: incorrect char in map matrix\n");
		return ;
	}
	find_biggest(map);
}

int		main(int ac, char **av)
{
	char	c;
	int		i;
	char	*file_name;

	i = 1;
	c = 0;
	file_name = "std_input_file";
	if (ac < 2)
	{
		if (std_input_read(file_name) < 0)
			ft_puterr("map error\n");
		read_file(file_name, c);
	}
	while (ac > 1)
	{
		read_file(av[i], c);
		ac--;
		i++;
		if (ac != 1)
			write(1, "\n", 1);
	}
	return (0);
}
