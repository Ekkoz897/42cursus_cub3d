/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:40:01 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/10 12:06:48 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			while (*str && *str != c)
				str++;
			i++;
		}
		while (*str == c && *str)
			str++;
	}
	return (i);
}

static char	*worddup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end && *str)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

int	fdp(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	free (split);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	int		index;

	if (fdp(s, c) == 0)
		return (0);
	split = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen((char *)s) && *s)
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen((char *)s)) && index >= 0)
		{
			split[j++] = worddup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
