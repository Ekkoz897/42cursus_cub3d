/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:56:02 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/08 17:45:44 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen((char *)s1 + i);
	if (len)
		while (ft_strchr(set, s1[len + i - 1]))
			len--;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + i, len + 1);
	str[len] = '\0';
	return (str);
}
