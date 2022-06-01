/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:12:06 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/07 11:22:07 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(char *str, int n, int len_n)
{
	int	i;

	i = 0;
	str[len_n] = '\0';
	if (n == -2147483648)
	{
		str[--len_n] = '8';
		n = n / 10;
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i++;
	}
	while (len_n - 1 >= i)
	{
		str[len_n - 1] = n % 10 + '0';
		n = n / 10;
		len_n--;
	}
}

static int	ft_len_n(int n)
{
	int	i;

	i = 1;
	if (n > 0)
	{
		while (n >= 10)
		{
			n = n / 10;
			i++;
		}
	}
	else if (n < 0)
	{
		while (n <= -10)
		{
			n = n / 10;
			i++;
		}
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len_n;
	char	*str;

	len_n = ft_len_n(n);
	str = (char *)malloc(sizeof(char) * (len_n + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
		ft_putnbr(str, n, len_n);
	return (str);
}
