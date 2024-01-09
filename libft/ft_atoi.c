/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:39:46 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/10 17:52:45 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	res;
	size_t	sinal;
	int		i;

	res = 0;
	sinal = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			sinal *= -1;
		}
		i++;
	}
	while ((nptr[i] && nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = 10 * res + nptr[i] - '0';
		i++;
	}
	return ((int)(res * sinal));
}
