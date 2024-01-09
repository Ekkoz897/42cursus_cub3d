/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:47:03 by ratavare          #+#    #+#             */
/*   Updated: 2023/03/10 11:27:29 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(const char *format)
{
	int	i;

	i = 0;
	if (format == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (format[i])
		ft_print_char(format[i++]);
	return (i);
}

int	ft_print_nbr(int n)
{
	int		ret;
	char	*str;

	str = ft_itoa(n);
	ret = ft_print_string(str);
	free (str);
	return (ret);
}

int	ft_print_unbr(unsigned int n)
{
	static int	ret;

	ret = 0;
	if (n >= 10)
	{
		ft_print_unbr(n / 10);
		n %= 10;
	}
	if (n < 10)
		ret += ft_print_char(n + 48);
	return (ret);
}

int	ft_print_hex(unsigned long n, const char format)
{
	if (n == 0)
		return (ft_print_char('0'));
	if (n > 15)
	{
		ft_print_hex(n / 16, format);
		ft_print_hex(n % 16, format);
	}
	if (n <= 9)
		ft_print_char(n + 48);
	else if (n < 16 && n > 9)
	{
		if (format == 'x')
			ft_print_char(n + 87);
		if (format == 'X')
			ft_print_char(n + 55);
	}
	return (hexcount(n));
}

int	ft_puthex(unsigned long n)
{
	if (n > 15)
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	if (n <= 9)
		ft_print_char(n + 48);
	if (n < 16 && n > 9)
		ft_print_char(n + 87);
	return (hexcount(n) + 2);
}
