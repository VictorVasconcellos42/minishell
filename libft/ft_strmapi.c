/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 07:30:01 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/27 08:20:03 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))

{
	unsigned int	index;
	char			*string;

	if (!(s))
		return (NULL);
	string = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!(string))
		return (NULL);
	index = -1;
	while (s[++index])
		string[index] = f(index, s[index]);
	return (string);
}
