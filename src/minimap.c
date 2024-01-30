/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:56:13 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/30 14:00:38 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_print_player(t_config *config)
{
	int	y;
	int	x;

	y = -1;
	while (y < 2)
	{
		x = -1;
		while (x < 2)
		{
			ft_mlx_pixel_put(config, config->pos_y * 8 + 5 + x,config->pos_x * 8 + 5 + y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void	ft_minimap(t_config *config)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < config->map_height * 8)
	{
		x = 0;
		while (x < config->map_width * 8)
		{
			if (config->map[y / 8][x / 8] == '1')
				color = 0xFFFFFF;
			else
				color = 0x444444;
			ft_mlx_pixel_put(config, x + 5, y + 5, color);
			x++;
		}
		y++;
	}
	ft_print_player(config);
}
