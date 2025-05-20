/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unadoroz <unadoroz@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:28:45 by unadoroz          #+#    #+#             */
/*   Updated: 2025/05/20 15:36:30 by unadoroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*saved;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t bytes_to_read;
	char	*temp;
	char	line;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return(NULL);
	bytes_to_read = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(saved, '\n'))
	{
		temp = ft_strjoin(saved, buffer);
		free(buffer);
		free(saved);
		saved = temp;
		free(temp);
	}
	if(ft_strchr(saved, '\n'))
	{
		line = 
	}
}
