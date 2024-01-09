/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:37:07 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/08 17:53:24 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(long n)
{
	int	i;
	int	sinal;

	i = 0;
	sinal = -1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= sinal;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	i = ft_nlen(n);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i--] = 48 + (nb % 10);
		nb /= 10;
	}
	return (str);
}
