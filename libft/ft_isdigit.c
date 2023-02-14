/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:52:44 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/04 09:53:03 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)

{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(void)

{
	char	a;
	char	b;

	b = '9';
	a = ft_isdigit(b);
	printf("%i\n", a);
	return 0;
}*/
