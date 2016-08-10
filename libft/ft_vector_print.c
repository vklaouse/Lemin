/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 01:49:56 by vklaouse          #+#    #+#             */
/*   Updated: 2016/04/23 23:47:28 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_print(t_vector *v, void (*print)(void*))
{
	size_t	i;

	i = 0;
	while (i < v->total)
	{
		ft_putstr("Elem #");
		ft_putnbr(i);
		ft_putstr(" => ");
		if (print == 0)
			ft_putnbr((int)ft_vector_get(v, i));
		else
			(*print)(ft_vector_get(v, i));
		ft_putstr("\n");
		++i;
	}
}
