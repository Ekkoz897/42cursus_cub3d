/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:32:00 by ratavare          #+#    #+#             */
/*   Updated: 2023/02/16 16:39:24 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin2(char *line, char *buffer)
{
	char	*newln;
	int		i;
	int		y;
	int		llen;
	int		blen;

	if (!buffer)
		return (NULL);
	llen = ft_strlen2(line);
	blen = ft_strlen2(buffer);
	newln = malloc(sizeof newln * (llen + blen) + 1);
	if (!newln)
		return (NULL);
	i = -1;
	y = -1;
	while (++i < llen)
		newln[i] = line[i];
	while (++y < blen)
		newln[i + y] = buffer[y];
	newln[i + y] = '\0';
	free (line);
	return (newln);
}

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_freebuffer(char *buffer, int fd)
{
	int	i;

	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		buffer[i] = 0;
		i++;
	}
	return (NULL);
}
