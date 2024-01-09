/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:24:19 by ratavare          #+#    #+#             */
/*   Updated: 2023/02/03 11:06:57 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char str[] = "ola";
	
	puts(str);
	bzero(str, 3);
	puts(str);
	return (0);
}*/