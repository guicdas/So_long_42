/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:53:12 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/25 21:38:38 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i != n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (p)
	{
		ft_memset(p, '\0', nmemb * size);
		return (p);
	}
	return (NULL);
}

char	*ft_memcpy(char *dest, char *src, size_t n)
{
	size_t			i;

	i = -1;
	while (++i < n)
	{
		dest[i] = src[i];
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	str[len1 + len2] = 0;
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	free(s1);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char) c)
		{
			return ((char *)str);
		}
		str++;
	}
	if ((char) c == 0)
		return ((char *)str);
	return (NULL);
}
