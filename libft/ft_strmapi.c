/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:23:37 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/06 14:23:41 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len_s;
	char	*str;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
