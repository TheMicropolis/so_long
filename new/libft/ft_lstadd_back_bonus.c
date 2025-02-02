/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:30:56 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/19 16:34:20 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pos;

	if (!new)
		return ;
	if (! *lst)
	{
		*lst = new;
		return ;
	}
	pos = ft_lstlast(*lst);
	pos->next = new;
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{

        char *a, *b;
        a = "first";
        b = "second";

        t_list *first = ft_lstnew(a);
        t_list *second = ft_lstnew(b);
        ft_lstadd_back(&first, second);

	t_list *last = ft_lstlast(first);

        printf("Last:");
        t_list* temp;
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
