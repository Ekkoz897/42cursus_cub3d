/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:22:15 by apereira          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/17 12:37:59 by apereira         ###   ########.fr       */
=======
/*   Updated: 2024/01/16 23:16:57 by ratavare         ###   ########.fr       */
>>>>>>> parser
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
	config->so = NULL;
	config->no = NULL;
	config->ea = NULL;
	config->we = NULL;
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
	config->map = NULL;
	config->hit = 0;
	config->colors = malloc(sizeof(int) * 2);
	config->step_x = 0;
	config->step_y = 0;
	config->map_coord = malloc(sizeof(int) * 2);
	config->side = -1;
	config->start = 0;
	config->end = 0;
	config->textures = malloc (sizeof(char *) * 4);
	config->textures[0] = ft_strdup("../includes/textures/wall_1.xpm");
	config->textures[1] = ft_strdup("../includes/textures/wall_2.xpm");
	config->textures[2] = ft_strdup("../includes/textures/wall_3.xpm");
	config->textures[3] = ft_strdup("../includes/textures/wall_4.xpm");
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
	{
		free (config->map[i]);
		i++;
	}
	free(config->map);
	free(config->mlx);
	free(config->textures);
	exit(0);
}
