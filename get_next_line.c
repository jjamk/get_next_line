/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:51:32 by skang             #+#    #+#             */
/*   Updated: 2020/03/12 20:55:36 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*get_read(int fd, char *buf, int *idx)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;

	
	*idx = read(fd, buff, BUFFER_SIZE);
	if (*idx < BUFFER_SIZE && buff[*idx - 1] != '\n')
	{
		buff[*idx] = '\n';	//개행 만나지 않을 때이거나 버퍼사이즈보다 읽을 게 적음
		buff[*idx + 1] = '\0';
	}
	else
		buff[*idx] = '\0';
	tmp = buf;
	buf = ft_strcat(buf, buff);	//이어 붙이기
	free(tmp);			//(*중요) buf를 가리킨 포인터 free
	return (buf);
}
	
int get_next_line(int fd, char **line)
{
	static char *buf = NULL;
	char *str;
	int idx;

	idx = 1;
	if (!line || fd < 0)
		return (-1);
	if (!buf)
		buf = malloc(1);		//buf 동적할당 (가리키는 주소 만들어주기)
	while (idx > 0)
	{
		if ((str = ft_strchr(buf, '\n'))) 	//buf에 개행이 있으면
		{
			*line = ft_strdup(buf);		//line에 buf 만큼 동적할당 후 복제
			ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1); //buf에 넣어주기
			return (1);
		}
		buf = get_read(fd, buf, &idx);
	}
	if (idx == 0)
		*line = malloc(1);
	return (idx);
}


int main()
{
	char *line = 0;
	int fd;
	int ret;

	fd = open("you.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
	//while ((ret = get_next_line(fd, &line)) > 0)
	//{
		printf("%s\n", line);
		//get_next_line(fd, &line);
		
	//}
	return (0);
}

/*char	get_read(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	static char *s;
	static int idx;
	char c; 

	if (idx == 0)
	{
		idx = read(fd, buf, BUFFER_SIZE);
		s = (char*)&buf;
		if (idx == 0)			//EOF 만났을 때
			return (0);
	}
	c = *s;
	printf("%c\n", c);
	s++;
	idx = 0;
	return (c);
}
		
int	get_next_line(int fd, char **line)
{
	int i;			//버퍼사이즈 넘어가지 않는 카운트용
	char *str;
	char c;

	i = 1;
	if (!line && fd < 0)
		return (-1);
	if (!(str = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!(c = get_read(fd)))
	{
		printf("%c\n", 'y');
		return (0);
	}
	while (c != '\n' && c != '\0' && i >= 0)
	{
		str[i] = c;
		c = get_read(fd);
		if (i % BUFFER_SIZE == 0)
		{
			*line = str;
			str = malloc(BUFFER_SIZE);
		}
		i++;
	}
	printf("i = %d\n", i);
	str[i] = '\0';
	printf("str = %s\n", str);
		return (1);
}*/
