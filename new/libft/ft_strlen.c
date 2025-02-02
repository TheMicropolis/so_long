/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:39:14 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/19 16:08:37 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str;
	int a;

	str = "";
	a = ft_strlen(str);	
	printf("%i\n", a);
	return(0);
}*/
