/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:54:05 by skang             #+#    #+#             */
/*   Updated: 2020/08/03 17:54:12 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char  *ft_next(char *s)
{
    char    *res;
    int     i;
    int     slen;
    int     j;

    i = 0;
    j = 0;
    while (s[i] != '\n')
        i++;
    i++;
    slen = ft_strlen(s) - i; 
    if (!(res = malloc(sizeof(char) * slen + 1)))
        return (NULL);
    while (j <slen)
        res[j++] = s[i++];
    res[j] = '\0';
    free(s);
    return (res);
}

static int  ft_read(int fd, char **s)
{
    int     flag;
    char    temp[BUFFER_SIZE + 1];

    while ((flag = read(fd, temp, BUFFER_SIZE)) > 0)
    {
        temp[flag] = '\0';
        if (!(*s = ft_strjoin(*s, temp)))
        {
            free(*s);
            *s = NULL;
            return (0);
        }
        if (ft_strchr(temp, '\n'))
            return (1);
    }
    return (flag);
}    
int         get_next_line(int fd, char **line)
{
    static char *s;
    int         flag;

    if (fd < 0 || !line)
        return (-1);
    if (!s)
    {
        if (!(s = malloc(sizeof(char))))
            return (-1);
        s[0] = 0;
    }
    flag = ft_read(fd, &s);
    if (flag < 0)
        return (-1);
    *line = ft_strdup(s);
    if (flag == 0 && !ft_strchr(s, '\n'))
    {
        free(s);
        s = NULL;
        return (0);
    }
    s = ft_next(s);
    return (1);
}

