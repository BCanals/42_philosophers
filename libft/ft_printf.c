/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:26:08 by bizcru            #+#    #+#             */
/*   Updated: 2024/10/18 15:34:44 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_string(va_list *args)
{
	char	*string;

	string = va_arg(*args, char *);
	if (!string)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(string, 1);
	return (ft_strlen(string));
}

static int	ft_print_arg(char type, va_list *args)
{
	if (type == 's')
		return (ft_printf_string(args));
	else if (type == 'c')
		return (ft_printf_char(args));
	else if (type == 'i' || type == 'd')
		return (ft_printf_dec(args));
	else if (type == 'u')
		return (ft_printf_unsigned(args));
	else if (type == 'x' || type == 'X')
		return (ft_printf_hex(args, type));
	else if (type == 'p')
		return (ft_printf_ptr(args));
	else if (type == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		rtrn;

	rtrn = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			rtrn += ft_print_arg(format[i], &args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			rtrn++;
		}
		i++;
	}
	va_end(args);
	return (rtrn);
}
