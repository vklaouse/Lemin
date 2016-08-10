/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 19:10:06 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:38:53 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	zero(t_arg *arg, char *s)
{
	while (arg->size < arg->width)
	{
		s = ft_strjoin(s, ft_strdup("0"));
		arg->size++;
	}
	arg->size = ft_strlen(s);
	s = ft_putstrl(s);
	if (!arg->punct)
		ft_putstr(s);
	free(s);
}

static void	norme(t_arg *arg, char *s)
{
	while (arg->size < arg->width)
	{
		if (arg->moins)
			s = ft_strjoin(s, ft_strdup(" "));
		else
			s = ft_strjoin(ft_strdup(" "), s);
		arg->size++;
	}
	arg->size = ft_strlen(s);
	s = ft_putstrl(s);
	if (!arg->punct)
		ft_putstr(s);
	free(s);
}

void		conv_p(t_arg *arg)
{
	char	*s;

	s = ft_itoa_base_unsigned(va_arg(arg->ap, unsigned long long), 16);
	arg->size = ft_strlen(s);
	while (arg->size < arg->precision)
	{
		s = ft_freejoin(ft_strdup("0"), s);
		arg->size++;
	}
	if (!arg->punct)
		s = ft_freejoin(ft_strdup("0x"), s);
	else
	{
		ft_putstr("0x");
		arg->ret++;
	}
	arg->size += 2;
	if (arg->zero && !arg->moins)
		zero(arg, s);
	else
		norme(arg, s);
	arg->ret += arg->size;
}
