/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:18:28 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/15 16:25:35 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <string.h>

char	**create_borders(char **map)
{
	int		i;
	int		j;
	int		last;
	char	**new_map;

	i = 0;
	while (map[i])
		i++;
	printf("%d\n", i);
	new_map = ft_calloc(i + 2, sizeof(char *));
	j = -1;
	while (++j < i + 2)
		new_map[j] = ft_calloc(60, sizeof(char));
	i = 0;
	while (i <= (int)ft_strlen(map[0]))
		new_map[0][i++] = 'a';
	new_map[0][i] = '\n';
	j = 1;
	i = 0;
	while (map[i])
	{
		new_map[j][0] = 'a';
		ft_memcpy(new_map[j] + 1, map[i], ft_strlen(map[i]));
		last = ft_strlen(new_map[j]);
		new_map[j][last - 1] = 'a';
		new_map[j][last] = '\n';
		i++;
		j++;
	}
	i = 0;
	while (i <= (int)ft_strlen(new_map[j - 1]))
		new_map[j][i++] = 'a';
	return (new_map);
}

int	check_map(char **map)
{
	char	**tmp_map;

	tmp_map = create_borders(map);
	for(int j = 0; j < 16; j++)
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
