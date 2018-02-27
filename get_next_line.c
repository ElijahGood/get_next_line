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




int		get_next_line(const int fd, char **line)
{
	static char	*res;
	char 		buf[BUFF_SIZE + 1];
	ssize_t 	bytes;

	//static int cntr = 1;

	if (BUFF_SIZE < 1 || !line || (bytes = read(fd, "", 0) == -1))
		return (-1);
	*line = ft_strnew(0);
	while ((bytes = read(fd, buf, BUFF_SIZE)))
	{
		buf[bytes] = '\0';
		if (res == NULL)
			res = ft_strnew(0);
		res = ft_strjoin(res, buf);
		
		if (ft_strchr(res, '\n'))
		{
			*line = ft_strsub(res, 0, ft_strchr(res, '\n') - res);
			res = ft_strdup(ft_strchr(res, '\n') + 1);
			//printf("loop:\nline = %s\nres = %s\n\n", *line, res);
			//printf("return");
			return (1);
		}
	}
	if (res == NULL)
		return (0);
	if (ft_strchr(res, '\n'))
	{
		*line = ft_strsub(res, 0, ft_strchr(res, '\n') - res);
		res = ft_strdup(ft_strchr(res, '\n') + 1);
		return (1);
	}
	else if (ft_strchr(res, '\0') && ft_strlen(res) > 0)
	{
		*line = ft_strdup(res);
		ft_strdel(&res);
		return (1);
	}
	//printf("line = %s\nres = %s\n", *line, res);
	return (0);
}


//#include <stdio.h>

// int main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	int 	counter = 1;

// 	if (argc || argv)
//   		;
// 	fd = open("file1.txt", O_RDONLY);
// 	// line = ft_strnew(100);
// 	while (get_next_line(fd, &line))
// 	{
// 		printf("%d: %s\n", counter,line);
// 		counter++;
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }