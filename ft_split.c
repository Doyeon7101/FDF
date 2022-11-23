/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:45:02 by dpark             #+#    #+#             */
/*   Updated: 2022/11/23 20:00:44 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	func_chunk_cnt(char const *s, char c)
{
	size_t	chunk_cnt;

	chunk_cnt = 0;
	if (c == '\0')
		return (ft_strlen(s) != 0);
	while (1)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (chunk_cnt);
		chunk_cnt++;
		while (*s != c)
		{
			if (*s == '\0')
				return (chunk_cnt);
			s++;
		}
		s++;
	}
}

static size_t	word_cnt(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*make_chunk(char const **s_ptr, char c)
{
	char		*chunk;
	size_t		i;
	const char	*s;
	size_t		chunk_size;

	i = 0;
	s = *s_ptr;
	while (*s == c)
		s++;
	chunk_size = word_cnt(s, c);
	chunk = (char *)malloc(sizeof(char) * (chunk_size + 1));
	while (*s == c)
		s++;
	while (i < chunk_size)
		chunk[i++] = *s++;
	chunk[i] = '\0';
	*s_ptr = s;
	return (chunk);
}

static void	free_chunks(size_t curr, char **pile)
{
	while (curr > 0)
	{
		free(pile[curr]);
		curr--;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	chunk_cnt;
	size_t	row;
	char	**pile;
	char	*chunk;

	row = 0;
	chunk_cnt = func_chunk_cnt(s, c);
	pile = (char **)malloc(sizeof(char *) * (chunk_cnt + 1));
	if (!pile)
		return (0);
	while (row < chunk_cnt)
	{
		chunk = make_chunk(&s, c);
		if (chunk == NULL)
		{
			free_chunks(row, pile);
			return (0);
		}
		pile[row] = chunk;
		row++;
	}
	pile[row] = 0;
	return (pile);
}
