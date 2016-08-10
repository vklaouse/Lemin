/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 21:54:04 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:40:57 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*flags(unsigned long long o, t_arg *arg)
{
	char	*s;

	if (arg->punct == 1 && o == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_unsigned(o, 8);
	arg->size = ft_strlen(s);
	while (arg->size < arg->precision)
	{
		s = ft_freejoin(ft_strdup("0"), s);
		arg->size++;
	}
	if (arg->diese && s[0] != 0)
		arg->size++;
	if (arg->diese && s[0] != '0')
		s = ft_freejoin(ft_strdup("0"), s);
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

static char	*zero(unsigned long long o, t_arg *arg)
{
	char	*s;

	if (arg->punct == 1 && o == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_unsigned(o, 8);
	arg->size = ft_strlen(s);
	if (arg->precision)
		while (arg->size++ < arg->precision)
			s = ft_freejoin(ft_strdup("0"), s);
	else
		while (arg->size++ < arg->width)
			s = ft_freejoin(ft_strdup("0"), s);
	if (arg->diese && s[0] != '0')
		arg->size++;
	if (arg->diese && s[0] != '0')
		s = ft_freejoin(ft_strdup("0"), s);
	while (arg->size++ <= arg->width)
	{
		if (arg->moins)
			s = ft_freejoin(s, ft_strdup(" "));
		else
			ft_freejoin(ft_strdup(" "), s);
	}
	return (s);
}

void		conv_o(t_arg *arg, char *format)
{
	unsigned long long	o;
	char				*s;

	o = va_arg(arg->ap, unsigned long long);
	if (arg->l || format[arg->i] == 'O')
		o = (unsigned long)o;
	else if (arg->h)
		o = (unsigned short int)o;
	else if (arg->hh)
		o = (unsigned char)o;
	else if (arg->j)
		o = (uintmax_t)o;
	else if (arg->z)
		o = (size_t)o;
	else if (!arg->ll)
		o = (unsigned int)o;
	if (arg->zero && !arg->moins)
		s = zero(o, arg);
	else
		s = flags(o, arg);
	arg->size = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
	arg->ret += arg->size;
}
