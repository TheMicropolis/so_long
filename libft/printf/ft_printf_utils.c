/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:54:40 by mmauri            #+#    #+#             */
/*   Updated: 2024/10/23 13:54:43 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(char c, int *count)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*count)++;
	return (0);
}

int	ft_putunsigned(unsigned int nb, int *count)
{
	char	c;

	if (nb > 9)
		if (ft_putunsigned((nb / 10), count) == -1)
			return (-1);
	c = (nb % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	(*count)++;
	return (0);
}

int	ft_putnbr_base(unsigned long nb, char c, int *count)
{
	char			*base;
	unsigned int	len;
	char			a;

	len = 16;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= len)
	{
		if (ft_putnbr_base((nb / len), c, count) == -1)
			return (-1);
	}
	a = base[nb % len];
	if (ft_putchar(a, count) == -1)
		return (-1);
	return (0);
}

int	ft_putnbr(int nb, int *count)
{
	int	c;

	c = 0;
	if (nb == -2147483648)
	{
		return (ft_putstr_len("-2147483648", count));
	}
	if (nb < 0)
	{
		if (ft_putchar('-', count) == -1)
			return (-1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		if (ft_putnbr(nb / 10, count) == -1)
			return (-1);
	}
	c = (nb % 10) + '0';
	if (ft_putchar(c, count) == -1)
		return (-1);
	return (0);
}

int	ft_putstr_len(char *s, int *count)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		return (ft_putstr_len("(null)", count));
	}
	while (s[len])
	{
		if (ft_putchar(s[len], count) == -1)
			return (-1);
		len++;
	}
	return (len);
}
