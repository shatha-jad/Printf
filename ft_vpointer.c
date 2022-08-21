/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjadalla <sjadalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:59:54 by sjadalla          #+#    #+#             */
/*   Updated: 2022/03/08 13:59:56 by sjadalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vpointer(unsigned long long n)
{
	int	i;

	i = 2;
	write(1, "0x", i);
	i += ft_puthex(n, 'x');
	return (i);
}
