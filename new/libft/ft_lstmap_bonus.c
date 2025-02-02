/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:10:49 by mmauri            #+#    #+#             */
/*   Updated: 2024/09/20 17:08:38 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*a;

	if (!lst || !del || !f)
		return (NULL);
	new = NULL;
	node = NULL;
	while (lst)
	{
		a = f(lst->content);
		node = ft_lstnew(a);
		if (!node)
		{
			del(a);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
/*

//neuer knoten, wenn alloctaion failed del und clear
//sonst hinten dran an list und zum nächsten element


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	del_content(void *content)
{
	free(content);
}

void	*dup_content(void *content)
{
	return (strdup((char *)content));
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("Content: %s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *node3;

	node1 = ft_lstnew(ft_strdup("first"));
	node2 = ft_lstnew(ft_strdup("second"));
	node3 = ft_lstnew(ft_strdup("third"));
	node1->next = node2;
	node2->next = node3;
	t_list *new_list = ft_lstmap(node1, dup_content, del_content);
	if (new_list)
	{
		printf("Original list:\n");
		print_list(node1);
		printf("\nMapped list:\n");
		print_list(new_list);
	}
	else
		printf("ft_lstmap failed\n");
	ft_lstclear(&node1, del_content);
	ft_lstclear(&new_list, del_content);
	return (0);
}*/
