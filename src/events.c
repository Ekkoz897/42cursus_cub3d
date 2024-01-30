/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 08:44:57 by apereira          #+#    #+#             */
/*   Updated: 2024/01/30 13:59:58 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	mouse_handle(int x, int y, t_config *config)
{
	static int	curr_x;
	static int	prev_x;

	(void)y;
	prev_x = curr_x;
	curr_x = x;
	if (x > prev_x)
		look_right(config);
	if (x < prev_x)
		look_left(config);
	// if (x > WDW_WIDTH / 2)
	// 	look_right(config);
	// if (x < WDW_WIDTH / 2)
	// 	look_left(config);
	// mlx_mouse_move(config->mlx, config->wdw, WDW_WIDTH / 2, WDW_HEIGHT / 2);
	return (0);
}

// Receives the signal for each relevant pressed key and handles it
int	keyboard_handle(int key, t_config *config)
{
	if (key == ESC)
		ft_free_exit_cub(config);
	else if (key == KEY_W)
		move_w(config);
	else if (key == KEY_S)
		move_s(config);
	else if (key == KEY_A)
		move_a(config);
	else if (key == KEY_D)
		move_d(config);
	else if (key == KEY_LEFT)
		look_left(config);
	else if (key == KEY_RIGHT)
		look_right(config);
	return (0);
}

void	look_left(t_config *config)
{
	double			old_x;

	old_x = config->dir_x;
	config->dir_x = config->dir_x * cos(PI / 100) - config->dir_y * \
		sin(PI / 100);
	config->dir_y = config->dir_y * cos(PI / 100) + old_x * sin(PI / 100);
	old_x = config->plane_x;
	config->plane_x = config->plane_x * cos(PI / 100) - config->plane_y \
		* sin(PI / 100);
	config->plane_y = config->plane_y * cos(PI / 100) + old_x * sin(PI / 100);
}

void	look_right(t_config *config)
{
	double			old_x;

	old_x = config->dir_x;
	config->dir_x = config->dir_x * cos(-PI / 100) - config->dir_y * \
		sin(-PI / 100);
	config->dir_y = config->dir_y * cos(-PI / 100) + old_x * sin(-PI / 100);
	old_x = config->plane_x;
	config->plane_x = config->plane_x * cos(-PI / 100) - config->plane_y * \
		sin(-PI / 100);
	config->plane_y = config->plane_y * cos(-PI / 100) + old_x * sin(-PI / 100);
}
