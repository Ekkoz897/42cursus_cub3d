/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:18:27 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/14 23:09:31 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// data.img.bpp: bits per pixel
// data.img.line_len: size (in bytes) of a single line of the image.
// data.img.endian:  the order of bytes, there are 2 types of system, big endian
// and little endian. They store the color bytes differently

int	main(int ac, char **av)
{
	t_config	config;

	(void)ac;
	(void)av;
	vars_init(&config);
	parser("scene_files/test.cub");
	// config.mlx = mlx_init();
	// config.wdw = mlx_new_window(config.mlx, WDW_WIDTH, WDW_HEIGHT, "Cub3D");
	// config.img.mlx_img = mlx_new_image(config.mlx, WDW_WIDTH, WDW_HEIGHT);
	// config.img.addr = mlx_get_data_addr(config.img.mlx_img, &config.img.bpp,
	// &config.img.line_len, &config.img.endian);
	// while (1)
	// 	write(1, " ", 0);
	return (0);
	}
