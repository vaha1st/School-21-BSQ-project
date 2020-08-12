/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:42:56 by etorren           #+#    #+#             */
/*   Updated: 2020/08/12 12:11:24 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

void	ft_puterr(char *str);
int		rows_size(char *av, char c);
int		cols_len(char *av, long int row, char c);
char	**map_create(char *av, long int row, long int cols, char c);
void	find_biggest(char **map);
char	*retrieve_params(char **map);
int		check_map(char **map, char *params, long int rows);
int		std_input_read(char *file_name);
int		open_err(void);
int		read_err(int fd);
int		bad_align_err(void);

#endif
