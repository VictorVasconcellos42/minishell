/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:26:05 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/26 18:48:13 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(int n)

{
	int	count_chars;

	if (n < 0)
	{
		n *= -1;
		count_chars = 1;
	}
	else
		count_chars = 0;
	while (n > 9)
	{
		count_chars++;
		n = n / 10;
	}
	if (n > 0 || n == 0)
		count_chars++;
	return (count_chars);
}

char	*ft_itoa(int n)

{
	int		count_chars;
	int		temp_n;
	char	*string;

	if (n == -2147483648)
		temp_n = -2147483647;
	else
		temp_n = n;
	count_chars = digits(temp_n);
	string = ft_calloc(count_chars + 1, sizeof(char));
	if (temp_n < 0)
		temp_n *= -1;
	if (!(string))
		return (NULL);
	while (count_chars)
	{
		string[count_chars - 1] = (temp_n % 10) + 48;
		temp_n = temp_n / 10;
		count_chars--;
	}
	if (n < 0)
		string[0] = '-';
	if (n == -2147483648)
		string[ft_strlen(string) - 1] = '8';
	return (string);
}

/*#include <stdio.h>

int	main(void)

{
	int		n = -623;
	char	*test;

	test = ft_itoa(n);
	puts(test);
	return 0;
}*/
