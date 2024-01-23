/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:56:21 by apereira          #+#    #+#             */
/*   Updated: 2024/01/22 23:48:28 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// height of the wall on the screen
// start and end -> where the wall begins and ends on the screen
void	get_image_vars(t_config *config, int side, double *dist)
{
	if (side == 0)
		config->distance = (dist[2] - dist[0]);
	else
		config->distance = (dist[3] - dist[1]);
	config->height = WDW_HEIGHT / config->distance;
	config->start = WDW_HEIGHT / 2 - config->height / 2;
	config->end = WDW_HEIGHT / 2 + config->height / 2;
}

// For y on the screen, it calculates the corresponding point on the texture
// and returns its color. This color is used to draw the pixel.
// get_i is used to know which which side of the wall was hit by the ray
// floor() returns the integer value or lower integer value of the number
unsigned int	get_pixel_texture(t_config *config, int y, double *ray)
{
	char	*color;
	float	coord_x;
	float	coord_y;
	int		i;

	(void)y;
	i = get_i(config, ray);
	if (config->side == 0)
		coord_x = config->pos_y + config->distance * ray[1];
	else
		coord_x = config->pos_x + config->distance * ray[0];
	coord_x = coord_x - floor(coord_x);
	coord_x = coord_x * config->wall[i].width;
	coord_y = ((y - config->start) * config->wall[i].height) \
	/ ((config->end - config->start));
	color = (config->wall[i].addr + ((int)coord_y \
				* config->wall[i].line_len
				+ (int)coord_x * (config->wall[i].bpp / 8)));
	if (!color)
		return (write(2, "xpm invalido bro cmon\n", 22), exit(1), 1);
	return (*(unsigned int *)color);
}

// Loops over each pixel and checks if it will be a ceiling, wall or floor.
//  Sets the color accordignly.
void	draw_img(int x, t_config *config, double *dist, double *ray)
{
	int				y;
	unsigned int	color;

	y = 0;
	get_image_vars(config, config->side, dist);
	while (y < WDW_HEIGHT)
	{
		if (y >= 0 && y <= config->start)
			ft_mlx_pixel_put(config, x, y, config->colors[1]);
		else if (y > config->start && y < config->end)
		{
			color = get_pixel_texture(config, y, ray);
			ft_mlx_pixel_put(config, x, y, color);
		}
		else if (y >= config->end)
			ft_mlx_pixel_put(config, x, y, config->colors[0]);
		y++;
	}
}
