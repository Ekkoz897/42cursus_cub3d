/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:03:17 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/12 20:16:02 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// For memory allocation purposes, counts the number
// of lines present in the scene file.

int	count_lines(char *src)
{
	int		i;
	int		fd;
	char	*tmp;

	fd = open(src, O_RDONLY);
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		free(tmp);
		i++;
	}
	close(fd);
	return (i);
}

// Extracts the scene file's text.

char	**extract(char *src)
{
	int		fd;
	int		i;
	char	**scfile_text;

	fd = open(src, O_RDONLY);
	if (fd == -1)
		return (printf("error1\n"), NULL);
	scfile_text = malloc(sizeof(char *) * (count_lines(src) + 1));
	if (!scfile_text)
		return (NULL);
	i = 0;
	while (1)
	{
		scfile_text[i++] = get_next_line(fd);
		if (scfile_text[i - 1] == NULL)
			break ;
	}
	return (scfile_text);
}
