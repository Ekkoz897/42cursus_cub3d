/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:24:56 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/17 14:17:49 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	parsing_error(t_config *config, char *msg, int err_nbr)
{
	if (err_nbr == 2 || err_nbr == 3)
		free_textures(config);
	if (err_nbr == 4)
	{
		free_textures(config);
		free_ptp(config->map);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	return (1);
}
