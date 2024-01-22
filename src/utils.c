/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:22:15 by apereira          #+#    #+#             */
/*   Updated: 2024/01/22 12:20:36 by apereira         ###   ########.fr       */
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
	config->mlx = 0;
	config->wdw = 0;
	config->distance = 0;
	config->height = 0;
	config->start = 0;
	config->end = 0;
	config->hit = 0;
	config->step_x = 0;
	config->step_y = 0;
	config->side = -1;
	config->letter = 0;
	config->map = 0;
	config->map_coord = malloc(sizeof(int) * 2);
	config->textures = malloc(sizeof(char *) * 4);
	config->colors = malloc(sizeof(int) * 2);
	vars_init_helper(config);
}

int	ft_free_exit_cub(t_config *config)
{
	int	i;

	if (!config)
		exit(0);
	if (config->img.mlx_img)
		mlx_destroy_image(config->mlx, config->img.mlx_img);
	if (config->wdw && config->mlx)
		mlx_destroy_window(config->mlx, config->wdw);
	if (config->mlx)
		mlx_destroy_display(config->mlx);
	i = 0;
	while (i != config->map_height)
		free (config->map[i++]);
	free(config->map);
	free(config->mlx);
	free(config->colors);
	free(config->map_coord);
	free(config->textures);
	exit(0);
}

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}
