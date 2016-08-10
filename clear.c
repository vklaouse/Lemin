/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 02:00:50 by vklaouse          #+#    #+#             */
/*   Updated: 2016/05/10 15:30:00 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	clear_doors(t_vector *v, t_parse *p)
{
	p->i = 0;
	while (p->i < v->total)
	{
		if (ft_strcmp(v->data[p->i], "#"))
			ft_vector_delat(v, p->i);
		else if (!ft_strcmp(v->data[p->i], "#"))
		{
			ft_vector_delat(v, p->i);
			break ;
		}
		else
			p->i++;
	}
}

static void	valid_path(t_vector *v, t_parse *p)
{
	char **tab;

	p->i = 0;
	while (p->i < v->total)
	{
		tab = ft_strsplit(v->data[p->i], '-');
		tab_len(tab, p);
		if (ft_strcmp(tab[p->resolve.tab_len], p->resolve.end))
			ft_vector_delat(v, p->i);
		else
			p->i++;
	}
}

static void	del_paths(t_vector *v, t_parse *p, char **tab1, char **tab2)
{
	while (p->k < p->resolve.tab_len)
	{
		p->s = 1;
		while (tab2[p->s])
		{
			if (!ft_strcmp(tab1[p->k], tab2[p->s]))
			{
				ft_vector_delat(v, p->i);
				p->i--;
				p->resolve.stop = 0;
				break ;
			}
			p->s++;
		}
		if (p->resolve.stop == 0)
			break ;
		p->k++;
	}
}

static void	useful_paths(t_vector *v, t_parse *p)
{
	char	**tab1;
	char	**tab2;

	p->i = 1;
	while (p->i < v->total)
	{
		p->j = 0;
		tab1 = ft_strsplit(v->data[p->i], '-');
		while (p->j < p->i)
		{
			p->k = 1;
			tab2 = ft_strsplit(v->data[p->j], '-');
			tab_len(tab1, p);
			del_paths(v, p, tab1, tab2);
			if (p->resolve.stop == 0)
				break ;
			p->j++;
		}
		p->resolve.stop = 1;
		p->i++;
	}
	p->i = 0;
}

void		clear(t_vector *v, t_parse *p)
{
	clear_doors(v, p);
	valid_path(v, p);
	useful_paths(v, p);
	write(1, "\n", 1);
	check_caca(v, p);
	display_result(v, p);
	free(v->data);
}
