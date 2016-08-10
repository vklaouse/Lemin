/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 16:47:56 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:38:43 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*flags_norme(long long d, t_arg *arg, char *s)
{
	if (arg->plus && d >= 0)
		s = ft_freejoin(ft_strdup("+"), s);
	if (arg->space && d >= 0 && !arg->plus)
		s = ft_freejoin(ft_strdup(" "), s);
	if (d < 0)
		s = ft_freejoin(ft_strdup("-"), s);
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

static char	*flags(long long d, t_arg *arg)
{
	char	*s;
	int		i;

	if (arg->punct == 1 && d == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_long(d, 10);
	i = ft_strlen(s);
	if (d < 0 || arg->plus || arg->space)
		arg->size = i + 1;
	else
		arg->size = i;
	while (i < arg->precision)
	{
		s = ft_freejoin(ft_strdup("0"), s);
		arg->size++;
		i++;
	}
	s = flags_norme(d, arg, s);
	return (s);
}

static char	*zero_norme(t_arg *arg, long long d, char *s)
{
	if (arg->plus && d >= 0)
		s = ft_freejoin(ft_strdup("+"), s);
	if (arg->space && d >= 0 && !arg->plus)
		s = ft_freejoin(ft_strdup(" "), s);
	if (d < 0)
		s = ft_freejoin(ft_strdup("-"), s);
	while (arg->size < arg->width)
	{
		if (arg->precision && !arg->punct)
			s = ft_freejoin(ft_strdup(" "), s);
		else
			s = ft_freejoin(ft_strdup("0"), s);
		arg->size++;
	}
	return (s);
}

static char	*zero(long long d, t_arg *arg)
{
	char	*s;
	int		i;

	if (arg->punct == 1 && d == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_long(d, 10);
	i = ft_strlen(s);
	if (d < 0 || arg->plus || arg->space)
		arg->size = i + 1;
	else
		arg->size = i;
	if (arg->precision)
		while (i < arg->precision && arg->size < arg->width)
		{
			s = ft_freejoin(ft_strdup("0"), s);
			i++;
			arg->size++;
		}
	else
		while (arg->size++ < arg->width)
			s = ft_freejoin(ft_strdup("0"), s);
	s = zero_norme(arg, d, s);
	return (s);
}

void		conv_d(char *format, t_arg *arg)
{
	long long	d;
	char		*s;

	d = va_arg(arg->ap, long long);
	if (arg->l || format[arg->i] == 'D')
		d = (long)d;
	else if (arg->h)
		d = (short int)d;
	else if (arg->hh)
		d = (signed char)d;
	else if (arg->j)
		d = (intmax_t)d;
	else if (arg->z)
		d = (ssize_t)d;
	else if (!arg->ll)
		d = (int)d;
	if (arg->zero && !arg->moins)
		s = zero(d, arg);
	else
		s = flags(d, arg);
	arg->size = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
	arg->ret += arg->size;
}
