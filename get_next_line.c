/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 20:20:03 by skang             #+#    #+#             */
/*   Updated: 2020/08/14 20:20:07 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_del(char *save, char **line, int idx)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(save))
	{
		*line = ft_substr(save, 0, i);
		tmp = ft_substr(save, i + 1, ft_strlen(save));
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else if (idx == 0)
	{
		*line = save;
		save = NULL;
	}
	return (save);
}

char				*ft_save(char *buf, char *save)
{
	char			*tmp;

	if (save)
	{
		tmp = ft_strjoin(save, buf);
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else
		save = ft_strdup(buf);
	return (save);
}

int					get_next_line(int fd, char **line)
{
	static char		*save[4096];
	char			buf[BUFFER_SIZE + 1];
	int				idx;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	while ((idx = read(fd, buf, BUFFER_SIZE)))
	{
		if (idx == -1)
			return (-1);
		buf[idx] = '\0';
		save[fd] = ft_save(buf, save[fd]);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (idx <= 0 && !save[fd])
	{
		*line = ft_strdup("");
		return (idx);
	}
	save[fd] = ft_del(save[fd], line, idx);
	if (idx <= 0 && !save[fd])
		return (idx);
	return (1);
}
