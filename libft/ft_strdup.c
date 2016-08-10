/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:41:00 by vklaouse          #+#    #+#             */
/*   Updated: 2016/02/22 16:40:59 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char*str;

	if (s == NULL)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	ft_strcpy(str, s);
	return (str);
}
