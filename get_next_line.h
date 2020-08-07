/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:54:44 by skang             #+#    #+#             */
/*   Updated: 2020/08/03 17:54:47 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

int get_next_line(const int fd, char **line);
size_t	ft_strlen(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(char *s, int c);
char    *ft_strdup(const char *s1);

#endif
