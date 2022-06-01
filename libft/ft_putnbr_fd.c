/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:59:38 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/06 15:59:42 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	vyvod(int s, char *base, int fd)
{
	if (s >= 10)
		vyvod(s / 10, base, fd);
	ft_putchar_fd(base[s % 10], fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*base;

	base = "0123456789";
	if (n >= 0)
		vyvod(n, base, fd);
	else if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		vyvod(n / 10 * -1, base, fd);
		ft_putchar_fd(base[n % 10 * -1], fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		vyvod(n * -1, base, fd);
	}
}
