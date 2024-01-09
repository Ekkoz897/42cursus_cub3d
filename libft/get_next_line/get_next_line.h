/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:32:00 by ratavare          #+#    #+#             */
/*   Updated: 2023/04/06 18:53:20 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

char	*get_next_line(int fd);
char	*gnl_ft_strjoin(char *line, char *buffer);
int		gnl_ft_strlen(const char *str);
char	*gnl_ft_freebuffer(char *buffer);

#endif