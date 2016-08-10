/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 02:13:15 by vklaouse          #+#    #+#             */
/*   Updated: 2016/05/10 17:01:02 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	clear_tab(t_vector *v)
{
	size_t	i;
	char	**tab;

	i = 0;
	while (i < v->total)
	{
		tab = ft_strsplit(v->data[i], '-');
		if (!tab[1])
		{
			ft_vector_delat(v, i);
			i--;
		}
		i++;
	}
}

static void	init(t_parse *p)
{
	p->cnt = 0;
	p->i = 0;
	p->e = 0;
	p->s = 0;
	p->resolve.ant = 0;
	p->resolve.stop = 1;
	p->w = 0;
	p->c = 0;
	p->resolve.tab_len = 0;
	p->resolve.start = NULL;
	p->resolve.end = NULL;
	p->alonepath = 0;
}

static void	parse_flags(char **av, t_parse *p)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (!ft_strcmp("-w", av[i]) && p->w == 0)
			p->w = 1;
		else if (!ft_strcmp("-c", av[i]) && p->c == 0)
			p->c = 1;
		else
			ft_error("Error !");
		i++;
	}
}

void		ft_error(char *s)
{
	ft_putendl(s);
	exit(0);
}

int			main(int ac, char **av)
{
	char		*str;
	t_parse		p;
	t_vector	v;

	init(&p);
	if (ac)
		parse_flags(av, &p);
	ft_vector_init(&v, 0);
	while ((get_next_line(0, &str)))
	{
		if (str[0] && p.alonepath == 0)
			parse_file(str, &p, &v);
		else
			break ;
		ft_printf("%s\n", str);
		ft_strdel(&str);
	}
	if (p.e != 2 || p.s != 2 || \
		p.resolve.start == NULL || p.resolve.end == NULL)
		ft_error("Error !");
	if (p.resolve.ant == 0)
		ft_error("Error !");
	clear_tab(&v);
	ft_resolve(&v, &p);
	return (0);
}
