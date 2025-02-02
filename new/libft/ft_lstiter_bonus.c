/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:25:12 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 14:25:53 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*

void	ft_str_toupper(void *content)
{
    char *str = (char *)content;
    while (*str)
    {
        *str = ft_toupper(*str);
        str++;
    }
}

#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char *str1 = ft_strdup("a");
	char *str2 = ft_strdup("b");
	
	t_list *a = ft_lstnew(str1);
	t_list *b = ft_lstnew(str2);
	t_list *temp;

	ft_lstadd_back(&a, b);
	ft_lstiter(a, ft_str_toupper);
	
	printf("Linked List: ");
        temp = a;
	while(temp)
         {
                 printf("%s", (char *)temp->content);
                 temp = temp->next;      //goes to next node
         }       
         while (a)
         {
                t_list *temp = a->next;
                free(a->content);
		free(a);
		a = temp;
         }       
	return 0;
}*/
