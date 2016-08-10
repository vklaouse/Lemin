/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 04:27:19 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:39:35 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_diese(char *format, t_arg *arg)
{
	if (format[arg->i] == '#' && format[arg->i + 1] == '\0')
		arg->fail = 1;
	else if (format[arg->i] == '#')
		arg->diese = 1;
}

void	flag_moins(char *format, t_arg *arg)
{
	if (format[arg->i] == '-' && format[arg->i + 1] == '\0')
		arg->fail = 1;
	else if (format[arg->i] == '-')
		arg->moins = 1;
}

void	flag_plus(char *format, t_arg *arg)
{
	if (format[arg->i] == '+' && format[arg->i + 1] == '\0')
		arg->fail = 1;
	else if (format[arg->i] == '+')
		arg->plus = 1;
}

void	flag_space(char *format, t_arg *arg)
{
	if (format[arg->i] == ' ' && format[arg->i + 1] == '\0')
		arg->fail = 1;
	else if (format[arg->i] == ' ')
		arg->space = 1;
}

void	flag_zero(char *format, t_arg *arg)
{
	if (format[arg->i] == '0' && format[arg->i + 1] == '\0')
		arg->fail = 1;
	else if (format[arg->i] == '0')
		arg->zero = 1;
}
