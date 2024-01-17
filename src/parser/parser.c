/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:26:42 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/17 20:27:52 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// Gets the map from the scene file and checks if its valid.

int	parse_map(char **scfile_text, t_config *config)
{
	int		i;
	int		temp_pos[2];

	config->map = get_map(scfile_text);
	if (!config->map)
		return (1);
	free_ptp(scfile_text);
	if (check_map(config->map))
		return (1);
	i = 0;
	while (config->map[i])
		i++;
	config->map_height = i;
	config->map_width = (ft_longest_line_size(config->map) - 1);
	get_player_pos(config->map, temp_pos);
	config->pos_x = temp_pos[1];
	config->pos_y = temp_pos[0];
	return (0);
}

// Cheks if exists and adds the defined RGB scheme to its
// respective variable in the t_config structure.

int	parse_colors(char **scfile_text, t_config *config)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (scfile_text[i])
	{
		if (!ft_contains_str(scfile_text[i], "F"))
			ft_add_colors(scfile_text[i], &count, config, 1);
		if (!ft_contains_str(scfile_text[i], "C"))
			ft_add_colors(scfile_text[i], &count, config, 2);
		i++;
	}
	if (count != 2)
		return (1);
	i = 0;
	while (i <= 2)
		if (config->f[i] > 255 || config->c[i++] > 255)
			return (1);
	return (0);
}

// Cheks if exists and adds the texture file path to its
// respective variable in the t_config structure.

int	parse_textures(char **scfile_text, t_config	*config)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (scfile_text[i])
	{
		if (!ft_contains_str(scfile_text[i], "SO"))
			ft_add_textures(scfile_text[i], &count, config, 1);
		if (!ft_contains_str(scfile_text[i], "NO"))
			ft_add_textures(scfile_text[i], &count, config, 2);
		if (!ft_contains_str(scfile_text[i], "WE"))
			ft_add_textures(scfile_text[i], &count, config, 3);
		if (!ft_contains_str(scfile_text[i], "EA"))
			ft_add_textures(scfile_text[i], &count, config, 4);
		i++;
	}
	if (count != 4)
		return (1);
	return (0);
}

// Main parsing function.

int	parser(char *src, t_config *config)

{
	char		**scfile_text;

	scfile_text = extract(src);
	if (!scfile_text)
		return (printf("error1\n"), 1);
	if (parse_textures(scfile_text, config))
		return (free_ptp(scfile_text), \
		parsing_error(config, "Invalid texture indentifiers.\n", 2));
	if (parse_colors(scfile_text, config))
		return (free_ptp(scfile_text), \
		parsing_error(config, "Invalid colors or identifiers.\n", 3));
	if (parse_map(scfile_text, config))
		return (parsing_error(config, "Invalid map.\n", 4));
	return (0);
}
