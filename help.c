/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:17:48 by gcatarin          #+#    #+#             */
/*   Updated: 2023/01/07 23:18:35 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numaction(int ret, int mfw)
{
	while (mfw-- > 0)
		ret = ret + write(1, " ", 1);
	return (ret);
}

int	verif(char **c, int nums)
{
	int	i;

	i = nums;
	while (nums > 0)
	{
		nums = nums / 10;
		(*c)++;
	}
	if (nums == -1)
	{
		(*c)++;
		i = 0;
	}
	return (i);
}

int	flags(char **str, va_list argptr)
{
	if (**str == '#')
	{
		(*str)++;
		if (**str == 'x')
			return (fun(argptr, HEXAL, **str));
		if (**str == 'X')
			return (fun(argptr, HEXAU, **str));
	}
	else if (**str == '+')
	{
		(*str)++;
		if (**str == 'd' || **str == 'i')
			return (ftint(argptr, '+'));
	}
	else
		if (**str == ' ')
			return (spaceflag(str, argptr));
	return (0);
}

int	compare(char **str, va_list argptr)
{
	if (**str == '%')
		return (write(1, "%", 1));
	if (**str == 'd' || **str == 'i')
		return (ftint(argptr, 0));
	if (**str == 's')
		return (ftstr(argptr, 0, -2));
	if (**str == 'p')
		return (ftp(argptr));
	if (**str == 'c')
		return (ftchar(argptr));
	if (**str == 'u')
		return (put_b_nbr(va_arg(argptr, unsigned int), DEX, 10));
	if (**str == 'x')
		return (put_b_nbr(va_arg(argptr, unsigned int), HEXAL, 16));
	if (**str == 'X')
		return (put_b_nbr(va_arg(argptr, unsigned int), HEXAU, 16));
	return (flags(str, argptr));
}
