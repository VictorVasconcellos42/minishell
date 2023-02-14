/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:12:03 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/06 13:18:33 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)

{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void)

{
	unsigned char	c;
	
	c = 122;

	if (ft_toupper(c) == toupper(c))
	{
		printf("OK!!!\n");
		printf("%c\t%c", ft_toupper(c), toupper(c));
	}
	else
	{
		printf("KO!!!\n");
		printf("%c\t%c", ft_toupper(c), toupper(c));
	}

	return (0);
}*/
