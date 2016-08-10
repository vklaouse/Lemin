/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 01:48:59 by vklaouse          #+#    #+#             */
/*   Updated: 2016/04/23 02:00:34 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vector_init(t_vector *v, size_t size)
{
	size_t	s;

	s = (size == 0) ? VECTOR_INIT_CAPACITY : size;
	v->max = s;
	v->total = 0;
	v->data = ft_memalloc(sizeof(void*) * s);
	if (v->data == NULL)
		return (NULL);
	return (v);
}
