/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:26:42 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/15 15:28:35 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	parse_map(char **scfile_text, t_config *config)
{
	config->map = get_map(scfile_text);
	if (!config->map)
		return (1);
	free_ptp (scfile_text);
	check_map(config->map);
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
		return (printf("error3\n"), 1);
	i = 0;
	while (i <= 2)
		if (config->f[i] > 255 || config->c[i++] > 255)
			return (printf("error3\n"), 1);
	// printf("config->f:%u,%u,%u\n", config->f[0], config->f[1], config->f[2]);
	// printf("config->c:%u,%u,%u\n", config->c[0], config->c[1], config->c[2]);
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
		return (printf("error2\n"), 1);
	// printf("config->no:%s$\n", config->no);
	// printf("config->so:%s$\n", config->so);
	// printf("config->we:%s$\n", config->we);
	// printf("config->ea:%s$\n", config->ea);
	return (0);
}

// Main parsing function.

int	parser(char *src)

{
	t_config	config;
	char		**scfile_text;

	scfile_text = extract(src);
	if (!scfile_text)
		return (1);
	if (parse_textures(scfile_text, &config))
		return (1);
	if (parse_colors(scfile_text, &config))
		return (1);
	if (parse_map(scfile_text, &config))
		return (1);
	return (0);
}
