/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:35:07 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 14:22:48 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr;
	char	*s;
	size_t	i;

	i = 0;
	ptr = (char *) dest;
	s = (char *) src;
	if (!dest && !src)
		return (NULL);
	if (ptr < s || ptr >= s + n)
		ft_memcpy(ptr, s, n);
	else
	{
		i = n;
		while (i > 0)
		{
			ptr[i - 1] = s[i - 1];
			i--;
		}
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	str1[] = "Hello";
	const char	str2[] = "World";
	char		s1[42];
	char		s2[42];

	ft_memmove(s1, str1, 7);
	memmove(s2, str2, 7);
	puts(s1);
	puts(s2);
	return (0);
}
*/
/*DESCRIPTION
       The  memmove()  function  copies n bytes from memory 
	   area src to memory area dest.  The memory
       areas may overlap: copying takes place as though the bytes 
	   in src are first copied into a tem‐
       porary  array that does not overlap src or dest, and the 
	   bytes are then copied from the tempo‐
       rary array to dest.*/
