/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:58:25 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/11 17:05:19 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write (fd, "\n", 1);
}
/*
int main()
{
	char *str = "abc";
	char *str2 = "def";
	ft_putendl_fd(str, 1);
	ft_putendl_fd(str2, 1);
	return (0);
}
*/