/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:13:30 by masharla          #+#    #+#             */
/*   Updated: 2020/08/11 21:01:39 by etorren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void	read_file(char **av, char c)
{
	long int	rows;
	long int	cols;
	char		**map;

	rows = 0;
	cols = 0;
	rows = rows_size(av, c);
	if (rows == -1)
		return ;
	cols = cols_len(av, rows, c);
	if (cols == -1)
		return ;
	map = map_create(av, rows, cols, c);
	ft_puterr("----map created----\n");
	if (check_map(map, retrieve_params(map)) == -1)
	{
		ft_puterr("Map error: incorrect empty or obstacle char\n");
		return ;
	}
	find_biggest(map);
}

int		main(int ac, char **av)
{
	char	c;
	int		i;

	i = 0;
	c = 0;
	if (ac < 2)
	{
		ft_puterr("File name missing.\n");
		return (1);
	}
	while (ac > 1)
	{
		read_file(&av[i], c);
		ac--;
		i++;
		if (ac != 1)
			ft_puterr("\n****======Next map=====****\n\n");
	}
	return (0);
}
