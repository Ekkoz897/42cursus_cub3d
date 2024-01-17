/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:56:21 by apereira          #+#    #+#             */
/*   Updated: 2024/01/17 11:36:09 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Calculates the pixel's address in the buffer and sets its color to our choice
// this changes the buffer of the image to be printed later, once we set all
// the pixels, we will the print the image.
void	ft_mlx_pixel_put(t_config *config, int x, int y, int color)
{
	char	*index;

	index = config->img.addr + (y * config->img.line_len + x * \
		(config->img.bpp / 8));
	*(unsigned int *)index = color;
}

// Determines which texture to use based on the ray vector coordinates
int	get_i(t_config *config, double *ray)
{
	int	i;

	if (config->side == 1)
	{
		if (ray[1] < 0)
			i = 2;
		else
			i = 3;
	}
	else
	{
		if (ray[0] < 0)
			i = 0;
		else
			i = 1;
	}
	return (i);
}
