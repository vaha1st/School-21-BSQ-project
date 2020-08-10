/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:32:04 by masharla          #+#    #+#             */
/*   Updated: 2020/08/10 18:20:58 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

char		min(char m1, char m2, char m3)
{
	char tmp;

	tmp = m1;
	(tmp > m2 ? tmp = m2 : 1);
	(tmp > m3 ? tmp = m3 : 1);
	printf("==> min OK\n");
	return (tmp);
}

long int	count_rows(char **map)
{
	int i;
	
	i = 0;
	printf("==> count_rows HERE");
	while (map[i][0])
		i++;
	printf("==> count_rows OK: rows = %d\n", i);
	return (i);
}

long int	count_cols(char **map)
{
	int i;
	
	i = 0;
	printf("==> count_cols HERE");
	while (map[0][i])
		i++;
	printf("==> count_cols OK: cols = %d\n", i);
	return (i);
}

char **build_submap(long int rows, long int cols, char **map)
{
	int i;
	int j;
	char **submap;

	i = 0;
	j = 0;
	submap = (char **)malloc(sizeof(submap) * rows);
	while (i < rows - 1)
	{
		submap[i] = (char *)malloc(sizeof(char) * cols);
		submap[i][0] = map[1 + i][0];
		i++;
	}
	submap[i] = "\0";
	printf("==> submap rows OK: записано элементов: %d\n", i);
	while (j < cols)
	{
		submap[0][j] = map[1][j];
		j++;
	}
	printf("==> submap cols OK: записано элементов: %d\n", j);
	i = 1;
	j = 1;
	while (i < rows - 1)
	{
		while(j < cols)
		{
			printf("j++\n");
			(map[i + 1][j] == map[0][1] ? (submap[i][j] = min(submap[i][j-1],\
			submap[i-1][j], submap[i-1][j-1]) + 1) : ((submap[i][j] = map[0][2]) && printf("==> min SKIP\n")));
			j++;
		}
	//	submap[i][j] = '\0';
		i++;
		j = 1;
		printf("i++\n");
	}
	// delete >>
	i = 0;
	while (i < rows - 1)
	{
		printf("%s\n", submap[i]);
		i++;
	}
	//delete <<
	return (submap);
}

void		find_biggest(char **map)
{
	int			i;
	long int	rows;
	long int	cols;
	char		**submap;

	i = 0;
	rows = count_rows(map);
	cols = count_cols(map);
	submap = build_submap(rows, cols, map);
	convert_obs(submap, map);
	fill_map(find_max(rows, cols, submap), submap, map);
	while (i < rows - 1)
		{
			printf("%s\n", map[i]);
			i++;
		}
	return;
}
