/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 21:41:21 by vklaouse          #+#    #+#             */
/*   Updated: 2016/05/10 16:59:02 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_coordinate(char **tab, t_parse *p)
{
	while (tab[1][p->cnt])
	{
		if (!ft_isdigit(tab[1][p->cnt]))
			ft_error("Error !");
		p->cnt++;
	}
	p->cnt = 0;
	while (tab[2][p->cnt])
	{
		if (!ft_isdigit(tab[2][p->cnt]))
			ft_error("Error !");
		p->cnt++;
	}
	if (p->s == 1)
	{
		p->s++;
		p->resolve.start = ft_strdup(tab[0]);
	}
	else if (p->e == 1)
	{
		p->e++;
		p->resolve.end = ft_strdup(tab[0]);
	}
	free(tab);
}

static void	check_ant(char *str, t_parse *p)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			ft_error("Error !");
		i++;
	}
	if ((p->resolve.ant = ft_atoi(str)) <= 0)
		ft_error("Error !");
	if (p->resolve.ant > 1000000)
		ft_error("Error !");
}

static void	check_comments(char *str, t_parse *p)
{
	if (!(ft_strcmp(str, "##start")))
		p->s++;
	else if (!(ft_strcmp(str, "##end")))
		p->e++;
	else
		p->i--;
}

static void	check_rooms(char *str, t_vector *v, t_parse *p)
{
	char **tab;

	tab = ft_strsplit(str, ' ');
	if (tab[1] && tab[2] && !tab[3])
	{
		check_coordinate(tab, p);
		ft_vector_add(v, tab[0]);
	}
	else
		check_tubes(str, p, v);
}

void		parse_file(char *str, t_parse *p, t_vector *v)
{
	if (p->i == 0 && str[0] != '#')
		check_ant(str, p);
	else if (str[0] == '#')
		check_comments(str, p);
	else if (str[0] != '#' && str[0] != 'L')
		check_rooms(str, v, p);
	p->i++;
}
