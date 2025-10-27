/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huda-roc <huda-roc@42student.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:06:37 by huda-roc          #+#    #+#             */
/*   Updated: 2025/10/27 15:08:36 by huda-roc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(unsigned long n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putptr(n / 16);
	}
	ft_putchar_fd(hex[n % 16], 1);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	n;
	int				len;

	n = (unsigned long)ptr;
	if (!ptr)
	{
		return (write(1, "(nil)", 5));
	}
	write(1, "0x", 2);
	len = 2;
	if (n == 0)
	{
		len += write(1, "0", 1);
	}
	else
	{
		ft_putptr(n);
		while (n)
		{
			n /= 16;
			len++;
		}
	}
	return (len);
}
