/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huda-roc <huda-roc@42student.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:33:00 by huda-roc          #+#    #+#             */
/*   Updated: 2025/10/27 14:39:07 by huda-roc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunsigned(n / 10);
	}
	write (1, &"0123456789"[n % 10], 1);
	count++;
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	return (ft_putunsigned(n));
}
