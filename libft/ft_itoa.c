/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:59:16 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/11 17:35:50 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_len(int n)
{
	int	l;

	l = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		l++;
		n = -n;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		l;
	int		res;
	char	*str;

	l = ft_len(n);
	res = n;
	if (res == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	str[l] = '\0';
	if (res < 0)
		res = -res;
	while (l > 0)
	{
		l--;
		str[l] = (res % 10) + '0';
		res = res / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
int main()
{
        int n = 12;
        int x = -2147483648;
        int y = 0;
        char *str = ft_itoa(n);
        char *ptr = ft_itoa(x);
        char *str1 = ft_itoa(y);
        if (str)
        {
                puts(str);
                free(str);
        }
        if (ptr)
        {
                puts(ptr);
                free(ptr);
        }
        puts(str1);
        return (0);
}
*/
