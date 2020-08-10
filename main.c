/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:13:30 by masharla          #+#    #+#             */
/*   Updated: 2020/08/10 19:03:34 by masharla         ###   ########.fr       */
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

	i = 0;
	map = NULL;
	map = (char **)malloc(sizeof(map) * 6);
	while (i <= 4)
	{
		map[i] = (char *)malloc(sizeof(char) * 5);
		printf("==> malloc map[%d] used\n", i);
		i++;
	}
//	if (argc < 2)
//		map = std_input();
//	else
//		map = file_input();
//	while (*map)
//		find_biggest(map);

/*	map[0][0] = '4';
	map[0][1] = '.';
	map[0][2] = 'o';
	map[0][3] = 'x';
	map[0][4] = '\0';
	map[1][0] = '.';
	map[1][1] = 'o';
	map[1][2] = 'o';
	map[1][3] = 'o';
	map[1][4] = '\0';
	map[2][0] = 'o';
	map[2][1] = '.';
	map[2][2] = '.';
	map[2][3] = '.';
	map[2][4] = '\0';
	map[3][0] = '.';
	map[3][1] = '.';
	map[3][2] = '.';
	map[3][3] = '.';
	map[3][4] = '\0';
	map[4][0] = 'o';
	map[4][1] = 'o';
	map[4][2] = '.';
	map[4][3] = 'o';
	map[4][4] = '\0';
	map[5][0] = '\0';*/

	map[0] = "4.ox\0";
	map[1] = ".ooo\0";
	map[2] = "o...\0";
	map[3] = "....\0";
	map[4] = "oo.o\0";
	map[5] = "\0";
	printf("==> map created\n");
	find_biggest(map);
}
