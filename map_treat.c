/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:53:19 by masharla          #+#    #+#             */
/*   Updated: 2020/08/10 18:22:19 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
		i++;
	}
	return (max);
}

void	fill_map(char max, char **submap, char **map)
{
	int i;
	int j;
	int	i_size;
	int j_size;

	i = 0;
	j = 0;
	i_size = max - map[0][1];
	j_size = max - map[0][1];
	while (submap[i++])
		while (submap[i][j++])
			if (submap[i][j] == max)
				while (i_size--)
				{
					while(j_size--)
					{
						map[i + 1][j] = max;
						j--;
					}
					j += (max - map[0][1]);
					i--;
				}
}

void	convert_obs(char **submap, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (submap[i])
	{
		while (submap[i][j])
		{
			if (submap[i][j] == map[0][2])
				submap[i][j] = 31;
			j++;
		}
		i++;
	}
}
