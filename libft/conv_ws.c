/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ws.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 22:59:59 by vklaouse          #+#    #+#             */
/*   Updated: 2016/04/23 01:31:45 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	norme(char *stock, t_arg *arg)
{
	int	size;

	arg->size = ft_strlen(stock);
	if (arg->moins)
		ft_putstr(stock);
	if (arg->width > arg->size)
	{
		size = arg->width - arg->size;
		if (arg->zero)
			ft_put_mystere('0', size);
		else
			ft_put_mystere(' ', size);
	}
	if (!arg->moins)
		ft_putstr(stock);
	if (arg->width > arg->size)
		arg->size = arg->width;
	arg->ret += arg->size;
	ft_strdel(&stock);
}

static void	conv(wchar_t *ws, t_arg *arg)
{
	int				i;
	unsigned int	size;
	char			**bin;
	char			*tmp;
	char			*stock;

	i = 0;
	if (!ws)
		stock = ft_strdup("(null)");
	else
		stock = ft_strnew(0);
	while (ws && ws[i] && !arg->punct)
	{
		size = (unsigned int)ws[i];
		tmp = ft_itoa_base_unsigned(size, 2);
		bin = mask_unicode(tmp);
		size = 0;
		while (bin[size++])
			arg->size++;
		if (arg->size > arg->precision && arg->precision)
			break ;
		stock = ft_freejoin(stock, stockbis(bin, size));
		i++;
	}
	norme(stock, arg);
}

void		conv_ws(t_arg *arg, char *format)
{
	wchar_t	*ws;
	int		i;

	i = 0;
	if (format[arg->i] == 'S' || arg->l == 1)
	{
		ws = va_arg(arg->ap, wchar_t *);
		conv(ws, arg);
	}
	else
		conv_s(arg);
}
