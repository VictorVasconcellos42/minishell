/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:29:03 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/18 04:04:18 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)

{
	size_t	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *) &s[len]);
	while (len-- > 0)
	{
		if (s[len] == (unsigned char) c)
			return ((char *) &s[len]);
	}
	return (NULL);
}

/* #include <string.h>
#include <stdio.h>

int main(void)

{
    char    *dest;
	char 	*origin;

	origin = strrchr("Victor", '0');
    dest = ft_strrchr("Victor", '0');
	puts(origin) ;
    puts(dest);
}
 */
