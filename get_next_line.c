/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:33:13 by odruke-s          #+#    #+#             */
/*   Updated: 2024/11/15 22:05:41 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char *old_buff)
{
	char	*new_buff;
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (old_buff[i] && old_buff[i] != '\n')
		i++;
	if (!old_buff[i])
	{
		free(old_buff);
		return (NULL);
	}
	new_buff = ft_calloc((ft_strlen(old_buff) - i) + 1, sizeof(char));
	if (!new_buff)
		return (NULL);
	i++;
	while (old_buff[i])
		new_buff[b++] = old_buff[i++];
	if (old_buff[i] == '\n')
		new_buff[b] = '\n';
	free(old_buff);
	return (new_buff);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*read_raw(int fd, char *buffer)
{
	char	*read_buff;
	int		read_count;

	read_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buff)
		return (NULL);
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, read_buff, BUFFER_SIZE);
		if (read_count < 0)
		{
			free(read_buff);
			return (NULL);
		}
		read_buff[read_count] = 0;
		buffer = ft_strjoin(buffer, read_buff);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(read_buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_raw(fd, buffer);
	line = get_line(buffer);
	buffer = next_line(buffer);
	return (line);
}
