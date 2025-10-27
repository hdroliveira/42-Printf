/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huda-roc <huda-roc@42student.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:43:04 by huda-roc          #+#    #+#             */
/*   Updated: 2025/10/27 14:48:44 by huda-roc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	ft_puthex(unsigned int n, int uppercase)
{
	char	*hex;

	if (uppercase)
	{
		hex = "0123456789ABCDEF";
	}
	else
	{
		hex = "0123456789abcdef";
	}
	if (n >= 16)
	{
		ft_puthex(n / 16, uppercase);
	}
	ft_putchar_fd(hex[n % 16], 1);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	int	len;

	len = ft_hex_len(n);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
	}
	else
	{
		ft_puthex(n, uppercase);
	}
	return (len);
}
