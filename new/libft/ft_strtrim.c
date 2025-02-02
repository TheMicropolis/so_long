/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:27:20 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 15:03:11 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	l;

	i = 0;
	if (!s1)
		return (NULL);
	l = ft_strlen((char *)s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (l > i && ft_strchr(set, s1[l - 1]))
		l--;
	return (ft_substr(s1, i, (l - i)));
}
/*
#include <stdlib.h> 
int main()
{
	char *a = "  123 ";
	char *b = "";
	char *c = "	";
	char *d = "a a a a 123 a a ";
	char *at, *bt, *ct, *dt;
	char *set = "	";
	
	at = ft_strtrim(a, set);
	if (at)
	{	
		puts(at);
		free(at);
	}
	bt = ft_strtrim(b, set);
	if (bt)
        {
                puts(bt);
                free(bt);
        }	
	ct = ft_strtrim(c, set);
        if (ct)
        {
                puts(ct);
                free(ct);
        }
	dt = ft_strtrim(d, set);
        if (dt)
        {
                puts(dt);
                free(dt);
        }
	return(0);
}*/
