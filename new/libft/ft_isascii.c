/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:16:48 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/19 16:04:22 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main(void)
{
    char a = 'a';
    int b = 300;
    int n = ft_isascii((int)a);
    int m = ft_isascii((int)b);
    printf("Is ascii ! (1) %i\n", n);
    printf("Is not ascii ! (0) %i", m);
    return (0);
}*/
