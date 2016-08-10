/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 07:07:24 by vklaouse          #+#    #+#             */
/*   Updated: 2016/05/10 16:46:11 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	cheat_paths(t_parse *p, char **tab_tmp, t_vector *v)
{
	static int	i;
	int			tmp;

	tab_len(tab_tmp, p);
	tmp = p->resolve.tab_len - i;
	if (tmp > 1 && p->alonepath == 1)
		p->alonepath = -1;
	else if (tmp == 0 && p->alonepath == 1)
		p->alonepath--;
	else if (p->alonepath > 1 && tmp != 0)
		p->alonepath = -1;
	if (p->alonepath == -1)
		ft_vector_delat(v, v->total - 1);
	i = p->resolve.tab_len;
}

static int	search_doublon(char *tab_tmp, char **tab)
{
	int i;

	i = 0;
	while (tab_tmp && tab[i])
	{
		if (!ft_strcmp(tab_tmp, tab[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	search_paths(char **tab_tmp, char **tab, t_vector *v, t_parse *p)
{
	int		j;
	char	*tmp;
	char	*space;

	j = 1;
	space = ft_strnew(1);
	space[0] = '-';
	while (tab_tmp[j])
	{
		if (!search_doublon(tab_tmp[j], tab))
		{
			tmp = ft_strjoin(v->data[p->resolve.limite], space);
			tmp = ft_strjoin(tmp, tab_tmp[j]);
			ft_vector_add(v, tmp);
		}
		if (!ft_strcmp(tab_tmp[j], p->resolve.end))
		{
			cheat_paths(p, tab, v);
			if (p->alonepath == -1)
				break ;
			p->alonepath++;
		}
		j++;
	}
}

void		algo(t_vector *v, t_parse *p)
{
	char	**tab;
	char	**tab_tmp;

	p->alonepath = 0;
	while (p->resolve.limite < v->total)
	{
		p->i = 0;
		tab = ft_strsplit(v->data[p->resolve.limite], '-');
		tab_len(tab, p);
		while (p->i < v->total)
		{
			tab_tmp = ft_strsplit(v->data[p->i], '-');
			if (!ft_strcmp(tab[p->resolve.tab_len], tab_tmp[0]))
			{
				search_paths(tab_tmp, tab, v, p);
				break ;
			}
			p->i++;
		}
		if (p->alonepath == -1)
			break ;
		p->resolve.limite++;
	}
}
