/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:32:06 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/25 21:50:17 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	fun(va_list argptr, char *s, char c)
{
	unsigned long long	t;
	int					i;

	t = va_arg(argptr, unsigned int);
	i = 0;
	if (t != 0)
	{
		if (c == 'x')
			i = write (1, "0x", 2);
		if (c == 'X')
			i = write (1, "0X", 2);
	}
	return (i + put_b_nbr(t, s, 16));
}

int	conta(char *arg)
{
	int	ret;

	ret = 0;
	while (*arg++)
		ret++;
	return (ret);
}

int	nums(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	spaceflag(char **str, va_list argptr)
{
	int	nums;
	int	i;

	i = 0;
	(*str)++;
	nums = numcond(*str);
	i = nums;
	if (i == -1)
		nums = 1;
	while (nums > 0)
	{
		nums = nums / 10;
		(*str)++;
	}
	if (**str == 's')
		return (ftstr(argptr, ' ', i));
	if (**str == 'd' || **str == 'i')
		return (ftint(argptr, ' '));
	return (0);
}
