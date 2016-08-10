/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_2x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 21:27:03 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:38:30 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*flags(unsigned long long x, t_arg *arg)
{
	char	*s;

	if (arg->punct && x == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_unsigned(x, 16);
	arg->size = ft_strlen(s);
	while (arg->size < arg->precision)
	{
		s = ft_freejoin(ft_strdup("0"), s);
		arg->size++;
	}
	if (arg->diese && x)
		s = ft_freejoin(ft_strdup("0X"), s);
	if (arg->diese)
		arg->size += 2;
	while (arg->size < arg->width)
	{
		if (arg->moins)
			s = ft_freejoin(s, ft_strdup(" "));
		else
			s = ft_freejoin(ft_strdup(" "), s);
		arg->size++;
	}
	return (s);
}

static char	*zero_norme(unsigned long long x, t_arg *arg, char *s)
{
	if (arg->precision)
	{
		while (arg->size++ < arg->precision)
			s = ft_freejoin(ft_strdup("0"), s);
		if (arg->diese)
			arg->size += 2;
	}
	else
	{
		if (arg->diese)
			arg->size += 2;
		while (arg->size++ < arg->width)
			s = ft_freejoin(ft_strdup("0"), s);
	}
	if (arg->diese && x)
		s = ft_freejoin(ft_strdup("0X"), s);
	while (arg->size <= arg->width)
	{
		if (arg->moins)
			s = ft_freejoin(s, ft_strdup(" "));
		else
			s = ft_freejoin(ft_strdup(" "), s);
		arg->size++;
	}
	return (s);
}

static char	*zero(unsigned long long x, t_arg *arg)
{
	char	*s;

	if (arg->punct && x == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_unsigned(x, 16);
	arg->size = ft_strlen(s);
	s = zero_norme(x, arg, s);
	return (s);
}

void		conv_2x(t_arg *arg, char *format)
{
	unsigned long long	x;
	char				*s;

	x = va_arg(arg->ap, unsigned long long);
	if (arg->l)
		x = (unsigned long)x;
	else if (arg->h)
		x = (unsigned short int)x;
	else if (arg->hh)
		x = (unsigned char)x;
	else if (arg->j)
		x = (uintmax_t)x;
	else if (arg->z)
		x = (size_t)x;
	else if (!arg->ll)
		x = (unsigned int)x;
	if (arg->zero && !arg->moins)
		s = zero(x, arg);
	else
		s = flags(x, arg);
	arg->ret += ft_strlen(s);
	if (format[arg->i] == 'x')
		s = ft_putstrl(s);
	ft_putstr(s);
	ft_strdel(&s);
}
