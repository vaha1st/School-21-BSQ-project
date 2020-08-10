/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:27:57 by masharla          #+#    #+#             */
/*   Updated: 2020/08/10 19:40:20 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
char	**std_input();
char	**file_input();
void	find_biggest(char **map);
char	min(char m1, char m2, char m3);
char	**build_submap(long int rows, long int cols, char **map);
int		find_max(long int rows, long int cols, char **submap);
void	fill_map(char max, char **submap, char **map);
char    convert(char c, char empty, char obst);

#endif
