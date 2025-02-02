/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:06:37 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/19 16:04:39 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
/*

#include <stdio.h>
int main(void)
{
    char a = 'a';
    char b = '1';
    int n = ft_isdigit((int)a);
    int m = ft_isdigit((int)b);
    printf("Is not digit (0) %i\n", n);
    printf("Is digit (1) %i", m);
    return (0);
}*/
