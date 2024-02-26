/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:19:44 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/19 13:54:44 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		ret;
	va_list	argptr;

	ret = 0;
	va_start(argptr, s);
	ret = tratamento((char *)s, ret, argptr);
	va_end(argptr);
	return (ret);
}
