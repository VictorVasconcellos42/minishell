/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 08:13:37 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/06/09 09:46:53 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)

{
	t_list	*node;
	int		i;

	i = 0;
	if (!(lst))
		return (i);
	node = lst;
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}
