/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:18:50 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 13:18:45 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fd_read(int fd, char *stash)
{
	ssize_t	a;
	char	*tmp;

	if (!stash)
		stash = ft_strdup_gnl("");
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free(stash), stash = NULL, NULL);
	a = 1;
	while (a > 0)
	{
		a = read(fd, tmp, BUFFER_SIZE);
		if (a == -1)
			return (free(tmp), tmp = NULL, free(stash), stash = NULL, NULL);
		tmp[a] = '\0';
		stash = ft_strjoin_gnl(stash, tmp);
		if (!stash)
			return (free(tmp), tmp = NULL, NULL);
		if (ft_strchr_gnl(tmp, '\n'))
			break ;
	}
	free(tmp);
	tmp = NULL;
	return (stash);
}

char	*updated_t(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), stash = NULL, NULL);
	i++;
	new_stash = ft_calloc_gnl(ft_strlen_gnl(stash) - i + 1, 1);
	if (!new_stash)
		return (free(stash), stash = NULL, NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	return (free(stash), stash = NULL, new_stash);
}

char	*fd_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_calloc_gnl(i + 1, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i])
		line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	stash = fd_read(fd, stash);
	if (!stash)
		return (free(stash), stash = NULL, NULL);
	line = fd_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	return (stash = updated_t(stash), line);
}
