/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tubes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 04:34:58 by vklaouse          #+#    #+#             */
/*   Updated: 2016/05/10 16:36:23 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_cmp_left(t_vector *v, char **tab, t_parse *p)
{
	size_t	i;
	char	*str;
	char	*space;

	i = 0;
	space = ft_strnew(1);
	space[0] = '-';
	tab_len(tab, p);
	if (p->resolve.tab_len != 1)
	{
		p->alonepath = 1;
		return ;
	}
	while (i < v->total)
	{
		str = ft_strdup(v->data[i]);
		if (!(ft_strcmp(tab[0], str)))
		{
			space = ft_freejoin(str, space);
			ft_vector_add(v, ft_strjoin(space, tab[1]));
			return ;
		}
		i++;
	}
	p->alonepath = 1;
}

static void	ft_cmp_right(t_vector *v, char **tab, t_parse *p)
{
	size_t	i;
	char	*str;
	char	*space;

	i = 0;
	space = ft_strnew(1);
	space[0] = '-';
	while (i < v->total)
	{
		str = ft_strdup(v->data[i]);
		if (!(ft_strcmp(tab[1], str)))
		{
			space = ft_freejoin(str, space);
			ft_vector_add(v, ft_strjoin(space, tab[0]));
			return ;
		}
		i++;
	}
	p->alonepath = 1;
}

void		cnt_paths(t_vector *v, t_parse *p)
{
	char **tab;

	p->resolve.tab_len = 0;
	tab = ft_strsplit(v->data[0], '-');
	while (tab[p->resolve.tab_len])
		p->resolve.tab_len++;
	if (p->resolve.tab_len == 0)
		ft_error("Error !");
}

void		check_caca(t_vector *v, t_parse *p)
{
	char	**tab_tmp;
	char	**tab_tmp2;
	int		i;

	while (p->i < v->total)
	{
		i = 0;
		tab_tmp = ft_strsplit(v->data[p->i], '-');
		tab_tmp2 = ft_strsplit(v->data[p->i + 1], '-');
		while (tab_tmp2[i])
			i++;
		if (i == 2)
		{
			if (!ft_strcmp(tab_tmp[1], tab_tmp2[1]) && \
				!ft_strcmp(tab_tmp[1], p->resolve.end) && v->total > 1)
				ft_vector_delat(v, p->i);
			else
				p->i++;
		}
		else
			break ;
	}
}

void		check_tubes(char *str, t_parse *p, t_vector *v)
{
	char	**tab;

	p->cnt++;
	tab = ft_strsplit(str, '-');
	ft_cmp_left(v, tab, p);
	if (p->alonepath != 1)
		ft_cmp_right(v, tab, p);
}
