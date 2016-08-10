/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:51:44 by vklaouse          #+#    #+#             */
/*   Updated: 2016/05/10 16:54:28 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	tab_len(char **tab, t_parse *p)
{
	p->resolve.tab_len = 0;
	while (tab[p->resolve.tab_len])
		p->resolve.tab_len++;
	p->resolve.tab_len--;
}

void	vatefairezigouiller(t_vector *v, t_parse *p)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(v->data[1], '-');
	while (tab[i])
		i++;
	if (i - p->resolve.tab_len > 1)
		ft_vector_delat(v, 1);
}
