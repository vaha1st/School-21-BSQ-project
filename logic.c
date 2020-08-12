/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:32:04 by masharla          #+#    #+#             */
/*   Updated: 2020/08/12 13:06:36 by etorren          ###   ########.fr       */
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
	if (map[1])
		while (map[1][i])
			i++;
	else
		while (map[0][i])
			i++;
	return (i);
}

char		**build_first_row_col(long int rows, long int cols,\
		char **map, char *params)
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
		submap[i][0] = convert(map[1 + i][0], params[0], params[1]);
		i++;
	}
	submap[i] = "\0";
	while (j < cols)
	{
		submap[0][j] = convert(map[1][j], params[0], params[1]);
		j++;
	}
	submap[0][j] = '\0';
	return (submap);
}

char		**build_remaining(long int rows, long int cols,\
		char **map, char *params)
{
	int		i;
	int		j;
	char	**submap;

	submap = build_first_row_col(rows, cols, map, params);
	i = 1;
	j = 1;
	while (i < rows - 1)
	{
		while (j < cols)
		{
			(map[i + 1][j] == params[0] ? (submap[i][j] = min(submap[i][j - 1],\
			submap[i - 1][j], submap[i - 1][j - 1]) + 1) :\
			((submap[i][j] = 48)));
			j++;
		}
		submap[i][j] = '\0';
		i++;
		j = 1;
	}
	return(submap);
}

void		find_biggest(char **map)
{
	int			i;
	long int	rows;
	long int	cols;
	char		**submap;
	char		*params;

	i = 0;
	rows = count_rows(map);
	cols = count_cols(map);
	params = retrieve_params(map);
	submap = build_remaining(rows, cols, map, params);
	fill_map(find_max(rows, cols, submap), submap, map, params);
	free_map(submap);
	print_map_wo_header(map, rows);
	free_map(map);
	free(params);
}
