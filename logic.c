/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:32:04 by masharla          #+#    #+#             */
/*   Updated: 2020/08/10 13:25:59 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		min(char m1, char m2, char m3)
{
	char tmp;

	tmp = m1;
	(tmp > m2 ? tmp = m2 : 1);
	(tmp > m3 ? tmp = m3 : 1);
	return (tmp);
}

long int	count_cols(char **map)
{
	int i;
	
	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

long int	count_rows(char **map)
{
	int i;
	
	i = 0;
	while (map[i][0])
		i++;
	return (i);
}

char **build_submap(long int rows, long int cols, char **map)
{
	int i;
	int j;
	char **submap;

	i = 0;
	j = 0;
	submap = malloc(rows * cols);
	while (i < rows)
	{
		submap[i][0] = map[1 + i][0];
		i++;
	}
	while (i < cols)
	{
		submap[0][j] = map[1][j];
		j++;
	}
	i = 1;
	j = 1;
	while (i < rows)
		{
			while(j < cols)
				(map[i + 1][j] == map[0][1] ? (submap[i][j] = min(submap[i][j-1],\
				submap[i-1][j], submap[i-1][j-1])) : (submap[i][j] = map[0][2]));
		}
	return (submap);
}

void		find_biggest(char **map)
{
	char		full;
	long int	rows;
	long int	cols;
	char		**submap;

	rows = count_rows(map);
	cols = count_cols(map);
	submap = build_submap(rows, cols, map);
	full = map[0][3];



	return;
}
