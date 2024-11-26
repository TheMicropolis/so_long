/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:08:44 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 15:10:10 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l;

	j = 0;
	i = ft_strlen(dst);
	l = ft_strlen((char *)src);
	if (size <= i)
		return (size + l);
	j = 0;
	while (src[j] != '\0' && (i + j) < (size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	if ((i + j) < size)
		dst[i + j] = '\0';
	return (i + l);
}
/*

#include <stdio.h>

int	main(void)
{
	char *a = "abc";
	char *b = "def";
	printf("The strings length is: %zu", ft_strlcat(a, b, 2));
	return (0);
}*/

/* DESCRIPTION

strlcat() functions return the total
     length of the string they tried to create.

     The strlcpy() and strlcat() functions copy and 
	 concatenate strings respec‐
     tively.  They are designed to be safer, more
	 consistent, and less error prone
     replacements for strncpy(3) and strncat(3).
   	 Unlike those functions, strlcpy()
     and strlcat() take the full size of the buffer 
	 (not just the length) and guar‐
     antee to NUL-terminate the result (as long as size is 
	 larger than 0 or, in the
     case of strlcat(), as long as there is at least on
	 e byte free in dst).  Note
     that a byte for the NUL should be included in size. 
	 Also note that strlcpy()
     and strlcat() only operate on true “C” strings. 
	 This means for strlcat() both 
	 src and dst must be NUL-terminated.

     The strlcat() function appends the NUL-terminated 
	 string src to the end of dst.
     It will append at most size - strlen(dst) - 1 bytes,
	 NUL-terminating the re‐
     sult.
*/
