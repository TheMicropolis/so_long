/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:31:34 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/19 16:13:13 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n-- > 0)
	{
		*str = '\0';
		str++;
	}
}
/*
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int i;

	char str[] = "123456789";
	i = 0;
	ft_bzero(str, 3);
	while (i < 9)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

//  The bzero() function writes n zeroed bytes to the string s.  If n is
     zero, bzero() does nothing.
*/
