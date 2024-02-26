/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:13:04 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/19 16:36:05 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
