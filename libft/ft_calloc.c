/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:57:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/16 16:53:06 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)

{
	void	*allocate;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	size *= count;
	allocate = malloc(size * sizeof(char));
	if (!(allocate))
		return (NULL);
	ft_bzero(allocate, (size));
	return (allocate);
}
