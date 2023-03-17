/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:47:40 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/16 17:03:26 by vde-vasc         ###   ########.fr       */
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

static int	separator(char *string, char c)

{
	int	i;

	i = 0;
	while (string[i] == c)
		i++;
	return (i);
}

static char	**split_string(char *string, char c, int words, int max)

{
	int		i;
	int		len;
	int		point;
	char	**array;

	array = ft_calloc(words, sizeof(char *));
	point = 0;
	len = 0;
	i = separator(string, c);
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

char	**ft_split(char *string, char c)

{
	size_t	string_len;
	int		count_words;
	char	**array;

	if (!(string))
		return (NULL);
	string_len = ft_strlen(string);
	count_words = how_many_words(string, c, string_len);
	array = split_string(string, c, count_words + 1, string_len);
	return (array);
}
