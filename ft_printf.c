/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:07:15 by marleand          #+#    #+#             */
/*   Updated: 2024/12/11 17:02:52 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int check(const char *str, va_list args)
{
	if (*str == '%')
		return (ft_putchar(*str));
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*str == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (*str == 'u')
		return (ft_putunsign(va_arg(args, unsigned int)));
/* 	if (*str == 'x')
		return (ft_hx(???));
	if (*str == 'X')
		return (ft_hx(???));
	else if(*str == 'p')
		return(ft_putstr("0x") + ) */
	else
		return (0);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int		count;

	count = 0;
    va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += check(str, args);
		}
		else
		{
			ft_putchar(*str);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}