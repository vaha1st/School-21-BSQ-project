/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:53:19 by masharla          #+#    #+#             */
/*   Updated: 2020/08/12 22:19:48 by etorren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** find_max(*) takes a submap and finds the maximum value on the map.
**
** fill_map(*) takes a submap and search for the first appearance of\
** the max value. Then it replaces the same element of array and\
** related square on the original map with character given as 'full'.
**
** retrieve_params(*) takes a header (first row) of the map and retrieves\
** 'free', 'obstacle' and 'full' characters. Reterns result as a string.
*/

int		find_max(long int rows, long int cols, char **submap)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max = 0;
	while (i < rows - 1)
	{
		while (j < cols)
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

void	fill_map_core(char max, char **map, int *i, char *params)
{
	int j_size;

	j_size = max - 48;
	while (j_size--)
		map[i[0] + 1][i[1]--] = params[2];
	i[1] += (max - 48);
	i[0]--;
}

void	fill_map(char max, char **submap, char **map, char *params)
{
	int i[2];
	int	i_size;

	i[0] = 0;
	i[1] = 0;
	i_size = max - 48;
	while (submap[i[0]])
	{
		while (submap[i[0]][i[1]])
		{
			if (submap[i[0]][i[1]] == max)
			{
				while (i_size--)
				{
					fill_map_core(max, map, i, params);
				}
				return ;
			}
			i[1]++;
		}
		i[0]++;
		i[1] = 0;
	}
}

char	*retrieve_params(char **map)
{
	long int	i;
	long int	rows;
	int			count;
	char		*params;

	count = 0;
	rows = count_rows(map);
	rows--;
	i = 0;
	while (rows)
	{
		rows /= 10;
		count++;
	}
	params = (char *)malloc(sizeof(char) * 4);
	while (i < 3)
		params[i++] = map[0][count++];
	params[i] = '\0';
	return (params);
}

int		check_num(char **map, char *av)
{
	long int	i;
	long int	rows;
	int			count;
	char		*num;

	count = 0;
	rows = count_rows(map);
	rows--;
	i = 0;
	while (rows)
	{
		rows /= 10;
		count++;
	}
	num = (char *)malloc(sizeof(char) * count + 1);
	while (i < count)
	{
		num[i] = map[0][i];
		i++;
	}
	num[i] = '\0';
	rows = count_rows(map) - 1;
	if (ft_atoi(num) != rows || rows == 0 || (count + 3) != head_read(av))
		return (-1);
	return (0);
}
