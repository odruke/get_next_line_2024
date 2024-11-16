/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:55:43 by odruke-s          #+#    #+#             */
/*   Updated: 2024/11/15 21:29:05 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	res = (void *)malloc(nmemb * size);
	if (!res)
		return (NULL);
	while (i < nmemb * size)
		res[i++] = 0;
	return (res);
}

char	*ft_strjoin(char *old_buffer, char *read_buff)
{
	char	*new_buffer;
	int		i;
	int		b;

	i = -1;
	b = 0;
	if (!read_buff)
		return (NULL);
	if (!old_buffer)
		old_buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	new_buffer = ft_calloc((ft_strlen(old_buffer) + ft_strlen(read_buff) + 1),
			sizeof(char));
	if (!new_buffer)
		return (NULL);
	while (old_buffer[++i])
		new_buffer[i] = old_buffer[i];
	while (read_buff[b])
		new_buffer[i++] = read_buff[b++];
	new_buffer[i] = 0;
	b = 0;
	while (read_buff[b])
		read_buff[b++] = 0;
	free (old_buffer);
	return (new_buffer);
}
