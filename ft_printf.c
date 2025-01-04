/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:07:15 by marleand          #+#    #+#             */
/*   Updated: 2025/01/04 19:34:09 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(const char *str, va_list args)
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
	if (*str == 'x')
		return (ft_hexa(0, va_arg(args, unsigned int), "0123456789abcdef"));
	if (*str == 'X')
		return (ft_hexa(0, va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (*str == 'p')
		return (ft_hexa(1, va_arg(args, unsigned long), "0123456789abcdef"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!str)
	{
		return (-1);
	}
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

/* #include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
    int     len1, len2;
    char    c = 'A';
    char    *str = "Hello, 42!";
    int     num = -12345;
    unsigned int u_num = 4294967295;
    unsigned int hex = 255;
    void    *ptr = &num;

    //Character
    len1 = ft_printf("Character: %c\n", c);
    len2 = printf("Character: %c\n", c);
    printf("ft_printf len = %d\nprintf len = %d\n\n", len1, len2);

    //String
    len1 = ft_printf("String: %s\n", str);
    len2 = printf("String: %s\n", str);
    printf("ft_printf len = %d\nprintf len = %d\n\n", len1, len2);

    //Signed Decimal
    len1 = ft_printf("Decimal: %d\n", num);
    len2 = printf("Decimal: %d\n", num);
    printf("ft_printf len = %d\nprintf len = %d\n\n", len1, len2);

    //Unsigned Integer
    len1 = ft_printf("Unsigned: %u\n", u_num);
    len2 = printf("Unsigned: %u\n", u_num);
    printf("ft_printf len = %d\nprintf len = %d\n\n", len1, len2);

    //Lowercase Hexadecimal
    len1 = ft_printf("Hex lowercase: %x\n", hex);
    len2 = printf("Hex lowercase: %x\n", hex);
    printf("ft_printf len = %d\nprintf len = %d\n\n", len1, len2);

    //Uppercase Hexadecimal
    len1 = ft_printf("Hex uppercase: %X\n", hex);
    len2 = printf("Hex uppercase: %X\n", hex);
    printf("ft_printf len = %d\nprintf len = %d\n\n", len1, len2);

    //Pointer Address
    len1 = ft_printf("Pointer: %p\n", ptr);
    len2 = printf("Pointer: %p\n", ptr);
    printf("ft_printf len = %d\nprintf len = %d\n\n", len1, len2);

    //Percent
    len1 = ft_printf("Percent: %%\n");
    len2 = printf("Percent: %%\n");
    printf("ft_printf len = %d\nprintf len = %d\n\n", len1, len2);

    return (0);
}

int	main(void)
{
	ft_printf("%d \n", ft_printf("ola%%%"));
	//printf("%d \n", printf("ola%%"));
 
	int teste = printf("hello world\n");
	printf("imprimiu: %d\n", teste);
	int teste2 = ft_printf("hello world\n");
	ft_printf("imprimiu: %d\n", teste2);
	printf("\n");
	int x = 42;
	int x2 = 34;
	void *ptrx2 = &x2;
	void *ptr = &x;

	
	ft_printf("HELLO\n");
	ft_printf("%d \n", ft_printf(""));
	ft_printf("%d \n", ft_printf(NULL));
	ft_printf("CHARACTERS: %c %c\n", 'a', 'b');
	ft_printf("STRINGS: %s %s\n", "Good", "bye");
	ft_printf("DECIMAL: %i %d\n", 42, 123);
	ft_printf ("DECIMALS: %d %d\n", 1977, 650000L);
    ft_printf("POINTER NULO: %p \n", NULL );
	printf("valor :%d\n", ft_printf("POINTER DE x é: %p\n", ptr));
	ft_printf("POINTER 0: %p %p \n", (void *)0, (void *)0);
	ft_printf ("DECIMAL e HEXADECIMAL: %d %x %X \n", 255, 255, 255);
	ft_printf ("HEXADECIMAL 0: %x %X\n", 0, 0);
	ft_printf ("Unsigned int: %u %u\n",  2147483647, UINT_MAX);
	ft_printf ("Unsigned int: %u \n", UINT_MAX);
	ft_printf ("Mix: %c, %s, %p, %d, %i, %x, %X, %u, %%, all mixed\n", 'A',
		"Mix", ptrx2, 34, 34, 255, 255, UINT_MAX);


 	ft_printf("\n");
	
	printf("Hello\n");
	//printf("%d \n", printf(""));
	//printf("%d \n", printf(NULL));
	printf("Characters: %c %c\n", 'a', 'b');
	printf("Strings: %s %s\n", "Good", "bye");
	printf("Decimal: %d %d\n", 42, 123);
	printf ("Decimals: %d %ld\n", 1977, 650000L);
	printf("Pointer nulo: %p \n", NULL );
	printf("Pointer de x é: %p\n", ptr);
	printf("Pointer 0: %p %p \n", (void *)0, (void *)0);
	printf ("Decimal e hexadecimal: %d %x %X \n", 255, 255, 255);
	printf (" Hexadecimal 0: %x %X\n", 0, 0);
	printf ("Unsigned int: %u %u\n", 2147483647, UINT_MAX);
	printf ("Unsigned int: %u \n", UINT_MAX);
	printf ("Mix: %c, %s, %p, %d, %i, %x, %X, %u, %%, all mixed\n", 'A', "Mix",
		ptrx2, 34, 34, 255, 255, UINT_MAX);
	return (0); 
} */