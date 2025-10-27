/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huda-roc <huda-roc@42student.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:15:36 by huda-roc          #+#    #+#             */
/*   Updated: 2025/10/27 14:57:26 by huda-roc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handler(char spec, va_list args)
{
	if (spec == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (spec == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (spec == '%')
		return (ft_print_percent());
	if (spec == 'd' || spec == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (spec == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (spec == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	if (spec == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	if (spec == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handler(format[i], args);
			i++;
		}
		else
		{
			write (1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
