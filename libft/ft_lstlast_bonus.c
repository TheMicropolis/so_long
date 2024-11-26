/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:06:27 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 15:07:07 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*pos;

	pos = lst;
	if (!pos)
		return (NULL);
	while (pos->next != NULL)
		pos = pos->next;
	return (pos);
}
/*

// goes on until next Position is at NULL
// then returns last node before NULL


#include <stdio.h>
#include <stdlib.h>
int main()
{

        char *a, *b;
        a = "first";
        b = "last";

        t_list *first = ft_lstnew(b);
        t_list *second = ft_lstnew(a);
        ft_lstadd_front(&first, second);

	t_list *last = ft_lstlast(first);

        printf("Last:");
        t_list* temp = last;
        if(last)
		printf("%s", (char *)last->content);
        temp = first;
	while (temp)
	{
		t_list* next_n = temp->next;
                free(temp);
                temp = next_n;
        }
        return 0;
}*/
