/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:05:22 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/21 11:45:45 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

static char	*ft_str_stat(char *str_stat)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	while (str_stat[i] && str_stat[i] != '\n' )
		i++;
	if (!str_stat[i])
	{
		free(str_stat);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(str_stat) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (str_stat[i])
		s[j++] = str_stat[i++];
	s[j] = '\0';
	free(str_stat);
	return (s);
}

static char	*ft_get_line(char *str_stat)
{
	size_t	i;
	char	*s;

	if (!str_stat[0])
		return (NULL);
	i = 0;
	while (str_stat[i] && str_stat[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str_stat[i] && str_stat[i] != '\n')
	{
		s[i] = str_stat[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		new_s[i] = s1[i];
	while (s2[j] != '\0')
		new_s[i++] = s2[j++];
	new_s[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (new_s);
}

static char	*ft_read_str(int fd, char *str_stat, int *br)
{
	char	*mass;
	int		byte_read;

	mass = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!mass)
		return (NULL);
	byte_read = read(fd, mass, 0);
	if (byte_read == -1)
	{
		free(mass);
		return (NULL);
	}
	byte_read = 1;
	while (!ft_strrchr(str_stat, '\n') && byte_read != 0)
	{
		byte_read = read(fd, mass, BUFFER_SIZE);
		mass[byte_read] = '\0';
		str_stat = ft_strjoin_gnl(str_stat, mass);
	}
	free(mass);
	*br = byte_read;
	return (str_stat);
}

int	get_next_line(int fd, char **line)
{
	static char	*str_stat;
	int			br;

	br = -1;
	*line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (br);
	str_stat = ft_read_str(fd, str_stat, &br);
	if (!str_stat)
		return (br);
	*line = ft_get_line(str_stat);
	str_stat = ft_str_stat(str_stat);
	return (br);
}
