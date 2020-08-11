/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:42:56 by etorren           #+#    #+#             */
/*   Updated: 2020/08/11 21:01:47 by etorren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <unistd.h>
# include <fcntl.h>

void	ft_puterr(char *str);
int		rows_size(char **av, char c);
int		cols_len(char **av, long int row, char c);
char	**map_create(char **av, long int row, long int cols, char c);
void	find_biggest(char **map);
char	*retrieve_params(char **map);
int		check_map(char **map, char *params);

#endif
