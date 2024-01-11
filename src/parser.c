/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:26:42 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/11 17:01:09 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_textures(char **scfile_text, t_config	*config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (scfile_text[j])
	{
		
	}
}

int	parse_textures(char **scfile_text, t_config	*config)
{
	if (check_textures)
		return (1);
}

int	parser(char *src)
{
	t_config	config;
	char		**scfile_text;

	scfile_text = extract(src);
	return (0);
}
