/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 08:44:57 by apereira          #+#    #+#             */
/*   Updated: 2024/01/21 17:59:42 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Receives the signal for each relevant pressed key and handles it
int	keyboard_handle(int key, t_config *config)
{
	static double	x_step;
	// double			dist;

	if (key == ESC)
		ft_free_exit_cub(config);
	else if (key == KEY_W)
	{
		config->pos_y -= 0.05;
		config->pos_x += x_step;
	}
	else if (key == KEY_S)
		config->pos_y += 0.05;
	else if (key == KEY_D)
		config->pos_x -= 0.05;
	else if (key == KEY_A)
		config->pos_x += 0.05;
	else if (key == KEY_LEFT)
	{
		x_step += 0.005;
		config->dir_x = config->dir_x + 0.1;
		config->dir_y = config->dir_y + 0.1;
		config->plane_x = config->plane_x + 0.066;
		config->plane_y = config->plane_y - 0.066;
	}
	// else if (key == KEY_RIGHT)
	// 	rotate_right(config);
	return (0);
}
