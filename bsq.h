/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:27:57 by masharla          #+#    #+#             */
/*   Updated: 2020/08/10 10:57:12 by masharla         ###   ########.fr       */
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

#endif
