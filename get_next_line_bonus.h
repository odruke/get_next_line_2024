/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:38:26 by odruke-s          #+#    #+#             */
/*   Updated: 2024/11/15 22:14:30 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
#endif
