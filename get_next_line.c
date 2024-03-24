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

void	ft_bzero(char *s, int n)
{
	int i;

	i = 0;
	while (n > i)
	{
		s[i] = '\0';
		i++;
	}
	
}

void	copy_to_static_buf(char *leftover, char *leftover_for_next_call)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (leftover == NULL)
		return ;
	while (leftover[j] != '\0')
	{
		leftover_for_next_call[i] = leftover[j];
		i++;
		j++;
	}
	free(leftover);
}

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
		ft_strlcat(leftover, buf, char_read);
	}
	free(buf);
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	char 		*check;
	char		*check2;
	static char leftover_for_next_call[10000];
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	check = read_to_leftover(leftover_for_next_call, fd);
	if (check == NULL)
		return (NULL);
	next_line = copy_to_next_line(leftover_for_next_call);
	if (next_line == NULL)
		return (NULL);
	check2 = new_leftover(leftover_for_next_call);
	ft_bzero(leftover_for_next_call, 10000);
	copy_to_static_buf(check2, leftover_for_next_call);
	return (next_line);
}
