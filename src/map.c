/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:18:28 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/16 17:36:10 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	border_line(char *map_line, char *new_line, int line_size, int flag)
{
	int		len;
	int		i;

	i = -1;
	if (flag)
	{
		len = ft_strlen(map_line);
		new_line[0] = '-';
		ft_memcpy(new_line + 1, map_line, len);
		while (new_line[++i])
			if (new_line[i] == 32)
				new_line[i] = '-';
		while (len < line_size - 1)
			new_line[len++] = '-';
		new_line[len] = '\n';
	}
	else
	{
		len = 0;
		while (len < line_size - 1)
			new_line[len++] = '-';
		new_line[len] = '\n';
	}
}

char	**create_borders(char **map)
{
	int		i;
	int		j;
	int		line_size;
	char	**new_map;

	i = 0;
	while (map[i])
		i++;
	new_map = ft_calloc(i + 3, sizeof(char *));
	j = -1;
	line_size = ft_longest_line_size(map) + 2;
	while (++j < i + 2)
		new_map[j] = ft_calloc(line_size + 1, sizeof(char));
	i = 0;
	border_line(NULL, new_map[0], line_size, 0);
	i = 0;
	j = 1;
	while (map[i])
		border_line(map[i++], new_map[j++], line_size, 1);
	border_line(NULL, new_map[j], line_size, 0);
	return (new_map);
}

int	check_map(char **map)
{
	char	**tmp_map;

	tmp_map = create_borders(map);
	for(int j = 0; j < 17; j++)
		printf("%s", tmp_map[j]);
	return (0);
}

char	**get_map(char **scfile_text)
{
	int		i;
	int		j;
	int		end;
	char	**map;

	i = 0;
	while (scfile_text[i])
		i++;
	while (scfile_text[i - 1][0] == '\n')
		i--;
	end = i;
	while (scfile_text[i - 1][0] != '\n')
		i--;
	map = ft_calloc(sizeof(char *), (end - i + 1));
	if (!map)
		return (NULL);
	j = 0;
	while (i < end)
		map[j++] = ft_strdup(scfile_text[i++]);
	return (map);
}
