/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:01:29 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/10 13:10:57 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	j = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s) && len <= ft_strlen(s) - start)
		str = malloc((len * sizeof(char) + 1));
	else if (len > ft_strlen(s) - start && start < ft_strlen(s))
		str = malloc((ft_strlen((char *)s) - start) * sizeof(char) + 1);
	else
		str = malloc(1 * sizeof(char));
	if (!str)
		return (NULL);
	while (j < len && start < ft_strlen(s))
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}
