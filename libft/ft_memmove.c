/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 05:36:01 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/12 18:08:25 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)

{
	char	*source;
	char	*destiny;
	size_t	i;

	source = (char *) src;
	destiny = (char *) dst;
	if (len == 0 || source == destiny)
		return (dst);
	if (source > destiny)
	{
		i = 0;
		while (i < len)
		{
			destiny[i] = source[i];
			i++;
		}
		return (dst);
	}
	i = len - 1;
	while ((int) i >= 0)
	{
		destiny[i] = source[i];
		i--;
	}
	return (dst);
}
