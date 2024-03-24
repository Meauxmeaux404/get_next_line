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

int	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (0);
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
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			stuff = (char *)s;
			return (&*stuff);
		}
		i++;
	}
	return (0);
}

void	ft_strlcat(char *dst, const char *src, int n)
{
	int		dstl;
	int		i;

	i = 0;
	if (n == 0)
		return ;
	dstl = ft_strlen(dst);
	while (src[i] != '\0')
	{
		dst[dstl] = src[i];
		dstl++;
		i++;
	}
	dst[dstl] = '\0';
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
		return (NULL);
	ptr = (char *)malloc((ft_strlen(leftover) - i) + 1);
	if (!ptr)
		return (NULL);
	i++;
	j = 0;
	while (leftover[i])
		ptr[j++] = leftover[i++];
	ptr[j] = '\0';
	return (ptr);
}
