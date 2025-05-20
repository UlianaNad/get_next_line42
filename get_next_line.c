/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unadoroz <unadoroz@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:12:14 by unadoroz          #+#    #+#             */
/*   Updated: 2025/05/20 10:56:02 by unadoroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	read_to_buffer(int fd, char **buffer)
{
	char	temp[BUFFER_SIZE + 1];
	ssize_t	bytes_to_read;
	char	*temp_buffer;
	
	while (!ft_strchr(*buffer, '\n'))
	{
		bytes_to_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_to_read < 0)
			return (-1);
		if (bytes_to_read == 0)
			break;
		temp[bytes_to_read] = '\0';
		temp_buffer = ft_strjoin(*buffer, temp);
		free(*buffer);
		*buffer = temp_buffer;
	}
	return(0);
}

static char	*get_line(char **buffer)
{
	char	*line;
	char	*rest;
	char	*newline;
	size_t	length;

	if (!*buffer || !**buffer)
		return (NULL);
	newline = ft_strchr(*buffer, '\n');
	if (newline)
		length = newline - *buffer + 1;
	else
		length = ft_strlen(*buffer);
	line = ft_substr(*buffer, 0, length);
	rest = ft_strdup(*buffer + length);
	free (*buffer);
	*buffer = rest;
	return (line);
}

char *get_next_line(int fd)
{	
	static char *buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	if (read_to_buffer (fd, &buffer) == -1)
		return (free(buffer), buffer = NULL, NULL);
	return (get_line(&buffer));
}

/*
int main(void)
{
	static int count = 1;
	char *s;
	int fd = open("test.txt", O_RDONLY);

	if (fd == -1)
	{
		printf("Error opening file\n");
		return(1);
	}
	while(1)
	{
		printf("ft_calloc#[%d]---", count++);
		s = get_next_line(fd);
		if (s == NULL)
			break;
		count++;
		printf("[%d]:%s\n",count,s);
		free(s);
		s = NULL;
	}
	close(fd);
	return (0);
}
*/
