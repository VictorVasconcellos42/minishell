/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 07:39:26 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/16 10:27:56 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	unsigned char	*string;

	string = (unsigned char *) s;
	while (n-- > 0)
	{
		if (*string == (unsigned char) c)
			return (string);
		string += 1;
	}
	return (NULL);
}

/* #include <stdio.h>

void	test(const void *s, int c, size_t n)

{	
	char	*string;
	char	*string_og;
	char	*test_og;
	char	*test;

	string = (char *) s;
	string_og = (char *) s;
	test = ft_memchr(s, c, n);
	test_og = memchr(s, c, n);
	puts(string);
	puts(string_og);
	printf("valor de size %zu\n", n);
    puts(test);
	puts(test_og);
	printf("\n");
}

int main(void)

{
	test("Victor", 't', 6);
	test("Marlon", 'l', 3);
	test("Victor", 'i', 2);
	test("Victor", 't', 3);
	test("Pinna", 'n', 3);
	test("Gabriela", 'l', 5);
	test("Pedro", 'l', 6);
	test("Marcio", 'c', 3);
	test("Tohru", 'r', 4);
	test("Alexandra", 'a', 5);
	test("Marlon", 'n', 3);
	return (0);
} */
