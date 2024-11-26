/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:14:34 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 14:14:51 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
/*

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main()
{
	char *a = "first";
	char *b = "last";
	
	t_list *first = ft_lstnew(a);
	t_list *second = ft_lstnew(b);
	ft_lstadd_back(&first, second);
	
	ft_lstdelone(first, free); 

    printf("Last: ");
    if (first)
        printf("%s\n", (char *)first->content);

    // Free the list nodes
    t_list *temp = first;
    while (temp)
    {
        t_list *next_node = temp->next;
        free(temp);
        temp = next_node;
    }

    return 0;
}*/
