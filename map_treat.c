/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:53:19 by masharla          #+#    #+#             */
/*   Updated: 2020/08/11 12:01:00 by masharla         ###   ########.fr       */
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
** print_map_wo_header(*) just prints map row by row without first line.
**
** free_map(*) frees memory of all rows on map firstly, then frees\
** the map itself.
*/

int		find_max(long int rows, long int cols, char **submap)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
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

void	fill_map(char max, char **submap, char **map)
{
	int i;
	int j;
	int	i_size;
	int	j_size;

	i = 0;
	j = 0;
	i_size = max - 48;
	while (submap[i++])
	{
		while (submap[i][j++])
			if (submap[i][j] == max)
			{
				while (i_size--)
				{
					j_size = max - 48;
					while (j_size--)
						map[i + 1][j--] = map[0][3];
					j += (max - 48);
					i--;
				}
				return ;
			}
		j = 0;
	}
}

void	print_map_wo_header(char **map, long int rows)
{
	int i;

	i = 1;
	while (i < rows)
	{
		ft_putstr(map[i++]);
		ft_putstr("\n");
	}
}

void	free_map(char **map)
{
	int			i;
	long int	rows;

	i = 0;
	rows = count_rows(map);
	while (i < rows)
		free(map[i++]);
	free(map);
}
