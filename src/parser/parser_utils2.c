/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:05:26 by ratavare          #+#    #+#             */
/*   Updated: 2024/02/14 16:42:01 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_fdp(char *scfile_line)
{
	int	i;

	i = 0;
	while (ft_isspace(scfile_line[i]))
		i++;
	
}

int	check_color_count(char *scfile_line)
{
	static int	i;
	static int	count;
	int			len;

	len = ft_strlen(scfile_line);	
	while (!ft_isdigit(scfile_line[i]) && i < len)
		i++;
	if (ft_isdigit(scfile_line[i]))
	{
		if (ft_isspace(scfile_line[i -1]) || count != 0)
			count++;
		while (ft_isdigit(scfile_line[i]) && i < len)
			i++;
	}
	if (scfile_line[i])
		check_color_count(scfile_line);
	if (count != 3)
		return (1);
	else
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
	if (check_color_count(scfile_line))
		return (1);
	return (0);
}
