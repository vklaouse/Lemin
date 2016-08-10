/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:59:49 by vklaouse          #+#    #+#             */
/*   Updated: 2016/01/20 15:57:41 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_del(char **stk)
{
	if (stk != NULL)
	{
		free(*stk);
		*stk = NULL;
	}
	return (0);
}

static char	*ft_join(char *stk, char *buf)
{
	char		*tmp;

	tmp = stk;
	stk = ft_strjoin(tmp, buf);
	ft_strdel(&tmp);
	return (stk);
}

static char	*ft_sub(char *stk)
{
	char		*tmp;

	tmp = stk;
	stk = ft_strsub(tmp, ft_strchr(tmp, '\n') - tmp + 1, \
		ft_strlen(ft_strchr(tmp, '\n')));
	ft_strdel(&tmp);
	return (stk);
}

int			get_next_line(int const fd, char **line)
{
	static char	*stk[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	ret = 1;
	if (BUFF_SIZE < 1 || !line || fd < 0)
		return (-1);
	if (!stk[fd])
		stk[fd] = ft_strnew(0);
	while (!(ft_strchr(stk[fd], '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		stk[fd] = ft_join(stk[fd], buf);
	}
	if (ret < 0)
		return (-1);
	*line = ft_strchr(stk[fd], '\n') ? ft_strsub(stk[fd], 0, \
			ft_strchr(stk[fd], '\n') - stk[fd] + 1) : ft_strdup(stk[fd]);
	if (ft_strlen(*line) == 0)
		return (ft_del(&stk[fd]));
	if (ret)
		line[0][ft_strlen(*line) - 1] = '\0';
	stk[fd] = ft_sub(stk[fd]);
	return (1);
}
