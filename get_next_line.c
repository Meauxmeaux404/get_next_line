/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinric <mheinric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:23:55 by mheinric          #+#    #+#             */
/*   Updated: 2024/03/12 14:23:55 by mheinric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_leftover(char *leftover, int fd)
{
	int		char_read;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	char_read = 1;
	while (!find_nl(leftover, '\n') && char_read != 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[char_read] = '\0';
		leftover = ft_strjoin(leftover, buf);
	}
	free(buf);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftover = read_to_leftover(leftover, fd);
	if (leftover == NULL)
		return (NULL);
	next_line = copy_to_next_line(leftover);
	leftover = new_leftover(leftover);
	return (next_line);
}
