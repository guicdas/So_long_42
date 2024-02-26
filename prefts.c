/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:10:47 by gcatarin          #+#    #+#             */
/*   Updated: 2022/12/23 17:16:29 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*preint(va_list argptr)
{
	int		i;

	i = va_arg(argptr, int);
	return (ft_itoa(i, 10, "0123456789"));
}

char	*prechar(va_list argptr)
{
	char	c;

	c = va_arg(argptr, int);
	return (ft_itoa(c, 10, "0123456789"));
}

char	*prestr(va_list argptr)
{
	char		*s;

	s = va_arg(argptr, char *);
	if (!s)
		return ("(null)");
	return (s);
}

char	*prexuint(va_list argptr, int bs, char *b)
{
	unsigned int		i;

	i = va_arg(argptr, unsigned int);
	return (ft_itoa(i, bs, b));
}

char	*precompare(char **str, va_list argptr)
{
	if (**str == 'd' || **str == 'i')
		return (preint(argptr));
	if (**str == 's')
		return (prestr(argptr));
	if (**str == 'u')
		return (prexuint(argptr, 10, "0123456789"));
	if (**str == 'x')
		return (prexuint(argptr, 16, "0123456789abcdef"));
	if (**str == 'X')
		return (prexuint(argptr, 16, "0123456789ABCDEF"));
	return (0);
}
