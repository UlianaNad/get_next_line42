/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unadoroz <unadoroz@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:15:42 by unadoroz          #+#    #+#             */
/*   Updated: 2025/05/19 11:58:05 by unadoroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = 0;
	while (s[i])
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	find_end_line(const char *s, int c)
{
	unsigned char	ch;
	int				i;

	i = 0;
	ch = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == ch)
			return (1);
		i++;
	}
	if (ch == '\0')
		return (2);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	int				i;

	i = 0;
	ch = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t len)
{
	size_t	i;
	char	*temp;

	temp = (char *)s;
	i = 0;
	while (i < len)
	{
		temp[i] = 0;
		i++;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	total;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	total = ft_strlen(s + start);
	if (total > len)
		total = len;
	sub_str = malloc((total + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, total + 1);
	return (sub_str);
}
