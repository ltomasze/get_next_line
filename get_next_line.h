/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:37:07 by ltomasze          #+#    #+#             */
/*   Updated: 2024/04/08 11:43:58 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(char *s);
char	*ft_strdup(char *str, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_loop(char *str1, char *str2);
int		have_n(char	*temp);
char	*print_line(char **temp);
char	*get_next_line(int fd);
#endif