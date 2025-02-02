/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:52:55 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/19 15:51:55 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char a = 'a';
	char b = '1';
	int n = ft_isalpha((int)a);
	int m = ft_isalpha((int)b);
	printf("Is alpha ! (1) %i\n", n);
	printf("Is not alpha ! (0) %i", m);
	return (0);
}*/
