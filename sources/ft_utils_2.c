/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:13:37 by gcatarin          #+#    #+#             */
/*   Updated: 2022/11/20 17:13:37 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	tam;
	int		i;

	i = 0;
	tam = ft_strlen(s);
	str = (char *)malloc((sizeof(char) * tam) + 1);
	if (!str)
		return (NULL);
	while (*s)
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] && str1[i] == str2[i])
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return (str1[i] - str2[i]);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*comp;
	size_t	j;
	size_t	i;

	i = 0;
	comp = (char *) s;
	j = ft_strlen(comp);
	if (start >= j)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (j - start < len)
		return (ft_strdup((char *)comp + start));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (start < j && i < len)
		str[i++] = comp[start++];
	str[i] = '\0';
	return (str);
}
