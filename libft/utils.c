/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 22:30:44 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/04 19:42:17 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_zero(int k, t_arg *arg)
{
	int i;

	i = 0;
	while (i < k)
	{
		ft_putchar('0');
		arg->ret++;
		i++;
	}
}

void	ft_put_space(int k, t_arg *arg)
{
	int i;

	i = 0;
	while (i < k)
	{
		ft_putchar(' ');
		arg->ret++;
		i++;
	}
}

void	ft_put_mystere(char c, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_putchar(c);
		j++;
	}
}

char	*ft_putstrl(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}

int		ft_putnstr(char *s, t_arg *arg, int i)
{
	int a;

	a = 0;
	if (arg->precision < i)
	{
		while (a < arg->precision)
		{
			ft_putchar(s[a]);
			a++;
		}
	}
	else if (arg->precision > i)
	{
		ft_putstr(s);
		a = i++;
		ft_putchar(s[a]);
	}
	return (a);
}
