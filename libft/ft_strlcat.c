/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:32:30 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/24 02:06:41 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)

{
	size_t	len_dst;
	size_t	i;

	len_dst = 0;
	while (dst[len_dst] && len_dst < dstsize)
		len_dst++;
	if (len_dst == dstsize)
		return (ft_strlen(src) + len_dst);
	i = 0;
	while (src[i] && i < (dstsize - len_dst) - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + ft_strlen(src));
}
