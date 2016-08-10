/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 03:03:02 by vklaouse          #+#    #+#             */
/*   Updated: 2016/05/10 16:49:07 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/include/libft.h"

/*
** Structure for the resolution.
*/

typedef struct	s_resolve
{
	int			i;
	int			result;
	int			stop;
	int			ant;
	char		*start;
	char		*end;
	size_t		place;
	size_t		limite;
	size_t		tab_len;
}				t_resolve;

/*
** Structure for the parsing.
*/

typedef struct	s_parse
{
	size_t		k;
	size_t		j;
	size_t		i;
	int			cnt;
	int			e;
	int			s;
	int			*tab_len;
	int			w;
	int			c;
	int			alonepath;
	t_resolve	resolve;
}				t_parse;

/*
** Fonctions directice.
*/

int				main(int ac, char **av);
void			ft_error(char *s);

/*
** Fonctions for the parsing.
*/

void			parse_file(char *str, t_parse *p, t_vector *v);
void			check_tubes(char *str, t_parse *p, t_vector *v);
void			check_caca(t_vector *v, t_parse *p);

/*
** Fontions for the reolution.
*/

void			ft_resolve(t_vector *v, t_parse *p);
void			algo(t_vector *v, t_parse *p);
void			clear(t_vector *v, t_parse *p);
void			tab_len(char **tab, t_parse *p);

/*
** Display result.
*/

void			display_result(t_vector *v, t_parse *p);
void			cnt_paths(t_vector *v, t_parse *p);
void			vatefairezigouiller(t_vector *v, t_parse *p);

#endif
