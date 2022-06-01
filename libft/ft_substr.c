/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 09:35:32 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/08 15:40:22 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new_s;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		len = 0;
	if (len_s < len)
		len = len_s - start;
	new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < len)
	{
		if (i >= start && j < len)
			new_s[j++] = s[i];
		i++;
	}
	new_s[j] = '\0';
	return (new_s);
}
