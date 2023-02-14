/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:32:11 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/18 05:04:07 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)

{
	size_t	i;
	size_t	j;
	char	*substring;

	substring = (char *) needle;
	i = 0;
	if (needle[i] == '\0')
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == substring[j] && i < len)
		{
			if (substring[j + 1] == '\0')
			{
				if (j + i >= len)
					return (NULL);
				return ((char *) &haystack[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
