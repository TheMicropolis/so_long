/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:30:10 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 14:52:56 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = node;
	}
}
/*

// deletes node per node and saves info to next list
//ends when lst is NULL -> pints to NULL
 
#include <stdio.h>
#include <stdlib.h>

static void	del_content(void *content)
{
	free(content);
}

int main()
{
    char *a = "first";
    char *b = "last";

    t_list *first = ft_lstnew(a);
    t_list *second = ft_lstnew(b);
    ft_lstadd_back(&first, second);

    printf("List before:\n");
    while (first)
	{
        printf("%s\n", (char *)first->content);
		first = first->next;
	}
	ft_lstclear(&first, del_content);
	printf("After clearing: ");
    if (!first)
		printf("Cleared!");
    return (0);
}*/
