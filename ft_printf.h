/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:39:47 by marleand          #+#    #+#             */
/*   Updated: 2025/01/04 13:59:14 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_hexa(unsigned long long n, char *base);
int		ft_putunsign(unsigned int n);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);
size_t	ft_strlen(const char *s);

#endif