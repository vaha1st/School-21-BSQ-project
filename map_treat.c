/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:53:19 by masharla          #+#    #+#             */
/*   Updated: 2020/08/10 14:07:29 by masharla         ###   ########.fr       */
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

int		search_i(char max, char **submap)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (char 
}

void	print_result(char max, char **submap)
{
	int i;
	int j;
	int i_needed;
	int j_needed;

	i = 0;
	j = 0;
	i_needed = 
}
