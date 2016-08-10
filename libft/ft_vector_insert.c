/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 01:49:27 by vklaouse          #+#    #+#             */
/*   Updated: 2016/04/23 02:00:48 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vector_insert(t_vector *v, size_t i, void *e)
{
	void	*tmp;

	if (i > v->total)
		return (NULL);
	if (v->total + 1 >= v->max)
		if (ft_vector_resize(v) == NULL)
			return (NULL);
	while (i < v->total)
	{
		tmp = ft_vector_get(v, i);
		ft_vector_set(v, i, e);
		e = tmp;
		++i;
	}
	if (i == v->total)
		return (ft_vector_add(v, e));
	v->total++;
	return (v);
}
