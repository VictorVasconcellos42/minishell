/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:47:40 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/10 21:00:25 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*freedom(char	**array)

{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array[i]);
	free(array);
	return (NULL);
}

static char	**split_string(char const *string, char c, char **array, int max)

{
	int		i;
	int		len;
	int		point;

	point = 0;
	len = 0;
	i = 0;
	while (string[i] == c)
		i++;
	while (i <= max)
	{
		if ((string[i] == c && len != 0) || \
		(string[i] == '\0' && len != 0))
		{
			array[point] = malloc((len + 1) * sizeof(char));
			if (!(array[point]))
				return (freedom(array));
			ft_strlcpy(array[point++], &string[i - len], len + 1);
			len = 0;
		}
		else if (string[i] != c)
			len++;
		i++;
	}
	return (array);
}

static int	how_many_words(char const *string, char c, size_t string_len)

{
	size_t	i;
	int		count_words;
	int		len_words;

	i = 0;
	count_words = 0;
	len_words = 0;
	while (string[i] == c)
		i++;
	while (i < string_len)
	{
		if (string[i] == c && len_words != 0)
		{
			count_words++;
			len_words = 0;
		}
		else if (string[i] != c)
			len_words++;
		i++;
	}
	if (len_words != 0 && count_words >= 0)
		count_words++;
	return (count_words);
}

char	**ft_split(char const *string, char c)

{
	size_t	string_len;
	int		count_words;
	char	**array_words;
	char	**array;

	if (!(string))
		return (NULL);
	string_len = ft_strlen(string);
	count_words = how_many_words(string, c, string_len);
	array_words = ft_calloc((count_words + 1), sizeof(char *));
	if (!(array_words))
		return (NULL);
	array = split_string(string, c, array_words, string_len);
	return (array);
}
