/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:29:42 by qmebble           #+#    #+#             */
/*   Updated: 2019/02/14 20:23:35 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 10

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int		main (int argc, char **argv);
t_list	*check(char **file, t_list *point, int i, int fd);
int		check_buf(char *buf, int i, int sharp, int point);
int		check_tetriminos(char *buf, int len);
t_list	*record(char *buf, t_list *point, char name);
int		record_name(t_list *point);
int		generic_map(t_list *point);
int		ft_sqrt(int nb);
t_list	*ft_list(t_list *point, t_list *start, int siz);
void	ft_list_red(int **ar, char *str, int siz);
int		ft_pos(char *map, int start);
int		check_for_fit(char *map, t_list *point, int i);
void	check_first(char *map, int size_map);
char	*ft_alco(t_list *point, int size_map);
int		ft_algorithm(t_list *point, char *map, int pos);
int		*ft_difference(int *coor, int pos, char *map, int len);
char	*new_map(char *map, t_list *point);

#endif
