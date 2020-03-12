/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:45:20 by skang             #+#    #+#             */
/*   Updated: 2020/03/12 20:53:42 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	get_next_line(int fd, char **line);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int	ft_strlen(char *str);
char	*ft_strdup(char *s1);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);

# define BUFFER_SIZE 7

#endif
