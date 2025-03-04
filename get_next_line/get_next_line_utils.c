/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:18:44 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/04 10:36:50 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(const char *s1)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen_gnl(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr_gnl(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (count == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (!s1 || !s2)
		return (free(s1), s1 = NULL, NULL);
	str = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!str)
		return (free(s1), s1 = NULL, NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
