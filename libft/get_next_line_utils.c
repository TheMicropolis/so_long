#include "get_next_line.h"

/*int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}*/
/*
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));

	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}
*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
i	return (dest);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	unsigned int	l;

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
	ft_strcpy(sub, s + start);
	return (sub);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	
	if (!s)  // Falls der String NULL ist
	        return (NULL);
	len = ft_strlen((char *)s);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, s);
	return (dup);
}


