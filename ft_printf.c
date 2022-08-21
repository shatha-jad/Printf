/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjadalla <sjadalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:52 by sjadalla          #+#    #+#             */
/*   Updated: 2022/03/08 14:26:43 by sjadalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	convs(va_list arg, char *str)
{
	int	t;

	t = 0;
	if (*str == 'c')
		t += ft_putchar(va_arg(arg, int));
	else if (*str == 's')
		t += ft_putstr(va_arg(arg, char *));
	else if (*str == 'i' || *str == 'd')
		t += ft_putnbr(va_arg(arg, int));
	else if (*str == 'u')
		t += ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (*str == 'x' || *str == 'X')
		t += ft_puthex(va_arg(arg, unsigned int), *str);
	else if (*str == 'p')
		t += ft_vpointer(va_arg(arg, unsigned long long));
	else if (*str == '%')
		t += ft_putchar('%');
	else
		t += ft_putchar(*str);
	return (t);
}

int	ft_printf(const char *format, ...)
{
	va_list			arg;
	char			*str;
	unsigned int	i;

	i = 0;
	va_start(arg, format);
	str = (char *)format;
	while (*str)
	{
		while (*str != '%' && *str)
			i += write(1, str++, 1);
		if (*str == '%')
		{
			str++;
			i += convs(arg, str++);
		}
	}
	va_end(arg);
	return (i);
}

// #include <stdio.h>
// //i #include "ft_printf.h"
// int main()
// {
// 	int a = 245;
// 	int b = 4357;
// 	int c = -2147483648;
// 	char *s1 = NULL;
// 	char *s2 = "ABCDEF";
// 	char *pointer1 = NULL;
// 	char *pointer2 = "AABBCC";
// 	// char c1 = '1';
// 	// char c2 = 'a';
// 	unsigned int u1 = 56756;
// 	int hex1 = 256;
// 	int hex2 = 7856892;
// 	int l1 = 0;
// 	int l2 = 0;
// 	l1 = ft_printf("integers and uint: %i %d %d %u\n", a, b, c, u1);
// 	l2 =	printf("integers and uint: %i %d %d %u\n", a, b, c, u1);
// 	printf("ft_printf length: %d\n", l1);
// 	printf(".  printf length: %d\n", l2);
// 	l1 = ft_printf("Strings: %s %s\n", s1, s2);
// 	l2 =	printf("Strings: %s %s\n", s1, s2);
// 	printf("ft_printf length: %d\n", l1);
// 	printf(".  printf length: %d\n", l2);
// 	l1 = ft_printf("Pointers: %p %p\n", pointer1, pointer2);
// 	l2 =	printf("Pointers: %p %p\n", pointer1, pointer2);
// 	printf("ft_printf length: %d\n", l1);
// 	printf(".  printf length: %d\n", l2);
// 	l1 = ft_printf("Hex: %x %x %X %X\n", hex1, hex2, hex1, hex2);
// 	l2 =	printf("Hex: %x %x %X %X\n", hex1, hex2, hex1, hex2);
// 	printf("ft_printf length: %d\n", l1);
// 	printf(".  printf length: %d\n", l2);
// 	l1 = ft_printf("Percent sign check: %%  %m\n");
// 	l2 =	printf("Percent sign check: %%  %m\n");
// 	printf("ft_printf length: %d\n", l1);
// 	printf(".  printf length: %d\n", l2);
// 	l1 = ft_printf("%i%d%u%p%s\n", a, b, c, s2, s1);
// 	l2 =	printf("%i%d%u%p%s\n", a, b, c, s2, s1);
// 	printf("ft_printf length: %d\n", l1);
// 	printf(".  printf length: %d\n", l2);
// 	return 0;
// }
