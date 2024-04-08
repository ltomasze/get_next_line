/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:36:46 by ltomasze          #+#    #+#             */
/*   Updated: 2024/04/08 15:14:59 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*temp;
	char			*buffer;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(temp), temp = NULL, NULL);
	if (have_n(temp))
		return (print_line(&temp));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		temp = ft_strjoin(temp, buffer);
		if (have_n(temp))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (print_line(&temp));
}
/*
int main(void)
{
    int     fd;
    char    *str;
    char    *path;
    int     i;

    path = "test.txt";
    fd = open(path, O_RDONLY);
    i = 0;
    while(i < 5)
    {
        str = get_next_line(fd);
        printf("i: %i\n", i);
        printf("fd: %i, %s\n", fd, str);
        i++;
    }
    return (0);
}*/
