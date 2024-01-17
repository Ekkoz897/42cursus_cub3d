/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:01:42 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/17 14:18:10 by apereira         ###   ########.fr       */
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
	if (config->so)
		free(config->so);
	if (config->no)
		free(config->no);
	if (config->we)
		free(config->we);
	if (config->ea)
		free(config->ea);
}
