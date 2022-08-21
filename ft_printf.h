/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjadalla <sjadalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:59:32 by sjadalla          #+#    #+#             */
/*   Updated: 2022/03/08 13:59:38 by sjadalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	convs(va_list arg, char *str);
int	ft_putchar(char c);
int	ft_puthex(unsigned long long n, char format);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_vpointer(unsigned long long n);

#endif
