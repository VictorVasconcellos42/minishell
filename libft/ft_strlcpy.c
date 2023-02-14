/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:22:08 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/05/09 10:56:40 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)

{
	unsigned char	*my_src;
	size_t			len;
	size_t			i;

	my_src = (unsigned char *) src;
	len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (len);
	while (my_src[i] && dstsize - 1)
	{
		dst[i] = my_src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (len);
}

/*#include <stdio.h>
#include <string.h>

void test(int size)
{
    char string[] = "ROBOZINHO DA SENAI";
    char buffer[100];
    int r, my;
	char string2[] = "ROBOZINHO DA SENAI";
	char buffer2[100];


    r = strlcpy(buffer,string,size);
	my = ft_strlcpy(buffer2, string2, size);
	if (my == r)
		printf("OK VICTOR VC É UM GENIO!\n");
	else
		printf("Preciso dizer nada\n");
    printf("Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            r
          );
	 printf("Copied '%s' into '%s', length %d\n",
            string2,
            buffer2,
            my
          );

}

int main()
{
    test(19);
    test(10);
    test(1);
    test(0);
	test(100);
	test(12);
	
    return(0);
}*/
