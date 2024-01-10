/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:22:15 by apereira          #+#    #+#             */
/*   Updated: 2024/01/10 17:21:50 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Initializes vars
void	vars_init(t_config *config)
{
	config->mlx = 0;
	config->wdw = 0;
	config->p_x = 0;
	config->p_y = 0;
	config->plane_x = 0;
	config->plane_y = 0;
	config->distance = 0;
	config->height = 0;
	// vars_init2(config); for later
}
