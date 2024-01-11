/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:13:29 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/11 15:59:47 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/GNL/get_next_line.h"

typedef struct s_config
{
	char	*so;
	char	*no;
	char	*we;
	char	*ea;

	int		f[3];
	int		c[3];

	char	**map;
}	t_config;

// parser.c
int	parser(char *src);

// extract.c
char	**extract(char *src);

#endif