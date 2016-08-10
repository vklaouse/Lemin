/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:47:55 by vklaouse          #+#    #+#             */
/*   Updated: 2015/12/11 12:10:29 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s != NULL && f != NULL)
	{
		i = 0;
		j = ft_strlen(s);
		str = (char*)malloc(sizeof(char) * (j + 1));
		if (str == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			str[i] = f((char)s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
