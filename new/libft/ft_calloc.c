/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:02:15 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 18:31:08 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		if (ptr)
			ft_bzero(ptr, 1);
		return (ptr);
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * nmemb));
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*ptr;

	ptr = ft_calloc(5, sizeof(char));
	if (!ptr)
	{
		printf("memory allocation failed!\n");
		return (1);
	}
	ft_strlcpy(ptr, "test", 5);
	puts(ptr);
	free(ptr);
	ptr = calloc(5, 0);
	if (!ptr)
	{
		printf("memory allocation failed!\n");
		return (1);
	}
	puts(ptr);
	free(ptr);
	return (0);
}

// The calloc() function contiguously allocates enough space for count
     objects that are size bytes of memory each and returns a pointer to the
     allocated memory.  The allocated memory is filled with bytes of value
     zero
*/
