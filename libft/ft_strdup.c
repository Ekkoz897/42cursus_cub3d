/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:26:00 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/02 16:49:15 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*m;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	m = malloc((ft_strlen((char *)s) * sizeof(char) + 1));
	if (!m)
		return (NULL);
	while (s[i])
	{
		m[i] = s[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}
