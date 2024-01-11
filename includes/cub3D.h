/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:13:29 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/11 17:01:25 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/GNL/get_next_line.h"
# include "../includes/mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "math.h"

# define WDW_WIDTH 800
# define WDW_HEIGHT 600
# define ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_config
{
<<<<<<< HEAD:includes/scene.h
=======
	void	*mlx;
	void	*wdw;
	double	p_x;
	double	p_y;
	double	plane_x;
	double	plane_y;
	double	distance;
	double	height;
	char	**scfile_text;

>>>>>>> refs/remotes/origin/main:includes/cub3D.h
	char	*so;
	char	*no;
	char	*we;
	char	*ea;

	int		f[3];
	int		c[3];

	char	**map;
	t_img	img;
}	t_config;

// parser.c
int		parser(char *src);

// extract.c
<<<<<<< HEAD:includes/scene.h
char	**extract(char *src);
=======
int		extract(char *src, t_config *config);

// utils.c
void	vars_init(t_config *config);
>>>>>>> refs/remotes/origin/main:includes/cub3D.h

#endif