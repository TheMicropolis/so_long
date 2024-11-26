/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:16:24 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 14:29:43 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	ptr = (unsigned char *) dest;
	s = (const unsigned char *) src;
	while (n > 0)
	{
		ptr[i] = s[i];
		n--;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
int main()
{
    char str1[10] = "haus";
    char str2[10] = "mix";
    ft_memcpy(str1, str2, 1);
    printf("After memcpy, str1: %s\n", str1);

    return 0;
}*/
/*
//The memcpy() function copies n bytes from
//memory area src to memory area dest.  
//The memory areas must not overlap.  
//Use memmove(3) if the memory areas do overlap.
*/
