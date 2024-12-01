/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhelp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:32:19 by marleand          #+#    #+#             */
/*   Updated: 2024/12/01 15:43:08 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	while (*s)
		write(1, s++, 1);
}
void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putunsign(unsigned int n)
{
	int	len;

	len = 1;
	if (n > 9)
		len += ft_putunsign(n / 10);
	ft_putchar((n % 10) + '0');
	return (len);
}