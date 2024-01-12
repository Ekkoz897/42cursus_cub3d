/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:22:15 by apereira          #+#    #+#             */
/*   Updated: 2024/01/12 09:46:02 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Initializes vars
void	vars_init(t_config *config)
{
	config->mlx = 0;
	config->wdw = 0;
	config->p_x = 0;
	config->p_y = 0;
	config->plane_x = 0;
	config->plane_y = 0;
	config->distance = 0;
	config->height = 0;
	config->textures = malloc (sizeof(char *) * 4);
	config->textures[0] = ft_strdup("../includes/textures/wall_1.xpm");
	config->textures[1] = ft_strdup("../includes/textures/wall_2.xpm");
	config->textures[2] = ft_strdup("../includes/textures/wall_3.xpm");
	config->textures[3] = ft_strdup("../includes/textures/wall_4.xpm");
	// vars_init2(config); for later
}
