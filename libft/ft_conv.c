/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 19:36:24 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:41:29 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_conv(char *format, t_arg *arg)
{
	if (format[arg->i] == 'd' || format[arg->i] == 'i' || \
		format[arg->i] == 'D')
		conv_d(format, arg);
	else if (format[arg->i] == 'c' || format[arg->i] == 'C')
		conv_c(arg, format);
	else if (format[arg->i] == 's' || format[arg->i] == 'S')
		conv_ws(arg, format);
	else if (format[arg->i] == '%')
		conv_strange(arg);
	else if (format[arg->i] == 'u' || format[arg->i] == 'U')
		conv_u(arg, format);
	else if (format[arg->i] == 'x' || format[arg->i] == 'X')
		conv_2x(arg, format);
	else if (format[arg->i] == 'o' || format[arg->i] == 'O')
		conv_o(arg, format);
	else if (format[arg->i] == 'p')
		conv_p(arg);
	else if (arg->fail != 1)
		wrong_conv(format, arg);
}
