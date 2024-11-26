/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:11:47 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/19 15:58:46 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main(void)
{
    char a = 'a';
    char b = '/';
    int n = ft_isalnum((int)a);
    int m = ft_isalnum((int)b);
    printf("Is alnum ! (1) %i\n", n);
    printf("Is not alnum ! (0) %i", m);
    return (0);
}*/
