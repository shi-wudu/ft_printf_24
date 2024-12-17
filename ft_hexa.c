/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-11 17:16:55 by marleand          #+#    #+#             */
/*   Updated: 2024-12-11 17:16:55 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hexa(unsigned long long n, char *base)
{
	char buffer[16];
	int count;
	int i;

	count = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar(base[0]));
	
	while(n > 0)
	{
		buffer[i++] = base [n % 16];
		n /= 16;
	}

	while (--i >= 0)
		count += ft_putchar(buffer[i]);
	return (count);
}