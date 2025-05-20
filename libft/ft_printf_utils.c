/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:12:36 by bizcru            #+#    #+#             */
/*   Updated: 2024/12/12 17:33:44 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_char(va_list *args)
{
	char	c;

	c = (char) va_arg(*args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf_dec(va_list *args)
{
	int		i;
	char	*dec;
	int		rtrn;

	i = va_arg(*args, int);
	dec = ft_itoa(i);
	rtrn = ft_putstr_fd(dec, 1);
	free(dec);
	return (rtrn);
}

int	ft_printf_unsigned(va_list *args)
{
	int		i;
	char	*dec;
	int		rtrn;

	i = va_arg(*args, unsigned int);
	dec = ft_itoa_u(i);
	rtrn = ft_putstr_fd(dec, 1);
	free(dec);
	return (rtrn);
}

int	ft_printf_hex(va_list *args, char type)
{
	unsigned int	i;
	int				rtrn;
	char			*base;

	base = NULL;
	i = va_arg(*args, unsigned int);
	if (type == 'x' )
		base = ft_strdup("0123456789abcdef");
	else if (type == 'X')
		base = ft_strdup("0123456789ABCDEF");
	rtrn = ft_putnbr_base_u(i, base);
	free(base);
	base = NULL;
	return (rtrn);
}

int	ft_printf_ptr(va_list *args)
{
	unsigned long	ptr;
	int				rtrn;
	char			*base;

	ptr = (unsigned long) va_arg(*args, void *);
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	rtrn = 2;
	base = ft_strdup("0123456789abcdef");
	rtrn += ft_putnbr_base_u(ptr, base);
	free(base);
	return (rtrn);
}
