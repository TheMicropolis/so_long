/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:15:49 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 14:17:30 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include <stdio.h>
int main()
{
  
   	char *content;
	content = "123456789";

	t_list *first = ft_lstnew(content);
    	
	printf("Linked List: ");
    	t_list* temp = first;	//temp list
  	while(first)
	{	
		printf("%s", (char *)first->content);
		temp = first->next;	//goes to next node, in this case NULL
		free(first);
		first = temp;
	}
	return 0;
}*/
