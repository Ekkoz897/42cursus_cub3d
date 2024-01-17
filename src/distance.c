/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:29:48 by apereira          #+#    #+#             */
/*   Updated: 2024/01/17 12:45:37 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// calculates the step size of the ray in the x and y directions.
// if one of the coordinates of the ray is 0, there is no movement in that axys
double	*dist_1(double *ray)
{
	double	*dist;

	dist = malloc(sizeof(double) * 4);
	if (ray[0] != 0)
		dist[0] = fabs(1 / ray[0]);
	else
		dist[0] = -1;
	if (ray[1] != 0)
		dist[1] = fabs(1 / ray[1]);
	else
		dist[1] = -1;
	return (dist);
}

// Calculates the distancia from player to the next vertical grid line that the
// ray will hit.
// pos_x = exact player coordinates
// map->coord integer rounded player coordinates
double	*dist_2(t_config *config, double *ray, double *dist)
{
	if (ray[0] < 0 && dist[0] > 0)
	{
		config->step_x = -1;
		dist[2] = (config->pos_x - config->map_coord[0]) * dist[0];
	}
	else if (dist[0] > 0)
	{
		config->step_x = 1;
		dist[2] = (config->map_coord[0] + 1 - config->pos_x) * dist[0];
	}
	else
	{
		config->step_x = 0;
		dist[2] = INFINITY;
	}
	return (dist);
}

// dist[0] = distance between x axis
// dist[1] = distance between y axis
// dist[2] = distance from player position to x axys gridline
// dist[3] = distance from player position to y axys gridline
// If one of the vector coordinates is 0, it will never meet 
// the next gridline, which makes the distance infinite
double	*calculate_dist(t_config *config, double *ray)
{
	double	*dist;

	dist = dist_1(ray);
	dist = dist_2(config, ray, dist);
	if (ray[1] < 0 && dist[1] > 0)
	{
		config->step_y = 1;
		dist[3] = (config->map_coord[1] + 1 - config->pos_y) * dist[1];
	}
	else if (ray[1] >= 0 && dist[1] > 0)
	{
		config->step_y = 1;
		dist[3] = (config->map_coord[1] + 1 - config->pos_y) * dist[1];
	}
	else
	{
		config->step_y = 0;
		dist[3] = INFINITY;
	}
	return (dist);
}
