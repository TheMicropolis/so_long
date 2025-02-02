/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:39:27 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/11 19:00:24 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;

	len = ft_strlen((char *)s);
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, (len + 1));
	return (dup);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*a;
	
	a = ft_strdup("123");
	if (a != NULL)
	{
		printf("%s", a);
		free(a);
	}
	else
		printf("allocation failed!");
	return (0);
}*/
