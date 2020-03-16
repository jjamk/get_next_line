/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:51:32 by skang             #+#    #+#             */
/*   Updated: 2020/03/16 23:30:20 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_read(int const fd, char *buf, int *idx)
{
	char	buff[BUFFER_SIZE + 1];

	*idx = read(fd, buff, BUFFER_SIZE);
	if (*idx < BUFFER_SIZE && buff[*idx -1] != '\n') //버퍼사이즈보다 덜읽었을 때 
	{
		buff[*idx] = '\n';
		buff[*idx + 1] = '\0';
	}
	else 
		buff[*idx] = '\0';
	buf = ft_strcat(buf, buff);
	return (buf);
}

int			get_next_line(int const fd, char **line)
{
	static char		*buf = NULL;
	int				idx;
	char			*str;

	if (!line || fd < 0)
		return (-1);
	idx = 1;
	if (!buf)
		buf = (char*)malloc(1);
	while (idx > 0)
	{
		if ((str = ft_strchr(buf, '\n')) != NULL)
		{
			*str = 0;
			*line = ft_strdup(buf);
			ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		buf = get_read(fd, buf, &idx);
	}
	if (idx == 0)
		*line = (char*)malloc(1);
	return (idx);
}
