/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:54:27 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/08 16:44:13 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	i = 0;
	while (src[i] && (d_len + i) < (dstsize - 1))
	{
		dest[d_len + i] = src[i];
		i++;
	}
	if (d_len <= dstsize)
		dest[d_len + i] = '\0';
	if (d_len > dstsize)
		d_len = dstsize;
	return (d_len + s_len);
}
