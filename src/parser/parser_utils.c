/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:28:08 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/18 21:50:12 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// Defines the player position in map and 
// checks for player indentifier duplicates.

void	get_player_pos(char **map, int *pos)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'W' || map[x][y] == 'E' 
			|| map[x][y] == 'S' || map[x][y] == 'N')
			{
				count++;
				pos[0] = x;
				pos[1] = y;
			}
		}
	}
	if (count != 1)
	{
		pos[0] = 0;
		pos[1] = 0;
	}
}

// Returns the size of the longest line in a (char *) array.

int	ft_longest_line_size(char	**ptp)
{
	int	i;
	int	size;
	int	l_size;

	i = 0;
	size = 0;
	l_size = 0;
	while (ptp[i])
	{
		size = (int)ft_strlen(ptp[i]);
		if (l_size < size)
			l_size = size;
		i++;
	}
	return (l_size);
}

// Checks if *contained existes at the begining of a given string,
// excluding any inital spaces.

int	ft_contains_str(char *scfile_line, char *contained)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (scfile_line[i] == 32)
		i++;
	while (contained[j])
	{
		if (contained[j++] == scfile_line[i])
			i++;
		else
			return (1);
	}
	if (scfile_line[i] != 32)
		return (1);
	return (0);
}

// Adds the RGB scheme to a 3 slot unsinged int array present in
// the t_config structure.

void	ft_add_colors(char *scfile_line, int *count, t_config *config, int id)
{
	int	i;
	int	j;

	(void)id;
	i = 0;
	while (!ft_isdigit(scfile_line[i]) && scfile_line[i] != '-')
		i++;
	j = 0;
	while (j <= 2)
	{
		if (id == 1)
			config->f[j] = ft_atoi(scfile_line + i);
		if (id == 2)
			config->c[j] = ft_atoi(scfile_line + i);
		while (ft_isdigit(scfile_line[i]) || scfile_line[i] == 32 \
		|| scfile_line[i] == '-')
			i++;
		i++;
		j++;
	}
	count[0]++;
}

// Allocates the texture paths into they're respective variable
// based on a given id.

void	ft_add_textures(char *scfile_line, int *count, t_config *config, int id)
{
	int	i;

	i = 0;
	while (scfile_line[i] == 'N' || scfile_line[i] == 'A' ||\
	scfile_line[i] == 'E' || scfile_line[i] == 'O' || scfile_line[i] == 'S' \
	|| scfile_line[i] == 'W' || scfile_line[i] == 32)
		i++;
	if (id == 1)
		config->textures[0] = ft_strndup(scfile_line + i, \
		ft_strlen(scfile_line + i) - 1);
	if (id == 2)
		config->textures[1] = ft_strndup(scfile_line + i, \
		ft_strlen(scfile_line + i) - 1);
	if (id == 3)
		config->textures[3] = ft_strndup(scfile_line + i, \
		ft_strlen(scfile_line + i) - 1);
	if (id == 4)
		config->textures[2] = ft_strndup(scfile_line + i, \
		ft_strlen(scfile_line + i) - 1);
	count[0]++;
}
