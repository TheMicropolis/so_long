/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:08:07 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 16:08:18 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*

//new zeigt auf 1. element von lst
//dann wird der Zeiger aufs erste Element von list
//auf next gesetzt denn dies ist nun 1. elem.

#include <stdio.h>
#include <stdlib.h>
int main()
{
  
   	char *content;
	char *content2;
	t_list *new;
	t_list *first;

	content = "123456789";
	content2 = "0";
	
	first = ft_lstnew(content);
	new = ft_lstnew(content2);

	ft_lstadd_front(&first, new); 
    	
	printf("Linked List: ");
    	t_list* list = first;
  	while(list)
	{	
		printf("%s", (char *)list->content);
		list = list->next;	//goes to next node
	}
	list = first;
	while (list)
	{
		t_list *temp = list->next;
		free(list);
		list = temp;
	}
	return 0;
}*/
