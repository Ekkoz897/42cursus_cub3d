/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:42:04 by apereira          #+#    #+#             */
/*   Updated: 2024/01/30 16:14:45 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// checking for null os spaces -> when bumping into map border walls
// config->pos_x > x => north
// config->pos_x < x => south
// config->pos_y < y => east
// config->pos_y > y => west
// Hardcoded porque senao o player entra ligeiramente dentro da parede antes 
// de detetar collision.
int	check_xy(t_config *config, double x, double y)
{
	// printf("config->x: %d\nconfig->y: %d\n", (int)config->pos_x, (int)config->pos_y);
	// printf("x: %d\ny: %d\n", (int)(x + 0.1), (int)(y + 0.1));
	// printf("config->map: %c\n", config->map[(int)(x + 0.2)][(int)(y + 0.2)]);
	// if (config->map[(int)(x)][(int)(y)] == '\n'
	// 	|| ft_isspace(config->map[(int)x][(int)y])
	// 	|| config->map[(int)(x)][(int)(y)] == '\0')
	// 	return (0);
	if (config->map[(int)(x - 0.1)][(int)(y - 0.1)] == '1'
		|| config->map[(int)(x + 0.1)][(int)(y - 0.1)] == '1'
		|| config->map[(int)(x - 0.1)][(int)(y + 0.1)] == '1'
		|| config->map[(int)(x + 0.1)][(int)(y + 0.1)] == '1')
		return (0);
	// if ((config->pos_x > x && config->pos_y > y
	// 		&& config->map[(int)(x - 0.1)][(int)(y - 0.1)] != '1')
	// 	|| (config->pos_x < x && config->pos_y < y
	// 	&& config->map[(int)(x + 0.1)][(int)(y + 0.1)] != '1')
	// 	|| (config->pos_x > x && config->map[(int)(x - 0.1)][(int)y] != '1')
	// 	|| (config->pos_x < x && config->map[(int)(x + 0.1)][(int)y] != '1')
	// 	|| (config->pos_y > y && config->map[(int)(x)][(int)(y - 0.1)] != '1')
	// 	|| (config->pos_y < y && config->map[(int)(x)][(int)(y + 0.1)] != '1'))
	// 	return (1);
	return (1);
}

void	move_w(t_config *config)
{
	double	x;
	double	y;

	x = config->pos_x + 0.1 * config->dir_x;
	y = config->pos_y + 0.1 * config->dir_y;
	if (config->map[(int)x][(int)y] != '1' && check_xy(config, x, y))
	{
		config->pos_x = x;
		config->pos_y = y;
	}
}

void	move_s(t_config *config)
{
	double	x;
	double	y;

	x = config->pos_x - 0.1 * config->dir_x;
	y = config->pos_y - 0.1 * config->dir_y;
	if (config->map[(int)x][(int)y] != '1' && check_xy(config, x, y))
	{
		config->pos_x = x;
		config->pos_y = y;
	}
}

void	move_a(t_config *config)
{
	double	x;
	double	y;

	x = config->pos_x - 0.1 * config->dir_y;
	y = config->pos_y + 0.1 * config->dir_x;
	if (config->map[(int)x][(int)y] != '1' && check_xy(config, x, y))
	{
		config->pos_x = x;
		config->pos_y = y;
	}
}

void	move_d(t_config *config)
{
	double	x;
	double	y;

	x = config->pos_x + 0.1 * config->dir_y;
	y = config->pos_y - 0.1 * config->dir_x;
	if (config->map[(int)x][(int)y] != '1' && check_xy(config, x, y))
	{
		config->pos_x = x;
		config->pos_y = y;
	}
}
