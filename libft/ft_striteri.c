/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 08:37:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/27 09:00:47 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))

{
	unsigned int	index;

	index = -1;
	if (!(s))
		return ;
	while (s[++index])
		f(index, s + index);
}
