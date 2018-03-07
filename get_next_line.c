/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazarin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:14:03 by inazarin          #+#    #+#             */
/*   Updated: 2018/01/03 14:15:42 by inazarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_magic(char **line, char *res)
{
	char	*tmp;

	if (ft_strchr(res, '\n'))
	{
		tmp = ft_strdup(res);
		*line = ft_strsub(res, 0, ft_strchr(res, '\n') - res);
		ft_strdel(&res);
		res = ft_strdup(ft_strchr(tmp, '\n') + 1);
		ft_strdel(&tmp);
	}
	else
	{
		*line = ft_strdup(res);
		ft_strdel(&res);
	}
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	static char	*res;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		bytes;

	if (fd < 0 || BUFF_SIZE < 1 || !line || (bytes = read(fd, "", 0)) < 0)
		return (-1);
	res = res ? res : ft_strnew(0);
	while ((bytes = read(fd, buf, BUFF_SIZE)))
	{
		buf[bytes] = '\0';
		tmp = res;
		res = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if (ft_strchr(res, '\n') || (ft_strchr(res, '\0') && ft_strlen(res) > 0))
	{
		res = ft_magic(line, res);
		return (1);
	}
	return (0);
}
