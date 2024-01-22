/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:42:04 by apereira          #+#    #+#             */
/*   Updated: 2024/01/22 12:02:49 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move_w(t_config *config)
{
	if (config->map[(int)(config->pos_x + 0.1 * config->dir_x)][(int)(config->pos_y + 0.1 * config->dir_y)] != '1')
	{
		config->pos_x = config->pos_x + 0.1 * config->dir_x;
		config->pos_y = config->pos_y + 0.1 * config->dir_y;
	}
}

void	move_s(t_config *config)
{
	if (config->map[(int)(config->pos_x - 0.1 * config->dir_x)][(int)(config->pos_y - 0.1 * config->dir_y)] != '1')
	{
		config->pos_x = config->pos_x - 0.1 * config->dir_x;
		config->pos_y = config->pos_y - 0.1 * config->dir_y;
	}
}

void	move_a(t_config *config)
{
	if (config->map[(int)(config->pos_x - 0.1 * config->dir_y)][(int)(config->pos_y + 0.1 * config->dir_x)] != '1')
	{
		config->pos_x = config->pos_x - 0.1 * config->dir_y;
		config->pos_y = config->pos_y + 0.1 * config->dir_x;
	}
}

void	move_d(t_config *config)
{
	if (config->map[(int)(config->pos_x + 0.1 * config->dir_y)][(int)(config->pos_y - 0.1 * config->dir_x)] != '1')
	{
		config->pos_x = config->pos_x + 0.1 * config->dir_y;
		config->pos_y = config->pos_y - 0.1 * config->dir_x;
	}
}
