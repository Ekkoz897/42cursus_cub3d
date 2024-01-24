/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:18:27 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/24 14:48:15 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Clears the image and redraws it based on players position, etc
int	ft_render(t_config *config)
{
	mlx_clear_window(config->mlx, config->wdw);
	ft_calculations(config);
	mlx_put_image_to_window(config->mlx, config->wdw, config->img.mlx_img, \
		0, 0);
	return (1);
}

void	direction_aux(t_config *config, int sig)
{
	config->dir_x = 0;
	config->dir_y = sig;
	config->plane_x = 0.66 * sig;
	config->plane_y = 0;
}

// Sets the initial direction of the player is looking towards
void	get_direction(t_config *config)
{
	if (config->letter == 'E')
		direction_aux(config, 1);
	else if (config->letter == 'W')
		direction_aux(config, -1);
	else if (config->letter == 'S')
	{
		config->dir_x = 1;
		config->dir_y = 0;
		config->plane_x = 0;
		config->plane_y = -0.66;
	}
	else if (config->letter == 'N')
	{
		config->dir_x = -1;
		config->dir_y = 0;
		config->plane_x = 0;
		config->plane_y = 0.66;
	}
}

// gets the xpm file path to all textures and creates a drawable img
// also collects the data addr to properly generate the textures
void	init_texture_imgs(t_config *config)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		config->wall[i].img = mlx_xpm_file_to_image(config->mlx, \
			config->textures[i], &config->wall[i].width, \
				&config->wall[i].height);
		if (!config->wall[i].img)
			return ;
		config->wall[i].addr = mlx_get_data_addr(config->wall[i].img, \
			&config->wall[i].bpp, &config->wall[i].line_len, \
			&config->wall[i].endian);
		free(config->textures[i]);
		i++;
	}
}

// config.img.bpp: bits per pixel
// config.img.line_len: size (in bytes) of a single line of the image.
// config.img.endian: the order of bytes, there's 2 types of system, big endian
// and little endian. They store the color bytes differently
int	main(int ac, char **av)
{
	t_config	config;

	if (ac != 2)
		return (parsing_error(&config, "Invalid argument number\n", 0));
	vars_init(&config);
	if (parser(av[1], &config))
		return (1);
	get_direction(&config);
	config.mlx = mlx_init();
	config.wdw = mlx_new_window(config.mlx, WDW_WIDTH, WDW_HEIGHT, "Cub3D");
	config.img.mlx_img = mlx_new_image(config.mlx, WDW_WIDTH, WDW_HEIGHT);
	config.img.addr = mlx_get_data_addr(config.img.mlx_img, &config.img.bpp,
			&config.img.line_len, &config.img.endian);
	init_texture_imgs(&config);
	mlx_loop_hook(config.mlx, ft_render, &config);
	// mlx_mouse_move(config->mlx, config->wdw, WDW_WIDTH / 2, WDW_HEIGHT / 2);
	mlx_hook(config.wdw, 02, (1L << 0), keyboard_handle, &config);
	mlx_hook(config.wdw, 06, (1L << 6), mouse_handle, &config);
	mlx_hook(config.wdw, 17, 1L << 17, ft_free_exit_cub, &config);
	mlx_loop(config.mlx);
}
