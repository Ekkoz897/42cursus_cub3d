/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:01:42 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/21 17:55:25 by apereira         ###   ########.fr       */
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
