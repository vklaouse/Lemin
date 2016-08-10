/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:29:10 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:41:19 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	flags_again_norme(t_arg *arg, int i)
{
	if (arg->precision > i)
		arg->width = arg->width - arg->precision + i;
	if (arg->precision > i)
		arg->precision = arg->precision + arg->width - i;
	while (i < arg->width)
	{
		if (arg->moins == 0 && arg->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	while (i < arg->precision)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

static int	flags_again(t_arg *arg, int i)
{
	if (arg->width > arg->precision && arg->precision)
		i = flags_again_norme(arg, i);
	else if (arg->width > arg->precision && !arg->precision)
	{
		while (i < arg->width)
		{
			if (arg->moins == 0 && arg->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
	}
	else if (arg->width < arg->precision)
	{
		while (i < arg->precision)
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

static void	flags(t_arg *arg, int i, unsigned long long u)
{
	if (arg->moins == 1 && arg->punct == 0)
		ft_putnbr_u(u);
	i = flags_again(arg, i);
	if (arg->moins == 0 && arg->punct == 0)
		ft_putnbr_u(u);
	arg->ret = arg->ret + i;
}

void		ft_putnbr_u(unsigned long long value)
{
	if (value >= 10)
		ft_putnbr_u(value / 10);
	ft_putchar(value % 10 + '0');
}

void		conv_u(t_arg *arg, char *format)
{
	unsigned long long	u;
	unsigned long long	tmp;
	int					i;

	u = va_arg(arg->ap, unsigned long long);
	if (arg->l || format[arg->i] == 'U')
		u = (unsigned long)u;
	else if (arg->h)
		u = (unsigned short int)u;
	else if (arg->hh)
		u = (unsigned char)u;
	else if (arg->j)
		u = (uintmax_t)u;
	else if (arg->z)
		u = (size_t)u;
	else if (!arg->ll)
		u = (unsigned int)u;
	tmp = u;
	i = 1;
	while ((tmp = tmp / 10))
		i++;
	if (arg->punct == 1 && u == 0)
		i--;
	flags(arg, i, u);
}
