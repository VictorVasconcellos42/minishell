/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:31:38 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/08/24 14:11:51 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa(unsigned long num, char flag)

{
	static int	count;
	char		*base;
	char		*base2;

	count = 0;
	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (num >= 16)
		ft_puthexa(num / 16, flag);
	if (flag == 'X')
		count += ft_putchar(base2[num % 16]);
	else
		count += ft_putchar(base[num % 16]);
	return (count);
}

int	ft_puthexa_case(unsigned long num, char flag)

{
	return (ft_puthexa(num, flag));
}
