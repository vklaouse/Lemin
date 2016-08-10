/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 01:50:24 by vklaouse          #+#    #+#             */
/*   Updated: 2016/04/23 02:01:18 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vector_resize(t_vector *v)
{
	void	*new;
	size_t	s;

	s = sizeof(void*) * v->max * VECTOR_GROWTH_FACTOR;
	new = ft_realloc(v->data, s, v->total * sizeof(void*));
	if (new == NULL)
		return (NULL);
	v->data = new;
	v->max *= VECTOR_GROWTH_FACTOR;
	return (v);
}
