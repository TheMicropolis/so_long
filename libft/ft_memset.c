/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:40:37 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/19 16:10:20 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	while (n > 0)
	{
		ptr[i] = (unsigned char) c;
		n--;
		i++;
	}
	return (s);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char str[9] = "abc";
	char str2[9] = "abc";
	int c = 49;

	ft_memset(str, c, 2);
       	printf("My memset: %s\n", str);
	memset(str2, c, 2);
	printf("Original: %s", str2);	
	return (0);
}
//The memset() function fills the first n bytes of the memory area pointed
//to by s with the constant byte c
*/
