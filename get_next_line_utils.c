/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:55:43 by odruke-s          #+#    #+#             */
/*   Updated: 2024/11/14 20:44:07 by odruke-s         ###   ########.fr       */
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
/*
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp_s;

	temp_s = (char *)s;
	i = 0;
	while (i < n)
		temp_s[i++] = '\0';
}
*/
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		b;

	i = -1;
	b = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(BUFFER_SIZE, sizeof(char));
	res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!res)
		return (NULL);
//	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	while (s1[++i])
		res[i] = s1[i];
//	ft_strlcpy(res + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	while (s2[b])
		res[i++] = s2[b++];
	res[i] = 0;
//	ft_bzero(s2, ft_strlen(s2));
	b = 0;
	while (s2[b])
		s2[b++] = 0;
	return (res);
}
