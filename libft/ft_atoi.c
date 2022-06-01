/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:01:55 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/07 11:21:54 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		p;
	long	chislo;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	p = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p = -1;
		i++;
	}
	chislo = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (chislo * 10 + (str[i] - '0') < chislo && p == -1)
			return (0);
		else if (chislo * 10 + (str[i] - '0') < chislo && p == 1)
			return (-1);
		chislo = chislo * 10 + (str[i] - '0');
		i++;
	}
	return (p * chislo);
}
