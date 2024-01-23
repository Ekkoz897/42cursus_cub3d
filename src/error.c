/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:24:56 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/23 00:40:13 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	parsing_error(t_config *config, char *msg, int err_nbr)
{
	if (err_nbr == 1)
	{
		free(config->map_coord);
		free(config->textures);
		free(config->colors);
	}
	if (err_nbr == 2 || err_nbr == 3)
	{
		free(config->map_coord);
		free_textures(config);
		free(config->colors);
	}
	if (err_nbr == 4)
	{
		free_ptp(config->textures);
		free_ptp(config->map);
		free(config->colors);
		free(config->map_coord);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	return (1);
}
