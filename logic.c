/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:32:04 by masharla          #+#    #+#             */
/*   Updated: 2020/08/11 12:47:45 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** count_rows(*) and count_cols(*) take the original map and count its\
** rows and columns.
**
** build_first_row_col(*) takes original map and copies its first row\
** and column.
**
** build_remaining(*) builds remainig map, element by element, using logic that\
** comparing upper, upper-lef and left peers and inserts min value of them + 1.
**
** find biggest(*) combines all map manipulations and prints the result.
*/

long int	count_rows(char **map)
{
	int i;

	i = 0;
	while (map[i][0])
		i++;
	return (i);
}

long int	count_cols(char **map)
{
	int i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

char		**build_first_row_col(long int rows, long int cols, char **map)
{
	int		i;
	int		j;
	char	**submap;

	i = 0;
	j = 0;
	submap = (char **)malloc(sizeof(submap) * rows);
	while (i < rows - 1)
	{
		submap[i] = (char *)malloc(sizeof(char) * cols);
		submap[i][0] = convert(map[1 + i][0], map[0][1], map[0][2]);
		i++;
	}
	submap[i] = "\0";
	while (j < cols)
	{
		submap[0][j] = convert(map[1][j], map[0][1], map[0][2]);
		j++;
	}
	return (submap);
}

char		**build_remaining(long int rows, long int cols,\
		char **map, char **submap)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i < rows - 1)
	{
		while (j < cols)
		{
			(map[i + 1][j] == map[0][1] ? (submap[i][j] = min(submap[i][j - 1],\
			submap[i - 1][j], submap[i - 1][j - 1]) + 1) :\
			((submap[i][j] = convert(map[0][2], map[0][1], map[0][2]))));
			j++;
		}
		i++;
		j = 1;
	}
	i = 0;
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
	submap = build_first_row_col(rows, cols, map);
	build_remaining(rows, cols, map, submap);
	retrieve_params(map);
	ft_putstr("XXX====>\n");
	fill_map(find_max(rows, cols, submap), submap, map);
	free_map(submap);
	print_map_wo_header(map, rows);
	free_map(map);
}
