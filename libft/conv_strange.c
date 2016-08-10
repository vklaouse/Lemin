/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_strange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:41:42 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:39:08 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_strange(t_arg *arg)
{
	int	i;

	i = 1;
	if (arg->moins)
		ft_putchar('%');
	if (!arg->zero || arg->moins)
	{
		while (i < arg->width)
		{
			ft_putchar(' ');
			i++;
		}
	}
	if (arg->zero && !arg->moins)
	{
		while (i < arg->width)
		{
			ft_putchar('0');
			i++;
		}
	}
	if (!arg->moins)
		ft_putchar('%');
	arg->ret = arg->ret + i;
}
