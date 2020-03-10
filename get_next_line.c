/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:51:32 by skang             #+#    #+#             */
/*   Updated: 2020/03/10 19:07:36 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read(int fd, char *buf)
{
	static char buf[1024];
	static char *s;
	static int i;

	if (i == 0)		//여기서 개행이거나 널일 때 제한해주기
	{
		i = read(fd, buf, BUFFER_SIZE);	//읽기
		s = buf;			//포인터에 담기
	}
	if (i == 0)
		return (0);
	buf++;
	return (s);
}
		
int	get_next_line(int fd, char **line)
{
	int val;
	char *str;

	if (!(line && fd < 0))
		return (-1);
	if (str = malloc(BUFFER_SIZE + 1))
		return (0);
	str = get_read(fd);
	while ((str + 1) != '\n' && (str + 1) != '\0')	//버퍼사이즈가 파일보다 작은 경우
	{
		str++;
		str = get_read(fd);		//읽기 전에 버퍼사이즈만큼 또 할당?
		
	}
	str[idx] = '\0';
	line = &str;
	return (1);
}
		
