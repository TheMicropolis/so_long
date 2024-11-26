/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:37:17 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/04 10:21:26 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	num;

	num = 0;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = 1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10;
		num = num + (*str - 48);
		str++;
	}
	if (n == 1)
		return (-num);
	return (num);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 2)
	{	
		printf("my atoi: %i\n", ft_atoi(av[1]));
		printf("original: %i", atoi(av[1]));
	}
	return (0);
}

//transforms ascii to int 
*/
