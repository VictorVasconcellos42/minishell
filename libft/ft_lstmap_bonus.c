/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:46:35 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/11 01:10:57 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))

{
	t_list	*node;
	t_list	*head;
	t_list	*prev;

	head = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL && node->content == NULL)
		{
			ft_lstclear(&head, del);
			break ;
		}
		if (head == NULL)
			head = node;
		else
			prev->next = node;
		prev = node;
		lst = lst->next;
	}
	return (head);
}
