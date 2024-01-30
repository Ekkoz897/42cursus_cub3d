/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:56:13 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/30 15:04:38 by ratavare         ###   ########.fr       */
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

	y = -1;
	while (++y < config->map_height * 8)
	{
		x = -1;
		while (++x < config->map_width * 8)
		{
			if (config->map[y / 8][x / 8] == '1')
				color = 0xFFFFFF;
			else if (config->map[y / 8][x / 8] == '0')
				color = 0x444444;
			else if (!ft_isalpha(config->map[y / 8][x / 8]))
				color = 0;
			if (color != 0)
				ft_mlx_pixel_put(config, x + 5, y + 5, color);
		}
	}
	ft_print_player(config);
}
