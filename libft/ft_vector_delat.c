/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 01:47:46 by vklaouse          #+#    #+#             */
/*   Updated: 2016/04/23 01:59:44 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vector_delat(t_vector *v, size_t i)
{
	if (i >= v->total)
		return (NULL);
	v->data[i] = NULL;
	v->total -= 1;
	while (i < v->total)
	{
		v->data[i] = v->data[i + 1];
		++i;
	}
	return (v);
}
