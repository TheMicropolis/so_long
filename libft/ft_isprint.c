/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:23:59 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/19 16:07:14 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main(void)
{
    char a = 'a';
    int b = 127;
    int n = ft_isprint((int)a);
    int m = ft_isprint((int)b);
    printf("Is print ! (1) %i\n", n);
    printf("Is not ! (0) %i", m);
    return (0);
}*/
