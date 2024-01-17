/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:18:27 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/17 14:18:42 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Temp function while I don't have parsing for maps, etc
void	parser_sqn(t_config *config)
{
	char	*temp_map[10] =
	{
		"1111111111", // Outer wall
		"1000000001", // Row with opening
		"1011001101", // Row with some walls
		"1011001101", // Row with some walls
		"1000000001", // Open row
		"1011111101", // Row with a narrow path
		"1010000101", // Row with some walls
		"1011100101", // Row with some walls
		"1000000001", // Open row
		"1111111111" // Outer wall
	};

	config->map = malloc(10 * sizeof(char *));
	for (int i = 0; i < 10; i++)
	{
		config->map[i] = ft_strdup(temp_map[i]);
	}
}

// Clears the image and redraws it based on players position, etc
int	ft_render(t_config *config)
{
	mlx_clear_window(config->mlx, config->wdw);
	ft_calculations(config);
	mlx_put_image_to_window(config->mlx, config->wdw, config->img.mlx_img, \
		0, 0);
	return (1);
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
			config->textures[i], &config->wall->width, &config->wall->height);
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

	(void)ac;
	(void)av;
	// apagar quando tivermos o tamanho real do mapa
	config.map_height = 10;
	config.map_width = 10;
	//
	vars_init(&config);
	parser_sqn(&config);
	config.mlx = mlx_init();
	config.wdw = mlx_new_window(config.mlx, WDW_WIDTH, WDW_HEIGHT, "Cub3D");
	config.img.mlx_img = mlx_new_image(config.mlx, WDW_WIDTH, WDW_HEIGHT);
	config.img.addr = mlx_get_data_addr(config.img.mlx_img, &config.img.bpp,
			&config.img.line_len, &config.img.endian);
	init_texture_imgs(&config);
	mlx_loop_hook(config.mlx, ft_render, &config);
	mlx_hook(config.wdw, 02, (1L << 0), keyboard_handle, &config);
	mlx_hook(config.wdw, 17, 1L << 17, ft_free_exit_cub, &config);
	mlx_loop(config.mlx);
}
