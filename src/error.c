/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:24:56 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/22 18:43:43 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	parsing_error(t_config *config, char *msg, int err_nbr)
{
	if (err_nbr == 2 || err_nbr == 3)
		free(config->textures);
	if (err_nbr == 4)
	{
		free(config->textures);
		free_ptp(config->map);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	return (1);
}
