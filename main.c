/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:13:30 by masharla          #+#    #+#             */
/*   Updated: 2020/08/10 10:56:58 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	char **map;

	map = malloc(sizeof(map));
	if (argc < 2)
		map = std_input();
	else
		map = file_input();
	while (*map)
		find_biggest(map);
}
