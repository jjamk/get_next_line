/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:30:38 by skang             #+#    #+#             */
/*   Updated: 2020/03/12 20:09:19 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (s1);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		strlen;
	char	*tmp;

	strlen = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	tmp = (char *)malloc(sizeof(*tmp) * (strlen));
	i = 0;
	if (tmp)
	{
		while (*s1)
			tmp[i++] = *s1++;
		while (*s2)
			tmp[i++] = *s2++;
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int	i;

	str = (char*)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}


char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!((int *) s1 > (int *) s2 && (int *) s2 + n > (int *) s1))
	{
		ft_memcpy(s1, s2, n);
	}	
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			*((char *) s1 + i) = *((char *) s2 + i);
		}
	}
	return (s1);
}
