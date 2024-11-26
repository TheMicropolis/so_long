/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:07:32 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 15:08:39 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	return (1 + ft_lstsize(lst->next));
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
  
   	char *a, *b;
	a = "1";
	b = "2";
	int n;

	t_list *first = ft_lstnew(b);
	t_list *second = ft_lstnew(a);
	ft_lstadd_front(&first, second);
	n = ft_lstsize(first);
    	
	printf("Size of List:%i\nList:", n);
    	t_list* temp = first;	//temp list
  	while(first)
	{	
		printf("%s", (char *)temp->content);
		temp = first->next;	//goes to next node, in this case NULL
		free(first);
		first = temp;
	}
	return 0;
}*/
