/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 20:29:59 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:42:02 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init(t_arg *arg)
{
	arg->diese = 0;
	arg->moins = 0;
	arg->plus = 0;
	arg->space = 0;
	arg->zero = 0;
	arg->width = 0;
	arg->precision = 0;
	arg->hh = 0;
	arg->h = 0;
	arg->ll = 0;
	arg->l = 0;
	arg->j = 0;
	arg->z = 0;
	arg->punct = 0;
	arg->size = 0;
}

static void	ft_check_option(char *format, t_arg *arg)
{
	ft_init(arg);
	arg->i++;
	while (format[arg->i] == '#' || format[arg->i] == '-' || format[arg->i] \
			== '+' || format[arg->i] == ' ' || format[arg->i] == '0')
	{
		flag_diese(format, arg);
		flag_moins(format, arg);
		flag_plus(format, arg);
		flag_space(format, arg);
		flag_zero(format, arg);
		arg->i++;
	}
	flag_width(format, arg);
	flag_precision(format, arg);
	flag_length(format, arg);
	ft_conv(format, arg);
}

static int	ft_roam(char *format, t_arg *arg)
{
	arg->i = 0;
	while (format[arg->i] && format)
	{
		arg->fail = 0;
		if (format[arg->i] == '%' && format[arg->i + 1] == '\0')
			break ;
		else if (format[arg->i] == '%')
			ft_check_option(format, arg);
		else if (arg->fail == 0 && format[arg->i] != '\0')
		{
			ft_putchar(format[arg->i]);
			arg->ret++;
		}
		if (format[arg->i])
			arg->i++;
	}
	return (arg->ret);
}

int			ft_printf(char *format, ...)
{
	t_arg	arg;
	int		ret;

	arg.ret = 0;
	va_start(arg.ap, format);
	ret = ft_roam(format, &arg);
	va_end(arg.ap);
	return (arg.ret);
}
