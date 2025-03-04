/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:18:59 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/04 10:34:20 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char			*get_next_line(int fd);
char			*ft_strchr_gnl(const char *s, char c);
char			*ft_strjoin_gnl(char *s1, char *s2);
void			*ft_calloc_gnl(size_t count, size_t size);
size_t			ft_strlen_gnl(const char *s);
char			*fd_line(char *stash);
char			*updated_t(char *stash);
char			*fd_read(int fd, char *stash);
char			*ft_strdup_gnl(const char *s1);

#endif