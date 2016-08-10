/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 06:33:55 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:40:15 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	wrong_conv(char *format, t_arg *arg)
{
	if (arg->width)
		arg->ret += arg->width;
	else
		arg->ret++;
	if (!arg->moins)
	{
		if (arg->zero)
			ft_put_mystere('0', arg->width - 1);
		else
			ft_put_mystere(' ', arg->width - 1);
	}
	ft_putchar(format[arg->i]);
	if (arg->moins)
	{
		if (arg->zero)
			ft_put_mystere('0', arg->width - 1);
		else
			ft_put_mystere(' ', arg->width - 1);
	}
}
