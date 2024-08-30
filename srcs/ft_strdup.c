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
