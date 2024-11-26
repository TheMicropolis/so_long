/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:00:07 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 14:24:16 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = ft_strlen((char *)src);
	if (size == 0)
		return (len);
	else
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
/*
#include <stdio.h>
int main(void)
{
	char *src = "abc";
	char dest[4];
	printf("%zu", ft_strlcpy(dest, src, 4));
	return (0);
}

DESCRIPTION

Returns length of copied string = Len src

     The strlcpy() and strlcat() functions copy and concatenate 
	 strings respec‐
     tively.  They are designed to be safer, more consistent, 
	 and less error prone
     replacements for strncpy(3) and strncat(3).  Unlike those 
	 functions, strlcpy()
     and strlcat() take the full size of the buffer (not just 
	 the length) and guar‐
     antee to NUL-terminate the result (as long as size is larger 
	 than 0 or, in the
     case of strlcat(), as long as there is at least one byt
	 e free in dst).  Note
     that a byte for the NUL should be included in size.  Als
	 o note that strlcpy()
     and strlcat() only operate on true “C” strings.  This mean
	 s that for strlcpy()
     src must be NUL-terminated and for strlcat() both src and ds
	 t must be NUL-ter‐
     minated.

     The strlcpy() function copies up to size - 1 characters from
	 the NUL-terminated
     string src to dst, NUL-terminating the result */
