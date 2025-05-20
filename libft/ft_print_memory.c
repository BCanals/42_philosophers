/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:39:05 by bcanals-          #+#    #+#             */
/*   Updated: 2024/10/18 16:30:52 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_addr(unsigned long addr, char *hex)
{
	int	i;
	int	r;

	i = 15;
	while (i >= 0 && addr > 0)
	{
		r = addr % 16;
		if (r >= 10)
			hex[i] = r + 'a' - 10;
		else
			hex[i] = r + '0';
		i--;
		addr /= 16;
	}
	while (i >= 0)
	{
		hex[i] = '0';
		i--;
	}
	write(1, hex, 16);
	write(1, ": ", 2);
}

static void	ft_write_char_hex(char c)
{
	char			t;
	char			u;
	unsigned char	str;

	str = c;
	t = str / 16;
	u = str % 16;
	if (t >= 10)
		t = t + 'a' - 10;
	else
		t = t + '0';
	if (u >= 10)
		u = u + 'a' - 10;
	else
		u = u + '0';
	write(1, &t, 1);
	write(1, &u, 1);
}

static void	ft_write_char(char *ad_char, unsigned int i, unsigned int size)
{
	int		j;
	char	c;

	j = 0;
	while (j < 16 && (i + j) < size)
	{
		c = ad_char[j];
		if (c < 32 || c > 126)
			write(1, ".", 1);
		else
			write(1, &c, 1);
		j++;
	}
}

static void	ft_write_cont_hex(char *ad_char, unsigned int i, unsigned int size)
{
	int	j;

	j = 0;
	while (j < 16)
	{
		if (i < size)
			ft_write_char_hex(ad_char[i]);
		else
			write(1, "  ", 2);
		if ((j % 2) == 1)
			write(1, " ", 1);
		j++;
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			hex[16];
	unsigned int	i;
	char			*ad_char;

	ad_char = addr;
	i = 0;
	while (i < size)
	{
		ft_write_addr((unsigned long)addr + i, &hex[0]);
		ft_write_cont_hex(ad_char, i, size);
		ft_write_char(&ad_char[i], i, size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
/*
int	main(void)
{
	char a[] = "abcdefghijklmnopqrstuvwzyz\20\0";
	void *addr = &a[0];
	
	ft_print_memory(addr, 17);
}*/
