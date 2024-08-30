/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes/ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:11:15 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/25 21:50:22 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# define DEX "0123456789"
# define HEXAL "0123456789abcdef"
# define HEXAU "0123456789ABCDEF"

//-------HELPER--FUNCTIONS---//
int		ft_strlen(char *str);
int		fun(va_list argptr, char *s, char c);
int		nums(int n);
int		conta(char *arg);
int		spaceflag(char **str, va_list argptr);
int		numaction(int mfw, int ret);
int		verif(char **c, int nums);
int		flags(char **str, va_list argptr);
int		compare(char **str, va_list argptr);
//----------FTS--------------//
int		put_b_nbr(unsigned long long nbr, char *b, size_t bs);
int		ftp(va_list argptr);
int		ftchar(va_list argptr);
int		ftstr(va_list argptr, char m, int max);
int		ftint(va_list argptr, char m);
//----------PRE-----------------//
char	*precompare(char **str, va_list argptr);
char	*prechar(va_list argptr);
char	*prestr(va_list argptr);
char	*preint(va_list argptr);
char	*prexuint(va_list argptr, int bs, char *b);
//----------ITOA---------------//
char	*ft_itoa(long long n, int bs, char *b);
char	*convet(long long n, char *str, int bs, char *b);
//----------ACTION-------------//
int		minusaction(char **c, int ret, va_list argptr);
int		action(char **c, va_list argptr, int nums, int maxt);
int		zeroaction(char **c, int ret, va_list argptr);
int		pointaction(char **c, int ret, va_list argptr, int maxtudo);
char	*spaceaction(int mfw, char *arg, char k, int max);
//----------------COND----------------//
int		minuscond(char **c);
int		spacecond(char **c);
int		numcond(char *c);
int		zerocond(char **c);
int		pointcond(char **c);
int		percentcond(char **c, int ret, va_list argptr);
//---------------TRATA--------------------//
int		nonmfw(char **c, int ret, va_list argptr, int mfw);
int		mfwpos(char **c, int ret, va_list argptr, int mfw);
int		tratamento(char *c, int ret, va_list argptr);
int		ft_printf(const char *c, ...);
#endif