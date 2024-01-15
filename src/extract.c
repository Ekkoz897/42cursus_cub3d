/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:03:17 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/15 13:47:26 by ratavare         ###   ########.fr       */
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

// Counts the amount of tabs in a given string.

int	count_tabs(char *scfile_line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (scfile_line[i])
	{
		if (scfile_line[i++] == '\t')
			count++;
	}
	return (count);
}

// Replaces any tab found with 4 spaces, reallocating the whole line.

char	*replace_tabs(char *scfile_line)
{
	int		i;
	int		y;
	int		j;
	char	*new_line;

	i = count_tabs(scfile_line);
	if (i != 0)
	{
		new_line = malloc((ft_strlen(scfile_line) + i * 4) * sizeof(char));
		i = -1;
		y = 0;
		while (scfile_line[++i])
		{
			j = 0;
			if (scfile_line[i] == '\t')
				while (j++ < 4)
					new_line[y++] = 32;
			else
				new_line[y++] = scfile_line[i];
		}
		new_line[y] = '\0';
		free (scfile_line);
		return (new_line);
	}
	return (scfile_line);
}

// Extracts the scene file's text and replaces all tabs with 4 spaces.

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
	i = -1;
	while (scfile_text[++i])
		scfile_text[i] = replace_tabs(scfile_text[i]);
	return (scfile_text);
}
