/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 08:44:57 by apereira          #+#    #+#             */
/*   Updated: 2024/01/22 16:28:40 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Receives the signal for each relevant pressed key and handles it
int	keyboard_handle(int key, t_config *config)
{
	double			old_x;

	if (key == ESC)
		ft_free_exit_cub(config);
	else if (key == KEY_W)
	{
		config->pos_x = config->pos_x + 0.1 * config->dir_x;
		config->pos_y = config->pos_y + 0.1 * config->dir_y;
	}
	else if (key == KEY_S)
	{
		config->pos_x = config->pos_x - 0.1 * config->dir_x;
		config->pos_y = config->pos_y - 0.1 * config->dir_y;
	}
	else if (key == KEY_D)
	{
		config->pos_x = config->pos_x + 0.1 * config->dir_y;
		config->pos_y = config->pos_y - 0.1 * config->dir_x;
	}
	else if (key == KEY_A)
	{
		config->pos_x = config->pos_x - 0.1 * config->dir_y;
		config->pos_y = config->pos_y + 0.1 * config->dir_x;
	}
	else if (key == KEY_LEFT)
	{
		old_x = config->dir_x;
		config->dir_x = config->dir_x * cos(PI / 100) - config->dir_y * sin(PI / 100);
		config->dir_y = config->dir_y * cos(PI / 100) + old_x * sin(PI / 100);
		old_x = config->plane_x;
		config->plane_x = config->plane_x * cos(PI / 100) - config->plane_y * sin(PI / 100);
		config->plane_y = config->plane_y * cos(PI / 100) + old_x * sin(PI / 100);
	}
	else if (key == KEY_RIGHT)
	{
		old_x = config->dir_x;
		config->dir_x = config->dir_x * cos(-PI / 100) - config->dir_y * sin(-PI / 100);
		config->dir_y = config->dir_y * cos(-PI / 100) + old_x * sin(-PI / 100);
		old_x = config->plane_x;
		config->plane_x = config->plane_x * cos(-PI / 100) - config->plane_y * sin(-PI / 100);
		config->plane_y = config->plane_y * cos(-PI / 100) + old_x * sin(-PI / 100);
	}
	return (0);
}
