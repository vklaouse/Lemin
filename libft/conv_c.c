/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 21:06:47 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:40:30 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putstr_right(unsigned char c, t_arg *arg)
{
	int	i;

	i = 1;
	if (arg->zero == 0)
	{
		while (i < arg->width)
		{
			ft_putchar(' ');
			arg->ret++;
			i++;
		}
	}
	else
	{
		while (i < arg->width)
		{
			ft_putchar('0');
			arg->ret++;
			i++;
		}
	}
	if (!arg->moins)
		ft_putchar(c);
	arg->ret++;
}

static void	norme(t_arg *arg, unsigned char c)
{
	int i;

	i = 1;
	if (arg->moins)
		ft_putchar(c);
	if (arg->width != 0 && arg->plus == 1)
	{
		ft_putchar(c);
		arg->ret++;
		while (i < arg->width)
		{
			ft_putchar(' ');
			arg->ret++;
			i++;
		}
	}
}

void		conv_c(t_arg *arg, char *format)
{
	unsigned char	c;

	if (format[arg->i] == 'C' || arg->l == 1)
		conv_bigc(arg);
	else
	{
		c = va_arg(arg->ap, int);
		if (!arg->width && !arg->moins)
		{
			ft_putchar(c);
			arg->ret++;
		}
		norme(arg, c);
		if (arg->width != 0 && arg->plus == 0)
			ft_putstr_right(c, arg);
	}
}

void		conv_bigc(t_arg *arg)
{
	unsigned int	c;
	char			*wc;
	char			**bin;

	c = va_arg(arg->ap, unsigned int);
	wc = ft_itoa_base_unsigned(c, 2);
	bin = mask_unicode(wc);
	while (bin[arg->size])
		arg->size++;
	if (arg->width > arg->size && !arg->moins)
	{
		arg->width -= arg->size;
		ft_put_mystere(' ', arg->width);
		arg->size += arg->width;
	}
	ft_putwchar(bin);
	if (arg->width > arg->size && arg->moins)
	{
		arg->width -= arg->size;
		ft_put_mystere(' ', arg->width);
		arg->size += arg->width;
	}
	arg->ret += arg->size;
}
