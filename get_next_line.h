/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinric <mheinric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:24:09 by mheinric          #+#    #+#             */
/*   Updated: 2024/03/12 14:24:09 by mheinric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);

char	*find_nl(const char *s, int c);

int	    ft_strlen(const char *str);

void	ft_strlcat(char *dst, const char *src, int n);

char	*copy_to_next_line(char *leftover);

char	*new_leftover(char *leftover);

#endif