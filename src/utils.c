/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:22:15 by apereira          #+#    #+#             */
/*   Updated: 2024/01/14 08:58:09 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Initializes vars
void	vars_init(t_config *config)
{
	config->mlx = 0;
	config->wdw = 0;
	config->pos_x = 0;
	config->pos_y = 0;
	config->plane_x = 0;
	config->plane_y = 0;
	config->distance = 0;
	config->height = 0;
	config->textures = malloc (sizeof(char *) * 4);
	config->textures[0] = ft_strdup("../includes/textures/wall_1.xpm");
	config->textures[1] = ft_strdup("../includes/textures/wall_2.xpm");
	config->textures[2] = ft_strdup("../includes/textures/wall_3.xpm");
	config->textures[3] = ft_strdup("../includes/textures/wall_4.xpm");
}

int	ft_exit_cub(t_config *config)
{
	int	i;

	if (!config)
		exit (0);
	if (config->img.mlx_img)
		mlx_destroy_image(config->mlx, config->img.mlx_img);
	if (config->wdw && config->mlx)
		mlx_destroy_window(config->mlx, config->wdw);
	if (config->mlx)
		mlx_destroy_display(config->mlx);
	i = 0;
	while (i != config->map_height)
	{
		free (config->map[i]);
		i++;
	}
	free(config->map);
	free(config->mlx);
	free(config->textures);
	exit(0);
}
