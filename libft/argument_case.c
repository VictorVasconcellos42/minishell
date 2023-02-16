/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:08:48 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/08/24 14:11:01 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	argument_case(char c, va_list arguments)

{
	int	count;

	if (c == 'c')
		return (ft_putchar(va_arg(arguments, int)));
	if (c == 's')
		return (ft_putstr(va_arg(arguments, char *)));
	if (c == 'x')
		return (ft_puthexa_case(va_arg(arguments, unsigned int), c));
	if ((c == 'd') || (c == 'i'))
		return (ft_putnbr(va_arg(arguments, int)));
	if (c == 'X')
		return (ft_puthexa_case(va_arg(arguments, unsigned int), c));
	if (c == 'p')
	{
		count = ft_putstr("0x");
		return (count + ft_puthexa_case(va_arg(arguments, unsigned long), c));
	}
	if (c == 'u')
		return (ft_putunbr(va_arg(arguments, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
