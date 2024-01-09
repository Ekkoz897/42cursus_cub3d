/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:36:34 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/09 17:50:56 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = ((char *)s2)[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
