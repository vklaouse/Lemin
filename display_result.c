/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 06:07:51 by vklaouse          #+#    #+#             */
/*   Updated: 2016/05/10 16:53:09 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_doublon(t_vector *v, char *str, t_parse *p)
{
	char	**tab_tmp;
	char	**tab_tmp2;
	char	**tab_tmp3;

	tab_tmp = ft_strsplit(v->data[p->resolve.place], ' ');
	tab_tmp2 = ft_strsplit(str, '-');
	p->i = 0;
	if (p->resolve.stop == 1 && p->resolve.tab_len == 2)
	{
		p->resolve.result--;
		return (1);
	}
	while (tab_tmp[p->i])
	{
		tab_tmp3 = ft_strsplit(tab_tmp[p->i], '-');
		if (!ft_strcmp(tab_tmp3[0], tab_tmp2[0]))
			return (1);
		p->i++;
	}
	p->i = 0;
	return (0);
}

static void	recording_solution(int k, char **tab_tmp, t_parse *p, t_vector *v)
{
	char	*tmp;
	char	*tmp2;

	while (tab_tmp[k])
	{
		tmp = ft_strjoin("L", ft_itoa(p->resolve.i));
		tmp = ft_strjoin(tmp, "-");
		if (!ft_strcmp(tab_tmp[k], p->resolve.end) && p->c == 1)
			tmp = ft_strjoin(tmp, \
				ft_strjoin(ft_strjoin("\033[35m", tab_tmp[k]), "\033[m"));
		else
			tmp = ft_strjoin(tmp, tab_tmp[k]);
		if (p->resolve.i > 1 && !check_doublon(v, tmp, p))
		{
			tmp2 = ft_strjoin(v->data[p->resolve.place], " ");
			tmp2 = ft_strjoin(tmp2, tmp);
			ft_vector_add(v, tmp2);
			ft_vector_delat(v, p->resolve.place);
		}
		else
			ft_vector_add(v, tmp);
		k++;
	}
}

static void	soluce(t_vector *v, t_parse *p)
{
	int		j;
	int		k;
	char	**tab_tmp;

	j = 0;
	p->resolve.i = 1;
	if (!ft_strcmp(v->data[0], "#"))
		ft_error("Error !");
	while (p->resolve.ant >= p->resolve.i)
	{
		k = 1;
		tab_tmp = ft_strsplit(v->data[j], '-');
		p->resolve.place = p->resolve.result;
		recording_solution(k, tab_tmp, p, v);
		j++;
		if (j == p->resolve.stop)
		{
			p->resolve.result++;
			j = 0;
		}
		p->resolve.i++;
	}
}

static void	bonus(t_vector *v, t_parse *p)
{
	p->c = 0;
	write(1, "\n", 1);
	while (p->c < p->resolve.stop)
	{
		write(1, v->data[p->c], ft_strlen(v->data[p->c]));
		write(1, "\n", 1);
		p->c++;
	}
}

void		display_result(t_vector *v, t_parse *p)
{
	cnt_paths(v, p);
	vatefairezigouiller(v, p);
	p->resolve.stop = v->total;
	p->resolve.result = v->total + 1;
	ft_vector_add(v, "#");
	soluce(v, p);
	p->i = p->resolve.stop + 1;
	while (p->i < v->total)
	{
		write(1, v->data[p->i], ft_strlen(v->data[p->i]));
		write(1, "\n", 1);
		p->i++;
	}
	if (p->w == 1)
		bonus(v, p);
}
