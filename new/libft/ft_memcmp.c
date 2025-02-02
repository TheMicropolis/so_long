/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:56:45 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 15:05:51 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n && str1[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int res;
	int res2;
	size_t n;
	
	if (argc == 4)
	{
		n = atoi(argv[3]);
		res = ft_memcmp(argv[1], argv[2], n);
        printf("my function: %d", res);
		res2 = memcmp(argv[1], argv[2], n);
		printf("\nlibrary function: %d", res2);
	}
	else
		printf("Put in 3 arguments : s1, s2 and bytes you want to compare.");
    return (0);
}*/
