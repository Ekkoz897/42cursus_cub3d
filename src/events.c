/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 08:44:57 by apereira          #+#    #+#             */
/*   Updated: 2024/01/14 08:45:48 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Receives the signal for each relevant pressed key and handles it
int	handle_keys(int key, t_config *config)
{
	if (key == ESC)
		ft_exit_cub(config);
	// else if (key == KEY_W)
	// 	move_w(config);
	// else if (key == KEY_S)
	// 	move_s(config);
	// else if (key == KEY_D)
	// 	move_d(config);
	// else if (key == KEY_A)
	// 	move_a(config);
	// else if (key == KEY_LEFT)
	// 	rotate_left(config);
	// else if (key == KEY_RIGHT)
	// 	rotate_right(config);
	return (0);
}
