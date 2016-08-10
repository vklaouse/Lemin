/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 21:47:48 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:41:09 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	flags_zero(t_arg *arg, int i)
{
	int	a;

	if (arg->width > arg->precision && arg->precision)
	{
		if (arg->precision > i)
		{
			arg->precision = i;
		}
		a = arg->width;
		while (a > arg->precision)
		{
			ft_putchar('0');
			i++;
			a--;
		}
	}
	else if (arg->width > i && !arg->precision)
	{
		while (i < arg->width)
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

static int	flags_again_norme(t_arg *arg, int i)
{
	int	a;

	if (arg->precision > i)
	{
		arg->precision = i;
	}
	a = arg->width;
	while (a-- > arg->precision)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

static int	flags_again(t_arg *arg, int i)
{
	if (arg->width > arg->precision && arg->precision)
		i = flags_again_norme(arg, i);
	else if (arg->width > i && !arg->precision)
	{
		while (i < arg->width)
		{
			ft_putchar(' ');
			i++;
		}
	}
	else if (arg->width < arg->precision)
	{
		if (i < arg->width && i < arg->precision)
			while (i < arg->width)
			{
				ft_putchar(' ');
				i++;
			}
	}
	return (i);
}

static void	flags(t_arg *arg, int i, char *s)
{
	if (arg->moins)
	{
		if (arg->precision && !arg->punct)
			i = ft_putnstr(s, arg, i);
		else if (!arg->punct)
			ft_putstr(s);
	}
	if (!arg->zero || arg->moins)
		i = flags_again(arg, i);
	if (arg->zero && !arg->moins)
		i = flags_zero(arg, i);
	if (!arg->moins)
	{
		if (arg->precision && !arg->punct)
			i = ft_putnstr(s, arg, i);
		else if (!arg->punct)
			ft_putstr(s);
	}
	if (arg->width > arg->precision && arg->width > i)
		arg->ret = arg->ret + arg->width;
	else
		arg->ret = arg->ret + i;
}

void		conv_s(t_arg *arg)
{
	char	*s;
	int		i;

	if (!(s = ft_strdup(va_arg(arg->ap, char *))))
		s = ft_strdup("(null)");
	if (s[0] == '\0')
		i = 0;
	else
		i = ft_strlen(s);
	if (arg->precision < 0)
	{
		arg->punct = 0;
		arg->precision = 0;
	}
	if (arg->punct == 1)
	{
		if (arg->width && arg->zero)
			ft_put_mystere('0', arg->width);
		else if (arg->width && !arg->zero)
			ft_put_mystere(' ', arg->width);
		arg->ret += arg->width;
		return ;
	}
	flags(arg, i, s);
	free(s);
}
