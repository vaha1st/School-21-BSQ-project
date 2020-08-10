/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:53:19 by masharla          #+#    #+#             */
/*   Updated: 2020/08/10 22:07:10 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int		find_max(long int rows, long int cols, char **submap)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		while(j < cols)
		{
			if (max < submap[i][j])
				max = submap[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (max);
}

void	fill_map(char max, char **submap, char **map)
{
	int i;
	int j;
	int	i_size;
	int	j_size;

	i = 0;
	j = 0;
	i_size = max - 48;
	map[0][1] = 1;
	printf("max = %d\n", max);
	printf("map[0][1] = %d\n", map[0][1]);
	while (submap[i++])
	{
		while (submap[i][j++])
		{
			if (submap[i][j] == max)
			{
				while (i_size)
				{
					j_size = max - 48;
					while(j_size)
					{
						 printf("map[%d+1][%d] = '%c' : max = %c\n", i, j, map[i + 1][j],  max);
						map[i + 1][j] = map[0][3];
						j--;
						j_size--;
					}
					j += (max - 48);
					i--;
					i_size--;
				}
				return ;
			}
		}
		j = 0;
	}
}

