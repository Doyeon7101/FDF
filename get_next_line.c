/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:40:36 by dpark             #+#    #+#             */
/*   Updated: 2022/11/20 16:17:35 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update_temp(char **origin)
{
	char	*update;
	char	*temp;
	int		lf;
	int		status;

	temp = *origin;
	lf = ft_strchr(temp, '\n');
	if (lf == -1 || temp[lf + 1] == '\0')
	{
		free(temp);
		*origin = NULL;
		return (1);
	}
	update = NULL;
	status = ft_strjoin(&update, &(temp[lf + 1]));
	free(temp);
	*origin = update;
	return (status);
}

int	get_line(char **line, char *temp)
{
	int		lf;
	char	lf_char;
	int		status;

	*line = 0;
	lf = ft_strchr((const char *)temp, '\n');
	if (lf == -1)
		return (ft_strjoin(line, temp));
	lf_char = temp[lf + 1];
	temp[lf + 1] = '\0';
	status = ft_strjoin(line, temp);
	temp[lf + 1] = lf_char;
	return (status);
}

int	make_temp(char **temp, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;

	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes == -1)
			return (0);
		buffer[read_bytes] = '\0';
		if (!ft_strjoin(temp, buffer))
			return (0);
		if (ft_strchr(buffer, '\n') != -1)
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr((const char *)temp, '\n') == -1)
		if (!make_temp(&temp, fd))
			return (0);
	if (!temp)
		return (0);
	if (!get_line(&line, temp))
	{
		free(temp);
		return (0);
	}
	if (!update_temp(&temp))
	{
		free(temp);
		return (0);
	}
	return (line);
}
