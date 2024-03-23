/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinric <mheinric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:23:48 by mheinric          #+#    #+#             */
/*   Updated: 2024/03/12 14:23:48 by mheinric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*find_nl(const char *s, int c)
{
	char	*stuff;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			stuff = (char *)s;
			return (stuff);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *leftover, char *buf)
{
	char	*ptr;
	int		i;
	int		j;

	if (!leftover)
	{
		leftover = (char *)malloc(1);
		leftover[0] = '\0';
	}
	if (!leftover || !buf)
		return (NULL);
	ptr = malloc((ft_strlen(leftover) + ft_strlen(buf)) + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	j = 0;
	if (leftover)
		while (leftover[++i] != '\0')
			ptr[i] = leftover[i];
	while (buf[j] != '\0')
		ptr[i++] = buf[j++];
	ptr[ft_strlen(leftover) + ft_strlen(buf)] = '\0';
	free(leftover);
	return (ptr);
}

char	*copy_to_next_line(char *leftover)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!leftover[i])
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	ptr = (char *)malloc(i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
	{
		ptr[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
	{
		ptr[i] = leftover[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*new_leftover(char *leftover)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
	{
		free(leftover);
		return (NULL);
	}
	ptr = (char *)malloc(ft_strlen(leftover) - i + 1);
	if (!ptr)
		return (NULL);
	i++;
	j = 0;
	while (leftover[i])
		ptr[j++] = leftover[i++];
	ptr[j] = '\0';
	free(leftover);
	return (ptr);
}
