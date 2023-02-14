/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:07:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/06 18:27:12 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)

{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/* #include <stdio.h>

int	main(void)

{
	char	c;
	int		a;

	c = '\t';
	a = ft_isprint(c);
	printf("%i", a);
	return (0);
} */
