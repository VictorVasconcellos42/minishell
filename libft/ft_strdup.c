/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:04:29 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/10 16:18:56 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)

{
	char	*string;
	size_t	len;
	char	*dest;
	size_t	i;

	i = 0;
	string = (char *) s1;
	len = ft_strlen(s1);
	dest = (char *) malloc (len + 1);
	if (!(dest))
		return (NULL);
	while (string[i])
	{
		dest[i] = string[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)

{
	char	string[] = "ROBERTINHO";
	char	string2[] = "ROBERTINHO";
	char	*result;
	char	*origin;

	origin = strdup(string2);
	result = ft_strdup(string);
	if	(ft_memcmp(origin, result, 10) == 0)
		printf("OK VICTOR\n");
	else
		printf("TEMOS UM 2319!!!\n");
	printf("%zu\n", ft_strlen(result));
	printf("%zu\n", ft_strlen(origin));
	puts(result);
	puts(origin);
	free(result);
	free(origin);
	return 0;
} */
