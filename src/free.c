/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:01:42 by ratavare          #+#    #+#             */
/*   Updated: 2024/02/14 15:47:19 by ratavare         ###   ########.fr       */
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

void	free_textures(t_config *config)
{
	int	i;

	i = 0;
	while (i < 4)
		free(config->textures[i++]);
	free(config->textures);
}
