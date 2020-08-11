/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:13:30 by masharla          #+#    #+#             */
/*   Updated: 2020/08/11 17:00:07 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	char **map;
	int i;
	int j;

	i = 0;
	j = 0;
	map = (char **)malloc(sizeof(map)*4);
	printf("size map = %lu\n", sizeof(map));
	while (i < 7)
	{
		map[i] = (char *)malloc(sizeof(char) * 4);

		i++;
	}

//	if (argc < 2)
//		map = std_input();
//	else
//		map = file_input();
//	while (*map)
//		find_biggest(map);
	map[0][0] = '4';
	map[0][1] = '.';
	map[0][2] = 'o';
	map[0][3] = 'x';
	map[0][4] = '.';
	map[0][5] = '.';
	map[1][0] = '.';
	map[1][1] = 'o';
	map[1][2] = 'o';
	map[1][3] = 'o';
	map[1][4] = '.';
	map[1][5] = '.';
	map[2][0] = 'o';
	map[2][1] = '.';
	map[2][2] = '.';
	map[2][3] = '.';
	map[2][4] = '.';
	map[2][5] = '.';
	map[3][0] = '.';
	map[3][1] = '.';
	map[3][2] = '.';
	map[3][3] = '.';
	map[3][4] = '.';
	map[3][5] = 'o';
	map[4][0] = 'o';
	map[4][1] = '.';
	map[4][2] = '.';
	map[4][3] = '.';
	map[4][4] = '.';
	map[4][5] = '.';
	map[5][0] = 'o';
	map[5][1] = '.';
	map[5][2] = '.';
	map[5][3] = '.';
	map[5][4] = '.';
	map[5][5] = '.';
	map[6][0] = '\0';

	printf("=======> HERE\n");

/*	map[0] = "4.ox\0";
	map[1] = ".ooo\0";
	map[2] = "o...\0";
	map[3] = "....\0";
	map[4] = "oo.o\0";
	map[5] = "\0";
	*/

	printf("==> map created\n");
	find_biggest(map);
}
