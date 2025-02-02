/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:03:40 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 15:04:28 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*	
void	ft_up(unsigned int i, char *c)
{
        (void) i;
        if (*c >= 'a' && *c <= 'z')
                *c = *c - 32;
}

#include <stdio.h>
int main()
{
        char s1[5] = "abcde";
        ft_striteri(s1, ft_up);
        puts(s1);
        return (0);
}	
*/
