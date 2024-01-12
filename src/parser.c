/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:26:42 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/12 13:49:51 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
		return (printf("error\n"), 1);
	return (0);
}

int	parser(char *src)

{
	t_config	config;
	char		**scfile_text;

	scfile_text = extract(src);
	if (parse_textures(scfile_text, &config))
		return (1);
	return (0);
}
