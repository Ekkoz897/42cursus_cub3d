/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:57:11 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/09 17:26:26 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(dst) >= size)
		return (size + ft_strlen((char *)src));
	i = 0;
	j = (ft_strlen(dst));
	while (src[i] != '\0' && j + 1 < size)
	{
		dst[j] = ((char *)src)[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (ft_strlen(dst)+ ft_strlen((char *)src + i));
}
