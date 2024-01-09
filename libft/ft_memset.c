/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:23:51 by ratavare          #+#    #+#             */
/*   Updated: 2022/10/27 18:00:23 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i)
	{
		((unsigned char *)str)[i] = ch;
		i++;
	}
	return (str);
}
