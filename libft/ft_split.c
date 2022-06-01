/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:31:19 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/11 10:22:39 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_n_str(char *s, char c)
{
	size_t	i;
	int		k;
	size_t	n;

	i = 0;
	n = 1;
	if (!s[i])
		n = 0;
	k = 1;
	while (s[i])
	{
		if (s[i] == c && k)
		{
			n++;
			k = 0;
		}
		else if (s[i] != c)
			k = 1;
		i++;
	}
	return (n);
}

static size_t	ft_strlen_str(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	ft_clear_mas_str(char **mas_str)
{
	size_t	i;

	i = 0;
	while (mas_str[i])
	{
		free(mas_str[i]);
		i++;
	}
	free(mas_str);
}

static void	ft_get_str(char **mas_str, char *s, char c, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	while (k < n)
	{
		i = ft_strlen_str(s, c);
		mas_str[k] = (char *)malloc(sizeof(char) * (i + 1));
		if (!mas_str[k])
			return (ft_clear_mas_str(mas_str));
		j = 0;
		while (j < i)
		{
			mas_str[k][j] = *(s++);
			j++;
		}
		mas_str[k][j] = '\0';
		j = 0;
		while (s[j] == c && s[j])
			s++;
		k++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**mas_str;
	size_t	n;
	size_t	end;
	char	*new_s;

	n = 0;
	if (!s)
		return (NULL);
	while (s[n] && s[n] == c)
		n++;
	end = ft_strlen(s);
	while (end > n && s[end - 1] == c)
		end--;
	new_s = ft_substr(s, n, end - n);
	if (!new_s)
		return (NULL);
	n = ft_n_str(new_s, c);
	mas_str = (char **)malloc(sizeof(char *) * (n + 1));
	if (!mas_str)
		return (NULL);
	ft_get_str(mas_str, new_s, c, n);
	mas_str[n] = NULL;
	free(new_s);
	return (mas_str);
}
