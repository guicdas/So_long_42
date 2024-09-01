/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functsbonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:33:34 by gcatarin          #+#    #+#             */
/*   Updated: 2022/12/23 18:46:50 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	minuscond(char **c)
{
	if (**c == '-')
	{
		(*c)++;
		return (1);
	}
	return (0);
}

int	spacecond(char **c)
{
	if (**c == ' ')
	{
		(*c)++;
		return (1);
	}
	return (0);
}

int	numcond(char *c)
{
	int	mfw;

	mfw = 0;
	if (*c > '0' && *c <= '9')
	{
		while (*c >= '0' && *c <= '9')
		{
			mfw = (mfw * 10) + *c - 48;
			c++;
		}
		return (mfw);
	}
	else if (*c == '0')
		return (-1);
	return (0);
}

int	zerocond(char **c)
{
	if (**c == '0')
		return (1);
	return (0);
}

int	pointcond(char **c)
{
	if (**c == '.')
		return (1);
	return (0);
}
