/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:11:25 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/24 13:17:50 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count(char *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		while (*s != c && *s)
			s++;
		n++;
	}
	return (n);
}

static char	*ft_word(const char *s, char c, int *i)
{
	int		start;
	int		l;
	char	*sub;

	start = *i;
	while (s[*i] != c && s[*i])
		(*i)++;
	l = *i - start;
	if (l <= 0)
		return (NULL);
	sub = ft_substr(s, start, l);
	if (!sub)
		return (NULL);
	return (sub);
}

static char	**ft_free(char **str, int j)
{
	while (j--)
		free(str[j]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char **)s;
	if (!s)
		return (NULL);
	str = (char **)malloc((ft_count((char *)s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		str[j] = ft_word(s, c, &i);
		if (!str[j])
			return (ft_free(str, j));
		j++;
	}
	str[j] = NULL;
	return (str);
}
/*
#include <stdio.h>
int main()
{
    char *str = " aa  bbb";
    char **words = ft_split(str, 48);
    int i = 0;
    
    while (i < 2)
    {
        puts(words[i]);
        free(words[i]);
        i++;
    }
    return 0;
}*/
