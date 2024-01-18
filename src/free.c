/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:01:42 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/18 20:46:20 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Frees a given (char *) array.

void	free_ptp(char **ptp)
{
	int	i;

	i = 0;
	while (ptp[i])
		free(ptp[i++]);
	free(ptp);
}

// Frees the texture path strings.

void	free_textures(t_config *config)
{
	if (config->textures[0])
		free(config->textures[0]);
	if (config->textures[1])
		free(config->textures[1]);
	if (config->textures[2])
		free(config->textures[2]);
	if (config->textures[3])
		free(config->textures[3]);
}
