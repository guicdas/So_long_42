/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:15:03 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/25 21:51:11 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*convet(long long n, char *str, int bs, char *b)
{
	if (n < 0)
	{
		n = -n;
		*str++ = '-';
	}
	if (n >= bs)
		str = convet(n / bs, str, bs, b);
	*str++ = b[n % bs];
	*str = 0;
	return (str);
}

char	*ft_itoa(long long n, int bs, char *b)
{
	static char	s[100];

	convet(n, s, bs, b);
	return (s);
}
