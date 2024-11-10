/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:33:13 by odruke-s          #+#    #+#             */
/*   Updated: 2024/11/11 00:17:42 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_raw(int fd, char *buffer)
{
	char	read_buff[BUFFER_SIZE];
	int		read_count;

	read_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buff)
		return (NULL);
	read_count = 1;
	while (read_count < 0 && ft_strchr('\n', buffer))
	{
		read_count = read(fd, read_buff, BUFFER_SIZE);
		if (read_count < 0)
		{
			free(read_buff);
			return (NULL);
		}
		ft_strjoin(buffer, read_buff);
	}
	
}
char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer[fd] = read_raw(fd, buffer[fd]);
}
