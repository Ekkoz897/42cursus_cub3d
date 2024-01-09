/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:32:00 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/30 17:06:31 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			i;
	int			y;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (ft_freebuffer(buffer[fd], fd));
	line = NULL;
	flag = 0;
	while (!flag && (buffer[fd][0] || (read(fd, buffer[fd], BUFFER_SIZE) > 0)))
	{
		i = 0;
		y = 0;
		line = ft_strjoin2(line, buffer[fd]);
		while (buffer[fd][i])
		{
			if (flag)
				buffer[fd][y++] = buffer[fd][i];
			if (buffer[fd][i] == '\n')
				flag = 1;
			buffer[fd][i++] = 0;
		}
	}
	return (line);
}
