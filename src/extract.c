/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:03:17 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/09 17:15:20 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scene.h"

/* For memory allocation purposes, counts the number 
   of lines present in the scene file */

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

// Extracts the scene file's text and normalizes the white spaces

int	extract(char *src, t_config *config)
{
	int	fd;
	int	i;

	fd = open(src, O_RDONLY);
	if (fd == -1)
		return (printf("error\n"), 1);
	config->scfile_text = malloc(sizeof(char *) * (count_lines(src) + 1));
	i = 0;
	while (1)
	{
		config->scfile_text[i++] = get_next_line(fd);
		if (config->scfile_text[i - 1] == NULL)
			break ;
	}
	for (int j = 0; j < 23; j++)
		printf("%s", config->scfile_text[j]);
	return (0);
}
