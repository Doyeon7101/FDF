/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:04:29 by dpark             #+#    #+#             */
/*   Updated: 2022/11/20 16:17:45 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (1)
	{
		if (s[i] == (char)c)
			return (i);
		if (s[i] == '\0')
			return (-1);
		i++;
	}
}

int	ft_strjoin(char **dest, char *s2)
{
	int			i;
	int			j;
	char		*s1;
	char		*c;

	if (!(*dest))
		s1 = "";
	else
		s1 = *dest;
	c = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!c)
		return (0);
	i = -1;
	j = -1;
	while (s1[++i])
		c[i] = s1[i];
	while (s2[++j])
		c[i + j] = s2[j];
	c[i + j] = '\0';
	if (*dest)
		free(*dest);
	*dest = c;
	return (1);
}
