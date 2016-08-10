/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 01:46:19 by vklaouse          #+#    #+#             */
/*   Updated: 2016/04/23 01:59:06 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vector_add(t_vector *v, void *e)
{
	if (v->total == v->max)
		if (ft_vector_resize(v) == NULL)
			return (NULL);
	v->data[v->total++] = e;
	return (v);
}
