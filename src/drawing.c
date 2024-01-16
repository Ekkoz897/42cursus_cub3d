/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:56:21 by apereira          #+#    #+#             */
/*   Updated: 2024/01/16 12:42:00 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// height of the wall on the screen
// start and end -> where the wall begins and ends on the screen
void	get_picture_vars(t_config *config, int side, double *dist)
{
	if (side == 0)
		config->distance = (dist[2] - dist[0]);
	else
		config->distance = (dist[3] - dist[1]);
	config->height = WDW_HEIGHT / config->distance;
	config->start = WDW_HEIGHT / 2 - config->height / 2;
	config->end = WDW_HEIGHT / 2 + config->height / 2;
}

void	drawing(int x, t_config *config, double *dist, double *ray)
{
	int				y;
	unsigned int	color;

	y = 0;
	get_picture_vars(config, config->side, dist);
}
