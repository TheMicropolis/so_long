/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:02:35 by mmauri            #+#    #+#             */
/*   Updated: 2024/10/23 19:02:38 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
	{
		if (!s1)
			s3 = ft_strdup_gnl(s2);
		else
			s3 = ft_strdup_gnl(s1);
		if (!s3)
			return (NULL);
		return (s3);
	}
	s3 = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	str = s3;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (s3);
}

char	*ft_strcpy_gnl(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup_gnl(char *s)
{
	char	*dup;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen_gnl((char *)s);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strcpy_gnl(dup, s);
	return (dup);
}

char	*ft_strchr_gnl(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
