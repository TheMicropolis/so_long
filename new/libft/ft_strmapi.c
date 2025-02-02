/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:40:44 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/19 15:41:20 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = ft_strlen((char *)s);
	str = (char *)malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < l)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	ft_up(unsigned int i, char c)
{
	(void) i;
	if (c >= 'a' && c <= 'z')
        	c = c - 32;
	return (c);
}

#include <stdio.h>	
int main()
{
	char *s1 = "abcde";
	char *s2 = ft_strmapi(s1, ft_up);
	if (s2)
	{	
		puts(s2);
		free(s2);
	}
	return (0);
}*/
