/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:30:47 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/11 16:48:35 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen((char *)s);
	if (start >= l)
		return (ft_strdup(""));
	if (len > l - start)
		len = l - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
/*
#include <stdio.h>
int main()
{
	char const *str;
	str = "12345";
	char *sub = ft_substr(str, 1, 3);
	if (sub)
	{	
		puts(sub);
		free(sub);
	}
	return (0);
}*/
