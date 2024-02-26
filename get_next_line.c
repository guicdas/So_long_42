/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:52:52 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/25 21:38:21 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	i++;
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[i] = 0;
	while (--i >= 0)
		str[i] = s[i];
	return (str);
}

char	*nextline(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	j = ++i;
	while (s[j])
		j++;
	str = (char *)ft_calloc(j - i + 1, sizeof(char));
	j = i--;
	while (s[++i])
		str[i - j] = s[i];
	free(s);
	return (str);
}

char	*getbuf(int fd, char *s)
{
	char	*str;
	int		y;

	str = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	y = read(fd, str, BUFFER_SIZE);
	if (y <= 0)
	{
		free(str);
		if (!s[0])
		{
			free(s);
			s = NULL;
		}
		return (s);
	}
	while (y > 0)
	{
		s = ft_strjoin(s, str);
		if (ft_strchr(s, '\n'))
			break ;
		y = read(fd, str, BUFFER_SIZE);
		str[y] = 0;
	}
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	if (!str)
	{
		str = (char *)ft_calloc(1, 1);
		str = getbuf(fd, str);
	}
	else if (!ft_strchr(str, '\n'))
		str = getbuf(fd, str);
	ret = readline(str);
	str = nextline(str);
	return (ret);
}
