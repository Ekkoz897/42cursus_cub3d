/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:28:08 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/12 13:49:20 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_contains_str(char *scfile_line, char *contained)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

char	*ft_strndup(const char *s, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((ft_strlen((char *)s) * sizeof(char) + 1));
	if (!str)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
