/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:55:43 by odruke-s          #+#    #+#             */
/*   Updated: 2024/11/10 13:50:55 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp_s;

	temp_s = (char *)s;
	i = 0;
	while (i < n)
		temp_s[i++] = '\0';
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcpy(res + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	ft_bzero(s2, ft_strlen(s2));
	return (res);
}
