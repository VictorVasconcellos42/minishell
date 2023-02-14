/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:37:34 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/06 14:37:35 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)

{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void)

{
	unsigned char c;

	c = 20;
	if (ft_tolower(c) == tolower(c))
		printf("OK!!");
	else
		printf("KO!!");
	return (0);
}*/
