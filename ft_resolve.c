/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 02:27:55 by vklaouse          #+#    #+#             */
/*   Updated: 2016/05/02 19:36:39 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	add_doors(t_vector *v, char **tab2, int cnt, int cnt2)
{
	int		i;
	char	*space;
	char	*tmp;

	i = 1;
	space = ft_strnew(1);
	space[0] = '-';
	tmp = ft_strjoin(v->data[cnt], space);
	ft_vector_delat(v, cnt);
	while (tab2[i])
	{
		tmp = ft_strjoin(tmp, tab2[i]);
		if (tab2[i + 1])
			tmp = ft_strjoin(tmp, space);
		i++;
	}
	ft_vector_delat(v, cnt2);
	ft_vector_add(v, tmp);
}

static void	tri_tab(t_vector *v)
{
	size_t	i;
	size_t	j;
	char	**tab1;
	char	**tab2;

	i = 0;
	while (v->total > i)
	{
		tab1 = ft_strsplit(v->data[i], '-');
		j = 1 + i;
		while (v->total > j)
		{
			tab2 = ft_strsplit(v->data[j], '-');
			if (!ft_strcmp(tab1[0], tab2[0]))
			{
				j--;
				add_doors(v, tab2, i, j);
				i--;
				break ;
			}
			else
				j++;
		}
		i++;
	}
}

static void	del_end(t_vector *v, t_parse *p)
{
	char	**tab;

	if (v->total == 1)
		ft_error("Error !");
	p->i = 0;
	while (v->data[p->i])
	{
		tab = ft_strsplit(v->data[p->i], '-');
		if (!(ft_strcmp(tab[0], p->resolve.end)))
		{
			ft_vector_delat(v, p->i);
			break ;
		}
		p->i++;
	}
	p->i = 0;
}

static void	search_start(t_vector *v, t_parse *p)
{
	char	**tab;
	int		i;
	char	*space;
	char	*tmp;

	i = 1;
	p->resolve.limite = v->total;
	space = ft_strnew(1);
	space[0] = '-';
	while (p->i < v->total)
	{
		tab = ft_strsplit(v->data[p->i], '-');
		if (!ft_strcmp(p->resolve.start, tab[0]))
		{
			while (tab[i])
			{
				tmp = ft_strjoin(tab[0], space);
				tmp = ft_strjoin(tmp, tab[i]);
				ft_vector_add(v, tmp);
				i++;
			}
			break ;
		}
		p->i++;
	}
}

void		ft_resolve(t_vector *v, t_parse *p)
{
	tri_tab(v);
	ft_vector_add(v, "#");
	del_end(v, p);
	search_start(v, p);
	algo(v, p);
	clear(v, p);
}
