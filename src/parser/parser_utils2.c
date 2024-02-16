/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:05:26 by ratavare          #+#    #+#             */
/*   Updated: 2024/02/16 17:01:14 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// Checks for different parts.

int	check_fdp(char *scfile_line)
{
	int	i;

	i = 0;
	while (ft_isspace(scfile_line[i]))
		i++;
	if (ft_isalpha(scfile_line[i]))
		i++;
	while (ft_isspace(scfile_line[i]))
		i++;
	while (scfile_line[i])
	{
		if (!ft_isdigit(scfile_line[i]) && \
		scfile_line[i] != ',' && scfile_line[i] != 32 && \
		scfile_line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_color_count(char *scfile_line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (scfile_line[i])
	{
		if (!ft_isdigit(scfile_line[i]))
			i++;
		else
		{
			count++;
			while (ft_isdigit(scfile_line[i]))
				i++;
		}
	}
	if (count != 3)
		return (1);
	return (0);
}

int	check_commas(char *scfile_line)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (scfile_line[++i])
		if (scfile_line[i] == ',')
			count++;
	if (count != 2)
		return (1);
	i = 0;
	count = 0;
	if (check_color_count(scfile_line))
		return (1);
	if (check_fdp(scfile_line))
		return (1);
	return (0);
}
