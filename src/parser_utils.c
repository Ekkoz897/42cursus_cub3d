/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:28:08 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/14 16:11:38 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
	while (scfile_line[i] != '.')
		i++;
	if (id == 1)
		config->so = ft_strndup(scfile_line + i, \
		ft_strlen(scfile_line + i) - 1);
	if (id == 2)
		config->no = ft_strndup(scfile_line + i, \
		ft_strlen(scfile_line + i) - 1);
	if (id == 3)
		config->we = ft_strndup(scfile_line + i, \
		ft_strlen(scfile_line + i) - 1);
	if (id == 4)
		config->ea = ft_strndup(scfile_line + i, \
		ft_strlen(scfile_line + i) - 1);
	count[0]++;
}
