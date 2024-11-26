/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:56:08 by mmauri            #+#    #+#             */
/*   Updated: 2024/10/23 15:17:05 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_put_ptr(void *ptr, int *count)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	if (ptr == 0)
		return (*count += write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	*count += 2;
	return (ft_putnbr_base(address, 'x', count));
}

static int	ft_specify(char format, va_list args, int *count)
{
	int	ret;

	ret = -1;
	if (format == 'c')
		ret = (ft_putchar(va_arg(args, int), count));
	else if (format == 's')
		ret = ft_putstr_len(va_arg(args, char *), count);
	else if (format == 'p')
		ret = (ft_put_ptr(va_arg(args, void *), count));
	else if (format == 'd' || format == 'i')
		ret = (ft_putnbr(va_arg(args, int), count));
	else if (format == 'u')
		ret = (ft_putunsigned(va_arg(args, unsigned int), count));
	else if (format == 'x' || format == 'X')
		ret = (ft_putnbr_base(va_arg(args, unsigned int), format, count));
	else if (format == '%')
		ret = (ft_putchar('%', count));
	return (ret);
}

static int	ft_format(const char **format, va_list args, int *count)
{
	int	ret;

	ret = 0;
	if (**format != '%')
		ret = ft_putchar(**format, count);
	else
	{
		(*format)++;
		if (**format && ft_strchr("cspdiuxX%", **format))
			ret = ft_specify(**format, args, count);
		else if (!**format)
			return (0);
		else
			ret = ft_putchar(**format, count);
	}
	(*format)++;
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		ret = ft_format(&format, args, &count);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
int main(void)
{
	int n, m, i;
	
	i = -2147483648;
	m = printf("%% %i\n", i);
	n = ft_printf("%% %i\n", i);
	printf("%i\n", m);
	printf("%i\n", n);

	m = printf("%s", "Hallo, test!\n");
        n = ft_printf("%s", "Hallo, test!\n");
        printf("%i\n", m);
        printf("%i\n", n);

	m = printf("%X%x\n", 42, 42);
        n = ft_printf("%X%x\n", 42, 42);
        printf("%i\n", m);
        printf("%i\n", n);

	m = printf("\n");
        n = ft_printf("\n");
        printf("%i\n", m);
        printf("%i\n", n);

	m = printf("%p\n", NULL);
        n = ft_printf("%p\n", NULL);
        printf("%i\n", m);
        printf("%i\n", n);

	m = printf(NULL);
    n = ft_printf(NULL);
        printf("%i\n", m);
       printf("%i\n", n);
	
	 return (0);
}*/
/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
			• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.*/
