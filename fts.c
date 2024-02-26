/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:48:18 by gcatarin          #+#    #+#             */
/*   Updated: 2022/12/23 20:20:47 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftint(va_list argptr, char m)
{
	long long	t;
	int			ret;

	ret = 0;
	t = va_arg(argptr, int);
	if (t < 0)
	{
		ret = write(1, "-", 1);
		t = -t;
	}
	else
	{
		if (m == '+')
			ret = write(1, "+", 1);
		if (m == ' ')
			ret = write(1, " ", 1);
	}
	return (ret + put_b_nbr(t, DEX, 10));
}

int	ftstr(va_list argptr, char m, int max)
{
	char	*s;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	s = va_arg(argptr, char *);
	if (!s)
		return (write(1, "(null)", 6));
	if (max == -1)
		return (ret + write(1, 0, 0));
	if (m == ' ')
	{
		while (s[i] == ' ')
			i++;
		if (s[i] != '-' && i != 0)
			ret = write(1, "+", 1);
	}
	if (max > 0)
		return (ret + write(1, s, max));
	return (ret + write(1, s, ft_strlen(s)));
}

int	ftchar(va_list argptr)
{
	char	c;

	c = va_arg(argptr, int);
	return (write(1, &c, 1));
}

int	ftp(va_list argptr)
{
	unsigned long	s;

	s = va_arg(argptr, unsigned long);
	if (!s)
		return (write(1, "(nil)", 5));
	return (write (1, "0x", 2) + put_b_nbr(s, HEXAL, 16));
}

int	put_b_nbr(unsigned long long nbr, char *b, size_t bs)
{
	int	i;

	i = 0;
	if (nbr >= bs)
		i = put_b_nbr((nbr / bs), b, bs);
	return (i + write(1, &b[nbr % bs], 1));
}
