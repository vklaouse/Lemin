/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 05:20:33 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:41:49 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	flag_width_norme(char *format, t_arg *arg, int i)
{
	char	*str;

	if (ft_isdigit(format[i]) && format[i] != '0')
	{
		while (ft_isdigit(format[i]))
			i++;
		i -= arg->i;
		str = ft_strnew(i);
		i = 0;
		while (ft_isdigit(format[arg->i]))
		{
			str[i] = format[arg->i];
			arg->i++;
			i++;
		}
		arg->width = ft_atoi(str);
		ft_strdel(&str);
	}
}

void		flag_width(char *format, t_arg *arg)
{
	int	i;

	i = arg->i;
	if ((ft_isdigit(format[i]) && format[i] != '0') || format[i] == '*')
	{
		if (format[i] == '*')
		{
			arg->width = va_arg(arg->ap, int);
			arg->i++;
			i++;
		}
		flag_width_norme(format, arg, i);
		if (format[arg->i] == '*')
		{
			arg->width = va_arg(arg->ap, int);
			arg->i++;
		}
		if (arg->width < 0)
		{
			arg->moins = 1;
			arg->width *= -1;
		}
	}
	else if (format[i] == '0')
		arg->fail = 1;
}

static void	flag_precision_norme(char *format, t_arg *arg, int i)
{
	char	*str;

	if (format[arg->i + 1] == '0')
		arg->punct = 1;
	while (ft_isdigit(format[i]))
		i++;
	arg->i++;
	i = i - arg->i;
	str = ft_strnew(i);
	i = 0;
	while (ft_isdigit(format[arg->i]))
	{
		str[i] = format[arg->i];
		arg->i++;
		i++;
	}
	arg->precision = ft_atoi(str);
	free(str);
}

void		flag_precision(char *format, t_arg *arg)
{
	int	i;

	i = arg->i + 1;
	if ((format[arg->i] == '.' && ft_isdigit(format[arg->i + 1])) \
		|| (format[arg->i] == '.' && format[arg->i + 1] == '*'))
	{
		if (format[arg->i] == '.' && ft_isdigit(format[arg->i + 1]))
			flag_precision_norme(format, arg, i);
		if (format[arg->i + 1] == '*')
		{
			arg->precision = va_arg(arg->ap, int);
			arg->i += 2;
			if (arg->precision <= 0)
				arg->punct = 1;
		}
	}
	else if (format[arg->i] == '.' && !ft_isdigit(format[arg->i + 1]))
	{
		arg->i++;
		arg->punct = 1;
	}
}

void		flag_length(char *format, t_arg *arg)
{
	if (format[arg->i] == 'h' && format[arg->i + 1] == 'h')
	{
		arg->hh = 1;
		arg->i++;
	}
	else if (format[arg->i] == 'h' && format[arg->i + 1] != 'h')
		arg->h = 1;
	else if (format[arg->i] == 'l' && format[arg->i + 1] != 'l')
		arg->l = 1;
	else if (format[arg->i] == 'l' && format[arg->i + 1] == 'l')
	{
		arg->ll = 1;
		arg->i++;
	}
	else if (format[arg->i] == 'z')
		arg->z = 1;
	else if (format[arg->i] == 'j')
		arg->j = 1;
	if ((arg->hh == 1 || arg->h == 1 || arg->ll == 1 || arg->l == 1	\
		|| arg->j == 1 || arg->z == 1) && format[arg->i + 1] != '\0')
		arg->i++;
	else if ((arg->hh == 1 || arg->h == 1 || arg->ll == 1 || arg->l == 1 \
			|| arg->j == 1 || arg->z == 1) && format[arg->i + 1] == '\0')
		arg->fail++;
}
