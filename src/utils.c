/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:22:15 by apereira          #+#    #+#             */
/*   Updated: 2024/01/18 22:22:29 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	vars_init_helper(t_config *config)
{
	int	i;

	i = 0;
	while (i != 4)
		config->textures[i++] = 0;
	i = 0;
	while (i != 2)
	{
		config->map_coord[i] = 0;
		config->colors[i] = -1;
		i++;
	}
}

// Initializes vars
void	vars_init(t_config *config)
{
	config->textures = malloc(sizeof(char *) * 4);
	// config->textures[0] = NULL;
	// config->textures[1] = NULL;
	// config->textures[2] = NULL;
	// config->textures[3] = NULL;
	config->mlx = 0;
	config->wdw = 0;
	config->pos_x = 0;
	config->pos_y = 0;
	config->dir_x = 0;
	config->dir_y = 0;
	config->plane_x = 0;
	config->plane_y = 0;
	config->distance = 0;
	config->height = 0;
	config->map = 0;
	config->hit = 0;
	config->colors = malloc(sizeof(int) * 2);
	config->step_x = 0;
	config->step_y = 0;
	config->map_coord = malloc(sizeof(int) * 2);
	config->side = -1;
	config->start = 0;
	config->end = 0;
	vars_init_helper(config);
}

int	ft_free_exit_cub(t_config *config)
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
		free (config->map[i++]);
	i = 0;
	while (i <= 3)
		free (config->textures[i++]);
	free(config->map);
	free(config->mlx);
	free(config->textures);
	free(config->colors);
	free(config->map_coord);
	exit(0);
}
