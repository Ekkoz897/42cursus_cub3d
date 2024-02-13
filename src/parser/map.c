/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:18:28 by ratavare          #+#    #+#             */
/*   Updated: 2024/02/13 14:48:27 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// Checks if the map area where the player spawns is
// valid, meaning the whole area must be bordered by
// '1' characters.

int	check_path(int x, int y, char **map)
{
	if (map[x][y] == '0' || map[x][y] == 'W'
	|| map[x][y] == 'E' || map[x][y] == 'S' || map[x][y] == 'N')
	{
		map[x][y] = '1';
		if (check_path(x, y - 1, map))
			return (1);
		if (check_path(x + 1, y, map))
			return (1);
		if (check_path(x, y + 1, map))
			return (1);
		if (check_path(x - 1, y, map))
			return (1);
	}
	else if (map[x][y] != '1')
		return (1);
	return (0);
}

// Based on its flag parameter, either fills a whole line with
// the '-' character, or adds it to it's extremities.
//  All lines are set to a sligtly bigger size than the
// largest line in the file, in order to avoid empty spots.

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

// Fills the surrounding area of the map with the '-' character.

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

// Extracts the map from the (char *) array gotten from the scene file.

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
	while (scfile_text[i - 1][0] != '\n' && i - 1 != 0)
		i--;
	map = ft_calloc(sizeof(char *), (end - i + 1));
	if (!map)
		return (NULL);
	j = 0;
	while (i < end)
		map[j++] = ft_strdup(scfile_text[i++]);
	return (map);
}

// Checks if the map is valid.

int	check_map(char **map)
{
	char	**tmp_map;
	int		player_pos[2];

	tmp_map = create_borders(map);
	get_player_pos(tmp_map, player_pos);
	if (!player_pos[0] && !player_pos[1])
		return (free_ptp(tmp_map), 1);
	if (check_path(player_pos[0], player_pos[1], tmp_map))
		return (free_ptp(tmp_map), 1);
	free_ptp(tmp_map);
	return (0);
}
