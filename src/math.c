/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 08:51:49 by apereira          #+#    #+#             */
/*   Updated: 2024/01/14 09:30:20 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// camerax -> checks if the ray is on the left or right side of player
// ray0 -> calculates the x of the ray's direction
// ray1 -> calculates the y of the ray direction
// example -> if x=0 entao camerax=-1, ray will be casted to the left of the POV
double	*get_ray(t_config *config, double x)
{
	double	*ray;
	double	camerax;

	ray = malloc(sizeof(double) * 2);
	camerax = 2 * x / (double)WDW_WIDTH - 1;
	ray[0] = config->dir_x + config->plane_x * camerax;
	ray[1] = config->dir_y + config->plane_y * camerax;
	return (ray);
}

void	ft_calculations(t_config *config)
{
	double	x;
	double	*ray;
	double	*dist;

	x = 0;
	while (x < WDW_WIDTH - 1)
	{
		config->hit = 0;
		config->map_coord[0] = (int)config->pos_x;
		config->map_coord[1] = (int)config->pos_y;
		ray = get_ray(config, x);
		dist = get_distance(config, ray);
	}
}
