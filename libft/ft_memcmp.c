/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:59:02 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/10 08:59:03 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)

{
	unsigned char	*string_one;
	unsigned char	*string_two;
	int				diff;
	size_t			i;

	string_one = (unsigned char *) s1;
	string_two = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		diff = string_one[i] - string_two[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)

{
	char	string[] = "A";
	char	string2[] = "AAAA";
	int		result;

	result = memcmp(string, string2, 4);
	printf("Diferença entre os caracteres: %d\n", result);
	result = ft_memcmp(string, string2, 4);
	printf("Diferença entre os caracteres: %d\n", result);
	return 0;

}*/
