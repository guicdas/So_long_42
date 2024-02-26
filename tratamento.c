/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tratamento.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:16:52 by gcatarin          #+#    #+#             */
/*   Updated: 2023/07/11 18:06:05 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mfwpos(char **c, int ret, va_list argptr, int mfw)
{
	(*c)++;
	if (minuscond(c))
		ret = minusaction(c, ret, argptr);
	else if (zerocond(c))
		ret = zeroaction(c, ret, argptr);
	else if (pointcond(c))
		ret = pointaction(c, ret, argptr, mfw);
	else
		ret = ret + compare(c, argptr);
	return (ret);
}

int	nonmfw(char **c, int ret, va_list argptr, int mfw)
{
	if (minuscond(c))
		ret = minusaction(c, ret, argptr);
	else if (zerocond(c))
		ret = zeroaction(c, ret, argptr);
	else if (pointcond(c))
		ret = pointaction(c, ret, argptr, mfw);
	else
	{
		mfw = numcond(*c);
		if (mfw != 0)
			ret = ret + action(c, argptr, mfw, mfw);
		else
			ret = ret + compare(c, argptr);
	}
	return (ret);
}

int	percentcond(char **c, int ret, va_list argptr)
{
	int	mfw;

	(*c)++;
	mfw = numcond(*c);
	if (mfw > 0)
		ret = mfwpos(c, ret, argptr, mfw);
	else
		ret = nonmfw(c, ret, argptr, mfw);
	return (ret);
}

int	tratamento(char *c, int ret, va_list argptr)
{
	while (*c)
	{
		if (*c == '%')
			ret = percentcond(&c, ret, argptr);
		else
			ret = ret + write(1, c, 1);
		c++;
	}
	return (ret);
}
